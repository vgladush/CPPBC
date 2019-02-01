// Copyright 2018, GlobalLogic Inc.
// All rights reserved.
//

#include "numeric_wrapper.hpp"

#include "gtest/gtest.h"

#include <sstream>
#include <stdexcept>
#include <string>

// Follow exception types are handled:
// SafeNumeric_Overflow
// SafeNumeric_DivisionByZero
// SafeNumeric_InvalidInput
// SafeNumeric_InvalidOperation

template <class T>
void test_set()
{
    std::string s;
    {
        std::ostringstream str;
        str << std::fixed << std::numeric_limits<T>::max();
        s = str.str();
    }
    SafeNumeric<T> v2(s.c_str());

    EXPECT_EQ(SafeNumeric<T>(std::numeric_limits<T>::max()), v2);

    EXPECT_EQ(SafeNumeric<T>("").get(), 0);
    EXPECT_EQ(SafeNumeric<T>(nullptr).get(), 0);
    EXPECT_EQ(SafeNumeric<T>().get(), 0);
}

const double PRECISION = 0.00001;

template <>
void test_set<double>()
{
    std::ostringstream str;
    double max_value = std::numeric_limits<double>::max();
    str << std::fixed << max_value;
    SafeNumeric<double> v2(str.str().c_str());
    const double Zero = 0.0;
    EXPECT_NEAR(SafeNumeric<double>(max_value).get(),
                v2.get(), PRECISION);
    EXPECT_NEAR(SafeNumeric<double>("").get(), Zero, PRECISION);
    EXPECT_NEAR(SafeNumeric<double>(nullptr).get(), Zero, PRECISION);
    EXPECT_NEAR(SafeNumeric<double>().get(), Zero, PRECISION);
}

TEST(Numeric_Wrapper, set)
{
    test_set<int>();
    test_set<unsigned>();
    test_set<short>();
    test_set<double>();
}

template <class T>
std::string test_up_limit()
{
    std::ostringstream str;
    str << std::numeric_limits<T>::max();
    str << 9; // add one more digit

    return str.str();
}

TEST(Numeric_Wrapper, up_limit)
{
    EXPECT_THROW(SafeNumeric<int>(test_up_limit<int>().c_str()),
                 SafeNumeric_Overflow);

    EXPECT_THROW(SafeNumeric<unsigned>(test_up_limit<unsigned>().c_str()),
                 SafeNumeric_Overflow);
    EXPECT_THROW(SafeNumeric<short>(test_up_limit<short>().c_str()),
                 SafeNumeric_Overflow);

    EXPECT_THROW(SafeNumeric<double>(test_up_limit<double>().c_str()),
                 SafeNumeric_Overflow);
}

template <class T>
std::string test_low_limit()
{
    static_assert(std::is_signed<T>(),
                  "invalid invoke of generic template test_low_limit() for unsigned");

    std::ostringstream str;
    str << std::fixed << std::numeric_limits<T>::lowest(); // C++11
    std::string v = str.str();
    // add one leading digit to create overflow
    size_t sign_pos = v.find('-');
    std::string::const_iterator pos = (sign_pos != std::string::npos) ? v.begin() + sign_pos + 1 : v.begin();
    v.insert(pos, '9');
    return v;
}

template <>
std::string test_low_limit<unsigned>()
{
    return std::string("-1");
}

TEST(Numeric_Wrapper, low_limit)
{
    EXPECT_THROW(SafeNumeric<int>(test_low_limit<int>().c_str()),
                 SafeNumeric_Overflow);
    EXPECT_THROW(SafeNumeric<unsigned>("-1"),
                 SafeNumeric_Overflow);
    EXPECT_THROW(SafeNumeric<short>(test_low_limit<short>().c_str()),
                 SafeNumeric_Overflow);
    EXPECT_THROW(SafeNumeric<double>(test_low_limit<double>().c_str()),
                 SafeNumeric_Overflow);
}

template <class T>
SafeNumeric<T> invoke_div()
{
    SafeNumeric<T> lhs = 10;
    SafeNumeric<T> rhs = 0;
    return lhs / rhs;
}

TEST(Numeric_Wrapper, logic_error)
{
    EXPECT_THROW(invoke_div<int>(), SafeNumeric_DivisionByZero);
    EXPECT_THROW(invoke_div<unsigned>(), SafeNumeric_DivisionByZero);
    EXPECT_THROW(invoke_div<short>(), SafeNumeric_DivisionByZero);
    EXPECT_THROW(invoke_div<double>(), SafeNumeric_DivisionByZero);
}

template <class T>
SafeNumeric<T> get_invalid_input()
{
    return SafeNumeric<T>("13tr8");
}

