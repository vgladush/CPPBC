// Copyright 2013, GlobalLogic Inc.
// All rights reserved.
//

#include "spell_checker.h"
#include "gtest/gtest.h"
#include <fstream>

TEST(SpellChecker, when_empty_size_return_0)
{
    SpellChecker obj(ContainerType::Vector);
    EXPECT_EQ(obj.size(), 0);
}

void test_load(ContainerType type)
{
    SpellChecker obj(type);
    obj.load("../dictionaries/large");
    EXPECT_EQ(obj.size(), 143091);
}

TEST(SpellChecker, load_Vector)
{
    test_load(ContainerType::Vector);
}

TEST(SpellChecker, load_Set)
{
    test_load(ContainerType::Set);
}

TEST(SpellChecker, load_Unordered_Set)
{
    test_load(ContainerType::Unordered_Set);
}

TEST(SpellChecker, invalid_dict_throws_exc)
{
    SpellChecker obj(ContainerType::Vector);

    EXPECT_THROW(obj.load("invalid.txt"), SpellChecker_InvalidDictFile);
}

const char *list_valid[] = {
    "denormalise",
    "revocation",
    "rewards",
    "roadworks",
    "absolutely",
    "obsession",
    "obsolete",
    "logic",
    "won't"};

const char *list_misspelled[] = {
    "GlobalLogic",
    "udemy",
    "kazka",
    "showtime",
};

void test_valid_and_misspelled(ContainerType type)
{
    SpellChecker obj(type);
    obj.load("../dictionaries/large");
    EXPECT_EQ(obj.size(), 143091);

    for (auto i : list_valid)
    {
        EXPECT_EQ(obj.check(i), true);
    }
    for (auto i : list_misspelled)
    {
        EXPECT_EQ(obj.check(i), false);
    }
}

const char *list2add[] = {
    "google",
    "variadic",
};

void test_add_and_check(ContainerType type)
{
    SpellChecker obj(type);
    EXPECT_EQ(obj.size(), 0);
    obj.load("../dictionaries/large");
    size_t dictSize = obj.size();
    EXPECT_EQ(dictSize, 143091);

    for (auto i : list2add)
    {
        EXPECT_EQ(SpellChecker::is_valid(i), true);
        EXPECT_EQ(obj.check(i), false);
        obj.add(i);
        EXPECT_EQ(obj.size(), ++dictSize);
        EXPECT_EQ(obj.check(i), true);
        obj.add(i);                      // duplicates not stored in dict, second add ignored
        EXPECT_EQ(obj.size(), dictSize); // size not changed
    }
    // re-check valid and misspelled that nothing broken after add
    for (auto i : list_valid)
    {
        EXPECT_EQ(obj.check(i), true);
    }
    for (auto i : list_misspelled)
    {
        EXPECT_EQ(obj.check(i), false);
    }
}

TEST(SpellChecker, test_add_and_check_Vector)
{
    test_add_and_check(ContainerType::Vector);
}
TEST(SpellChecker, test_add_and_check_Set)
{
    test_add_and_check(ContainerType::Set);
}
TEST(SpellChecker, test_add_and_check_UnorderedSet)
{
    test_add_and_check(ContainerType::Unordered_Set);
}

TEST(SpellChecker, when_valid_word_is_valid_returns_true)
{
    for (auto i : list_valid)
    {
        EXPECT_EQ(SpellChecker::is_valid(i), true);
    }
    for (auto i : list_misspelled)
    {
        EXPECT_EQ(SpellChecker::is_valid(i), true);
    }
}

// performance check
struct TextData
{
    const char *text;
    unsigned missed;
    unsigned valid;
    unsigned total;
};

TextData data[] = {
    {"../texts/alice.txt", 73, 23203, 29459},
    {"../texts/dracula.txt", 1540, 138207, 163798},
    {"../texts/sherlock.txt", 539, 88248, 106840}};

void test_performance(ContainerType type)
{
    SpellChecker obj(type);
    obj.load("../dictionaries/large");
    ASSERT_EQ(obj.size(), 143091);

    // allow only alphabetical characters and apostrophes not at beginning
    // ignore words with numbers (like MS Word can)
    // ignore alphabetical strings too long to be words
    for (auto test : data)
    {
        std::ifstream infile;
        infile.open(test.text);
        std::string line;
        unsigned misspelled = 0;
        unsigned words_in_text = 0;
        unsigned total = 0;
        ASSERT_EQ(infile.good(), true);
        while (infile >> line)
        {
            total++;
            if (!SpellChecker::is_valid(line))
            {
                continue;
            }
            words_in_text++;
            if (!obj.check(line))
            {
                misspelled++;
            }
        }
        EXPECT_EQ(misspelled, test.missed);
        EXPECT_EQ(words_in_text, test.valid);
        EXPECT_EQ(total, test.total);
    }
}

TEST(SpellChecker, performance_check_vector)
{
    test_performance(ContainerType::Vector);
}
TEST(SpellChecker, performance_check_set)
{
    test_performance(ContainerType::Set);
}
TEST(SpellChecker, performance_check_unordered_set)
{
    test_performance(ContainerType::Unordered_Set);
}

struct TestWords
{
    const char *pattern;
    bool expected;
};

// maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
const size_t Max_Length = 45;

TestWords tw[] = {
    {"word", true},
    {"IBSN9998", false}, // has non alpha characters
    {"$100", false},     // has special symbols
    // valid the longest word
    {"Pneumonoultramicroscopicsilicovolcanoconiosis", true},
    // exceeds max length
    {"Pneumonoultramicroscopicsilicovolcanoconiosisa", false},
    {"Beau--ootiful", false}, // has '-'
    {"e--e--evening", false},
    {"http://www.gutenberg.org/1/11/", false}, // has non alpha
    {"11.zip", false},                         // has digits
    {"1.E.3.", false},
    {"Gutenberg-tm", false},
    {"'cause", false}, // apostrophe at first position is not allowed
    {"won't", true},   // apostrophe in other than first position is fine
};

TEST(SpellChecker, is_valid)
{
    for (auto i : tw)
    {
        EXPECT_EQ(SpellChecker::is_valid(i.pattern), i.expected);
    }
}

int main(int argc, char **argv)
{

    printf("Running main() from Coder_gTest.cpp\n");

    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
