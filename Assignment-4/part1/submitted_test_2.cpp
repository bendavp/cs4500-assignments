//lang CwC
// testing column

#include <gtest/gtest.h>
#include "dataframe.h"

#define CS4500_ASSERT_TRUE(a) \
    ASSERT_EQ((a), true);
#define CS4500_ASSERT_FALSE(a) \
    ASSERT_EQ((a), false);
#define CS4500_ASSERT_EXIT_ZERO(a) \
    ASSERT_EXIT(a(), ::testing::ExitedWithCode(0), ".*");

/**
 * @brief Checking to see if we can accurately get the elements from an IntColumn
 * 
 */
void testIntColumnGet1()
{
    IntColumn *i = new IntColumn(17, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17);
    for (int j = 0; j < 17; j++)
    {
        CS4500_ASSERT_TRUE(i->get(j) == j);
    }
    delete i;
    exit(0);
}

TEST(W1, int1)
{
    CS4500_ASSERT_EXIT_ZERO(testIntColumnGet1);
}

/**
 * @brief Testing set function via setting the values then getting them to check if we set the value correctly as each location.
 * 
 */
void testIntColumnSet2()
{
    IntColumn *i = new IntColumn(17, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17);
    // set 1 value in i to something else and check if that one value changed correctly
    i->set(8, 8888);
    CS4500_ASSERT_TRUE(i->get(8) == 8888);
    // set all values in i to something else and check
    for (int j = 0; j < 17; j++)
    {
        i->set(j, j * 3);
    }
    for (size_t j = 0; j < count; j++)
    {
        CS4500_ASSERT_TRUE(i->get(j) == j * 3);
    }
    delete i;
    exit(0);
}

TEST(W1, int2)
{
    CS4500_ASSERT_EXIT_ZERO(testIntColumnSet2);
}

/**
 * @brief Testing that push_back() function works as expected for empty and nonempty Columns. Check after each push back that the added element is
 * where and what is expected.
 * 
 */
void testIntColumnPushBack3()
{
    // checking empty column
    IntColumn *i_ = new IntColumn();
    // adding to empty column and checking to see if added element is where and what we expect
    for (size_t j = 0; j < 10000000; j++)
    {
        i_->push_back(j);
        CS4500_ASSERT_TRUE(i_->get(j) == j);
    }
    delete i_;
    // checking nonempty array
    IntColumn *i = new IntColumn(17, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17);
    for (size_t j = 0; j < 10000000; j++)
    {
        i->push_back(j * 3 + 3);
        CS4500_ASSERT_TRUE(i->get(j) == (j * 3 + 20));
    }
    delete i;
    exit(0);
}

TEST(W1, int3)
{
    CS4500_ASSERT_EXIT_ZERO(testIntColumnPushBack3);
}

/**
 * @brief Testing that size works as expected for empty and nonempty Columns including after we add new elements via push_back() function
 * 
 */
void testIntColumnSize4()
{
    // checking empty column
    IntColumn *i_ = new IntColumn();
    CS4500_ASSERT_TRUE(i->size() == 0);
    // adding to empty column and checking to see if size is as expected after each add and at the end
    for (size_t j = 0; j < 10000000; j++)
    {
        i_->push_back(j);
        CS4500_ASSERT_TRUE(i_->size() == j);
    }
    CS4500_ASSERT_TRUE(i_->size() == 10000000);
    delete i_;
    // checking nonempty column
    IntColumn *i = new IntColumn(17, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17);
    CS4500_ASSERT_TRUE(i->size() == 17);
    // adding to nonempty column and checking to see if size is as expected after each add and at the end
    for (size_t j = 0; j < 10000000; j++)
    {
        i_->push_back(j);
        CS4500_ASSERT_TRUE(i->size() == (j + 17));
    }
    CS4500_ASSERT_TRUE(i->size() == 10000017);
    delete i;
    exit(0);
}

TEST(W1, int4)
{
    CS4500_ASSERT_EXIT_ZERO(testIntColumnSize4);
}

/**
 * @brief Testing if empty/nonempty IntColumn returns the expected pointer
 * 
 */
void testIntColumnAsType5()
{
    // checking empty column
    IntColumn *i_ = new IntColumn();
    CS4500_ASSERT_TRUE(i_ == i_->as_int());
    CS4500_ASSERT_TRUE(i_->as_bool() == nullptr);
    CS4500_ASSERT_TRUE(i_->as_float() == nullptr);
    CS4500_ASSERT_TRUE(i_->as_string() == nullptr);
    // checking nonempty column
    IntColumn *i = new IntColumn(17, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17);
    CS4500_ASSERT_TRUE(i == i->as_int());
    CS4500_ASSERT_TRUE(i->as_bool() == nullptr);
    CS4500_ASSERT_TRUE(i->as_float() == nullptr);
    CS4500_ASSERT_TRUE(i->as_string() == nullptr);
    delete i;
    delete i_;
    exit(0);
}

TEST(W1, int5)
{
    CS4500_ASSERT_EXIT_ZERO(testIntColumnAsType5);
}

/**
 * @brief Testing if empty/nonempty IntColumn returns the expected char representing its type
 * 
 */
void testIntColumnGetType6()
{
    // checking empty column
    Column *i_ = new IntColumn();
    CS4500_ASSERT_TRUE(i_->get_type() == 'I');
    // checking nonempty column
    IntColumn *i = new IntColumn(17, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17);
    CS4500_ASSERT_TRUE(i->get_type() == 'I');
    delete i;
    delete i_;
    exit(0);
}

TEST(W1, int6)
{
    CS4500_ASSERT_EXIT_ZERO(testIntColumnGetType6);
}

/**
 * @brief Tests the clone method for an IntColumn. Because Columns have pointer equality, to see if clone is correct, we test to see if each element is the same. 
 * Additionally, because a clone should not directly point at something the Column owns, the original Column is deleted and then the values in the clone are checked
 * again.
 * 
 */
void testIntColumnClone7()
{
    // create and populate IntCol
    IntColumn *i = new IntColumn();
    for (size_t j = 0; j < 10000; j++)
    {
        i->push_back(j);
    }
    IntColumn *i_ = i->clone();
    CS4500_ASSERT_TRUE(i->size() == i_->size());
    // check manually if each element is the same
    for (size_t j = 0; j < i->size(); j++)
    {
        CS4500_ASSERT_TRUE(i->get(j) == i_->get(j));
    }
    delete i;
    // check that the clone retains information/elements after original is deleted
    for (size_t j = 0; j < 10000; j++)
    {
        CS4500_ASSERT_TRUE(i_->get(j) == j);
    }
    delete i_;
    exit(0)
}

TEST(W1, int7)
{
    CS4500_ASSERT_EXIT_ZERO(testIntColumnClone7);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}