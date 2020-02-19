//lang Cwc

#include <gtest/gtest.h>
#include "dataframe.h"

#define CS4500_ASSERT_TRUE(a) \
    ASSERT_EQ((a), true);
#define CS4500_ASSERT_FALSE(a) \
    ASSERT_EQ((a), false);
#define CS4500_ASSERT_EXIT_ZERO(a) \
    ASSERT_EXIT(a(), ::testing::ExitedWithCode(0), ".*");

/**
 * @brief Tests the clone method for an StringColumn. Because Columns have pointer equality, to see if clone is correct, we test to see if each element is the same. 
 * Additionally, because a clone should not directly pointer at something the Column owns, the original Column is deleted and then the values in the clone are checked
 * again.
 * 
 */
void testStringColumnClone()
{
    // create and populate StringCol
    String *all = new String("blahhityblahhityblah");
    size_t size_ = all->size();
    StringColumn *i = new StringColumn();
    char *c;
    String *expected;
    for (size_t j = 0; j < 10000; j++)
    {
        c = new char(all->at(j % size_));
        expected = new String(c);
        i->push_back(expected->clone());
    }
    StringColumn *i_ = i->clone();
    CS4500_ASSERT_TRUE(i->size() == i_->size());
    // check manually if each element is the same
    for (size_t j = 0; j < i->size(); j++)
    {
        CS4500_ASSERT_TRUE(i->get(j)->equals(i_->get(j)));
    }
    delete i;
    // check that the clone retains information/elements after original is deleted
    for (size_t j = 0; j < 10000; j++)
    {
        c = new char(all->at(j % size_));
        expected = new String(c);
        CS4500_ASSERT_TRUE(i_->get(j)->equals(expected));
    }
    exit(0);
}

TEST(test1, StringColumnClone)
{
    CS4500_ASSERT_EXIT_ZERO(testStringColumnClone);
}

/**
 * @brief Runs all Google Tests in this file
 */
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
