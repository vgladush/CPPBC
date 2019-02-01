// Copyright 2018, GlobalLogic Inc.
// All rights reserved.
//

#include "stl_task.h"
#include "gtest/gtest.h"
#include <array>
#include <utility>
#include <iterator>

TEST(StlTask, remove_value_from_map)
{
    Map m;
    m[3] = 5;
    m[2] = 7;
    m[9] = 11;
    remove_elem_by_value(m, 7);
    EXPECT_EQ(m.size(), 2);
    EXPECT_EQ(m[3], 5);
    EXPECT_EQ(m[9], 11);
}

struct TestData
{
    const char *src;
    const char *expected;
};

// fix duplicate whitespaces, leading and trailing
TEST(StlTask, remove_blanks)
{
    TestData data[] = {{"Hello,    world!     Hey    Jude   ",
                        "Hello, world! Hey Jude"},
                       {"Hello, world! Hey Jude",
                        "Hello, world! Hey Jude"},
                       {" Hello ", "Hello"}};
    for (auto p : data)
    {
        std::string actual = remove_blanks(p.src);
        EXPECT_EQ(actual, p.expected);
    }
}

struct TestDataDuplicate
{
    std::vector<int> source;
    std::vector<int> expected;
};

TestDataDuplicate td[] = {
    {{1, 3, 5, 5, 7, 9, 9, 9, 13, 15}, {1, 3, 5, 7, 9, 13, 15}}, // consequent duplicates sorted
    {{3, 9, 9, 9, 7, 7, 1, 13, 13, 11}, {3, 9, 7, 1, 13, 11}},   // consequent duplicates non sorted - keep order unchanged
    {{7, 5, 11, 13, 1}, {7, 5, 11, 13, 1}},                      // no consequent duplicates: keep order unchanged
    {{7, 5, 5, 11, 13, 1, 11, 7}, {7, 5, 11, 13, 1, 11, 7}}      // no consequent duplicates - no removals
};

TEST(StlTask, remove_duplicates)
{
    for (auto i : td)
    {
        std::vector<int> actual = remove_duplicates(i.source);
        EXPECT_EQ(i.expected.size(), actual.size());
        EXPECT_EQ(i.expected, actual);
    }
}

TestDataDuplicate td2[] = {
    {{1, 3, 5, 5, 7, 9, 9, 9, 13, 15}, {1, 3, 5, 7, 9, 13, 15}}, // consequent duplicates sorted
    {{3, 9, 9, 9, 7, 7, 1, 13, 13, 11}, {3, 9, 7, 1, 13, 11}},   // consequent duplicates non sorted - keep order unchanged
    {{7, 5, 11, 13, 1}, {7, 5, 11, 13, 1}},                      // no consequent duplicates: keep order unchanged
    {{7, 5, 5, 11, 13, 1, 11, 7}, {7, 5, 11, 13, 1}}};

// removes duplicates not necessary consequent and keeps order
TEST(StlTask, remove_duplicates_not_consequent)
{
    for (auto i : td2)
    {
        std::vector<int> actual(i.source);
        remove_duplicates_not_consequent(actual);
        EXPECT_EQ(i.expected.size(), actual.size());
        EXPECT_EQ(i.expected, actual);
    }
}

TEST(StlTask, remove_by_cond)
{
    std::vector<int> source = {1, 2, 3, 4, 1, 5};

    // remove elements in container source that less than n
    remove_if_less(source, 3);
    EXPECT_EQ(source.size(), 3);
    std::vector<int> expected = {3, 4, 5};
    EXPECT_EQ(source, expected);
}

TEST(StlTask, find_keys_by_value)
{
    std::map<std::string, int> wordMap = {
        {"dog", 6},
        {"cat", 5},
        {"parrot", 9},
        {"groundhog", 6}};
    // contains all keys with given value
    std::vector<std::string> res = find_keys_by_value(wordMap, 6);
    EXPECT_EQ(res.size(), 2);
    std::vector<std::string> expected{"dog", "groundhog"};
    EXPECT_EQ(res, expected);
}

TEST(StlTask, map_find_insert)
{
    DnsMap dns{
        {"172.217.16.14", "google.com"},
        {"45.60.31.11", "globallogic.com"},
        {"176.32.98.166", "amazon.com"},
        {"17.142.160.59", "apple.com"},
        {"204.79.197.212", "live.com"},
        {"185.60.216.35", "facebook.com"}};

    DnsMap dns2check = {
        {"216.58.209.78", "maps.google.com"},
        {"17.142.160.59", "apple.com"},
        {"185.60.216.35", "facebook.com"},
        {"172.217.16.5", "gmail.com"},
        {"23.102.255.237", "skype.com"}};

    std::array<std::string, 9> domains = {
        "google.com", "globallogic.com", "amazon.com", "apple.com", "live.com",
        "facebook.com", "gmail.com", "skype.com", "maps.google.com"};

    std::for_each(std::begin(dns2check), std::end(dns2check),
                  [&dns](const auto &e) { insert_if_missed(dns, e); });

    EXPECT_EQ(dns.size(), 9);

    for (const auto &e : dns)
    {
        EXPECT_EQ(true, std::find(std::begin(domains), std::end(domains), e.second) != std::end(domains));
    }
}

int main(int argc, char **argv)
{
    printf("Running main() from StlTask_gTest.cpp\n");

    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
