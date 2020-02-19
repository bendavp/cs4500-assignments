// langCwC

#include <gtest/gtest.h>
#include "dataframe.h"

#define CS4500_ASSERT_TRUE(a) \
    ASSERT_EQ((a), true);
#define CS4500_ASSERT_FALSE(a) \
    ASSERT_EQ((a), false);
#define CS4500_ASSERT_EXIT_ZERO(a) \
    ASSERT_EXIT(a(), ::testing::ExitedWithCode(0), ".*");

/**
 * @brief Testing that push_back() function works as expected for empty and nonempty Columns. Check after each push back that the added element is
 * where and what is expected.
 * 
 */
void testStringColumnPushBack()
{
    String *all = new String("blahhityblahhityblah");
    size_t size_ = all->size();
    // checking empty column
    StringColumn *i_ = new StringColumn();
    char *c;
    String *expected;
    // adding to empty column and checking to see if added element is where and what we expect
    for (size_t j = 0; j < 10000000; j++)
    {
        c = new char(all->at(j % size_));
        expected = new String(c);
        i_->push_back(expected->clone());
        CS4500_ASSERT_TRUE(i_->get(j)->equals(expected));
        delete c;
        delete expected;
    }
    delete i_;
    // checking nonempty array
    String *s1 = new String("h");
    String *s2 = new String("e");
    String *s3 = new String("l");
    String *s4 = new String("l");
    String *s5 = new String("o");
    String *s6 = new String("w");
    String *s7 = new String("o");
    String *s8 = new String("r");
    String *s9 = new String("l");
    String *s10 = new String("d");
    String *s11 = new String("r");
    String *s12 = new String("e");
    String *s13 = new String("j");
    String *s14 = new String("e");
    String *s15 = new String("c");
    String *s16 = new String("t");
    String *s17 = new String("s");
    String *all2 = new String("helloworldrejects");
    StringColumn *i = new StringColumn(17, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15, s16, s17);
    for (size_t j = 0; j < 10000; j++)
    {
        char *c = new char(all->at(j % size_));
        String *expected = new String(c);
        i->push_back(expected->clone());
        CS4500_ASSERT_TRUE(i->size() == j + 18);
        CS4500_ASSERT_TRUE(i->get(j + 17)->equals(expected));
    }
    // check that the beginning is unchanged by pushback
    for (size_t j = 0; j < 17; j++)
    {
        c = new char(all2->at(j));
        expected = new String(c);
        CS4500_ASSERT_TRUE(i->get(j)->equals(expected));
        delete c;
        delete expected;
    }
    delete i;
    delete all;
    delete all2;
    exit(0);
}

TEST(test5, StringColPushback) { CS4500_ASSERT_EXIT_ZERO(testStringColumnPushBack); }

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}