TEST(Numeric_Wrapper, invalid_input)
{
    EXPECT_THROW(get_invalid_input<int>(), SafeNumeric_InvalidInput);
    EXPECT_THROW(get_invalid_input<unsigned>(), SafeNumeric_InvalidInput);
    EXPECT_THROW(get_invalid_input<short>(), SafeNumeric_InvalidInput);
    EXPECT_THROW(get_invalid_input<double>(), SafeNumeric_InvalidInput);
}

template <class T>
void test_add_overflow()
{
    SafeNumeric<T> v = std::numeric_limits<T>::max();
    EXPECT_THROW((v + SafeNumeric<T>(1)), SafeNumeric_Overflow);
}

TEST(Numeric_Wrapper, add_overflow)
{
    test_add_overflow<int>();
    test_add_overflow<unsigned>();
    test_add_overflow<short>();
    test_add_overflow<double>();
}

template <class T>
void test_multiply_overflow()
{
    SafeNumeric<T> v = (std::numeric_limits<T>::max() / 2);
    EXPECT_THROW(v * SafeNumeric<T>(3), SafeNumeric_Overflow);
}

TEST(Numeric_Wrapper, multiply_overflow)
{
    test_multiply_overflow<int>();
    test_multiply_overflow<unsigned>();
    test_multiply_overflow<short>();
    test_multiply_overflow<double>();
}

template <typename T>
T get_addend()
{
    T addend = 1;
    T lowest = std::numeric_limits<T>::lowest();
    T rhs = lowest;
    while (lowest >= (rhs + addend))
    {
        addend *= 2;
    }
    return addend;
}

template <class T>
void test_subtract_overflow()
{
    SafeNumeric<T> v = std::numeric_limits<T>::lowest();
    ASSERT_EQ(v.get(), std::numeric_limits<T>::lowest());
    EXPECT_THROW((v - SafeNumeric<T>(get_addend<T>())), SafeNumeric_Overflow);
}

TEST(Numeric_Wrapper, subtract_overflow)
{
    test_subtract_overflow<int>();
    test_subtract_overflow<unsigned>();
    test_subtract_overflow<short>();
    test_subtract_overflow<double>();
}

template <class T>
void test_basic_op_common(SafeNumeric<T> v1,
                          SafeNumeric<T> v2,
                          SafeNumeric<T> v3)
{
    EXPECT_EQ(v1 + v2, SafeNumeric<T>(v1.get() + v2.get()));
    EXPECT_EQ(v2 - v1, SafeNumeric<T>(v2.get() - v1.get()));

    EXPECT_EQ((v1 * v2), SafeNumeric<T>(v1.get() * v2.get()));
    EXPECT_EQ((v2 / v1), SafeNumeric<T>(v2.get() / v1.get()));

    EXPECT_EQ(v2 > v1, true);
    EXPECT_EQ(v1 > v2, false);
    EXPECT_EQ(v1 < v2, true);
    EXPECT_EQ(v1 != v2, true);
    EXPECT_EQ(v3 == v2, true);
}

template <class T>
void test_basic_op()
{
    SafeNumeric<T> v1 = 123;
    SafeNumeric<T> v2 = 247;
    SafeNumeric<T> v3 = v2;

    test_basic_op_common<T>(v1, v2, v3);

    EXPECT_EQ((v2 % v1), SafeNumeric<T>(247 % 123));
}

template <>
void test_basic_op<double>()
{
    SafeNumeric<double> v1 = 123;
    SafeNumeric<double> v2 = 247;
    SafeNumeric<double> v3 = v2;

    test_basic_op_common<double>(v1, v2, v3);
}

TEST(Numeric_Wrapper, basic_op)
{
    test_basic_op<int>();
    test_basic_op<unsigned>();
    test_basic_op<short>();
    test_basic_op<double>();

    // special case for SafeInt<double> for binary %
    SafeNumeric<double> v1 = 123;
    SafeNumeric<double> v2 = 247;
    EXPECT_THROW((v2 % v1), SafeNumeric_InvalidOperation);

    SafeNumeric<float> v1_fl = 123;
    SafeNumeric<float> v2_fl = 247;
    EXPECT_THROW((v2_fl % v1_fl), SafeNumeric_InvalidOperation);

    SafeNumeric<int> v1_i = 123;
    EXPECT_EQ((-v1_i).get(), -123);

    SafeNumeric<unsigned> v1_u = 123;
    EXPECT_THROW((-v1_u), SafeNumeric_InvalidOperation);
}

int main(int argc, char **argv)
{
    printf("Running main() from numeric_wrapper_gTest.cpp\n");

    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
