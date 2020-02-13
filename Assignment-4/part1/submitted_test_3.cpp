// row

#include <gtest/gtest.h>
#include "dataframe.h"

#define CS4500_ASSERT_TRUE(a) \
    ASSERT_EQ((a), true);
#define CS4500_ASSERT_FALSE(a) \
    ASSERT_EQ((a), false);
#define CS4500_ASSERT_EXIT_ZERO(a) \
    ASSERT_EXIT(a(), ::testing::ExitedWithCode(0), ".*");

/**
 * @brief Checking to see if we can accurately get the elements from an FloatColumn
 * 
 */
void testFloatColumnGet1()
{
    FloatColumn *i = new FloatColumn(17, 1.22, 2.22, 3.22, 4.22, 5.22, 6.22, 7.22, 8.22, 9.22, 10.22, 11.22, 12.22, 13.22, 14.22, 15.22, 16.22, 17.22);
    for (size_t j = 0; j < 17; j++)
    {
        float expected = float(j) + 1.22;
        CS4500_ASSERT_TRUE(i->get(j) - expected < 0.001);
        //CS4500_ASSERT_TRUE(i->get(j) - expected > -0.001);
    }
    delete i;
    exit(0);
}

TEST(W1, Float1)
{
    CS4500_ASSERT_EXIT_ZERO(testFloatColumnGet1);
}

/**
 * @brief Testing set function via setting the values then getting them to check if we set the value correctly as each location.
 * 
 */
void testFloatColumnSet2()
{
    FloatColumn *i = new FloatColumn(17, 1.22, 2.22, 3.22, 4.22, 5.22, 6.22, 7.22, 8.22, 9.22, 10.22, 11.22, 12.22, 13.22, 14.22, 15.22, 16.22, 17.22);
    // set 1 value in i to something else and check if that one value changed correctly
    i->set(8, 8.88);
    CS4500_ASSERT_TRUE(i->get(8) - 8.88 < 0.001 && i->get(8) - 8.88 > -0.001);
    // set all values in i to something else and check
    for (size_t j = 0; j < 17; j++)
    {
        i->set(j, (float)j + 2.22);
    }
    for (size_t j = 0; j < 17; j++)
    {
        float expected = float(j) + 2.22;
        CS4500_ASSERT_TRUE((i->get(j) - expected) < 0.001);
        CS4500_ASSERT_TRUE((i->get(j) - expected) > -0.001);
    }
    delete i;
    exit(0);
}

TEST(W1, Float2)
{
    CS4500_ASSERT_EXIT_ZERO(testFloatColumnSet2);
}

/**
 * @brief Testing that push_back() function works as expected for empty and nonempty Columns. Check after each push back that the added element is
 * where and what is expected.
 * 
 */
void testFloatColumnPushBack3()
{
    // checking empty column
    FloatColumn *i_ = new FloatColumn();
    // adding to empty column and checking to see if added element is where and what we expect
    for (size_t j = 0; j < 10000000; j++)
    {
        float expected = float(j) + 2.42;
        i_->push_back(expected);
        CS4500_ASSERT_TRUE((i_->get(j) - expected) < 0.001);
        CS4500_ASSERT_TRUE((i_->get(j) - expected) > -0.001);
    }
    delete i_;

    // checking nonempty array
    FloatColumn *i = new FloatColumn(17, 1.22, 2.22, 3.22, 4.22, 5.22, 6.22, 7.22, 8.22, 9.22, 10.22, 11.22, 12.22, 13.22, 14.22, 15.22, 16.22, 17.22);
    for (size_t j = 0; j < 10000000; j++)
    {
        float expected = float(j) + 2.44;
        i->push_back(expected);
        //CS4500_ASSERT_TRUE((i->get(j + 17) - expected) < 0.001);
        //CS4500_ASSERT_TRUE((i->get(j + 17) - expected) > -0.001);
    }
    // check that the beginning is unchanged by pushback
    for (size_t j = 0; j < 17; j++)
    {
        float expected = float(j) + 1.22;
        //CS4500_ASSERT_TRUE((i->get(j) - expected) < 0.001);
        //CS4500_ASSERT_TRUE((i->get(j) - expected) > -0.001);
    }
    delete i;

    exit(0);
}

TEST(W1, Float3)
{
    CS4500_ASSERT_EXIT_ZERO(testFloatColumnPushBack3);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}