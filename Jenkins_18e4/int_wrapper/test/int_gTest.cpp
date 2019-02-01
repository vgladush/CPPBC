// Copyright 2018, GlobalLogic Inc.
// All rights reserved.
//

#include "int_wrapper.h"

#include "gtest/gtest.h"

#include <exception>

class TInt_Overflow
{
};
class TInt_DivisionByZero
{
};

std::ostream &operator<<(std::ostream &os, const TInt &v)
{
    return os << v.getV();
}

TEST(TInt_Wrapper, init)
{
    TInt v;

    ASSERT_EQ(0, v);
}

TEST(TInt_Wrapper, set)
{
    TInt v2("2147483647");

    ASSERT_EQ(2147483647, v2);
}

TEST(TInt_Wrapper, up_limit)
{
    EXPECT_THROW(TInt("2147483649"), TInt_Overflow);
}

TEST(TInt_Wrapper, low_limit)
{
    EXPECT_THROW(TInt("-2147483649"), TInt_Overflow);
}

TEST(TInt_Wrapper, logic_error)
{
    TInt lhs = 10;
    TInt rhs = 0;

    EXPECT_THROW(lhs / rhs, TInt_DivisionByZero);
}

TEST(TInt_Wrapper, invalid_input)
{
    EXPECT_THROW(TInt("123tr83"), std::exception);
}

TEST(TInt_Wrapper, negative_overflow)
{
    TInt v = -2147483648;

    EXPECT_THROW(-v, TInt_Overflow);
}

TEST(TInt_Wrapper, add_overflow)
{
    TInt v = 2147483647;

    EXPECT_THROW(v + 2, TInt_Overflow);
}

TEST(TInt_Wrapper, multiply_overflow)
{
    TInt v = 1147483649;

    EXPECT_THROW(v * 2, TInt_Overflow);
}

TEST(TInt_Wrapper, substract_overflow)
{
    TInt v = -2147483647;

    EXPECT_THROW(v - 2, TInt_Overflow);
}

TEST(TInt_Wrapper, basic_op)
{
    TInt v1 = 123;
    TInt v2 = 456;
    TInt v3 = v2;

    EXPECT_EQ(v1 + v2, 579);
    EXPECT_EQ(v2 - v1, 333);

    EXPECT_EQ(v1 * v2, 56088);
    EXPECT_EQ(v2 / v1, 3);
    EXPECT_EQ(v2 % v1, 87);

    EXPECT_EQ(v2 > v1, true);
    EXPECT_EQ(v1 > v2, false);
    EXPECT_EQ(v1 < v2, true);

    EXPECT_EQ(v1 != v2, true);
    EXPECT_EQ(v3 == v2, true);
}

int main(int argc, char **argv)
{
    printf("Running main() from int_gTest.cpp\n");

    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
