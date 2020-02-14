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
 * @brief Testing adding row by seeing if the dataframe's schema and other values have changed as expected. 
 * Also tests if the strings are external. 
 * 
 */
void testDataframeAddingRows()
{
    // adding row to a nonempty schema
    Schema *s = new Schema("IISFB");            // nonempty schema
    DataFrame *df = new DataFrame(*s);          // make df based on nonempty schema
    Row *r = new Row(df->get_schema());         // making a row based off the schema
    String *toSet = new String("string hello"); // this string
    // filling df with rows
    for (size_t i = 0; i < 1000; i++)
    {
        r->set(0, (int)i);
        r->set(1, (int)i + 1);
        r->set(2, toSet); // string should be external
        r->set(3, (float)(i + 0.22));
        r->set(4, i % 2 == 1);
        df->add_row(*r);
    }
    CS4500_ASSERT_TRUE(df->get_schema().length() == 1000);
    CS4500_ASSERT_TRUE(df->get_schema().width() == 5);
    CS4500_ASSERT_TRUE(df->nrows() == 1000);
    CS4500_ASSERT_TRUE(df->ncols() == 5);

    // check to see if the columns values are as expected
    delete toSet; // should be able to delete this string without affecting whats in the dataframe
    String *expected = new String("string hello");
    for (int i = 0; i < 1000; i++)
    {
        CS4500_ASSERT_TRUE(df->get_int(0, i) == i);
        CS4500_ASSERT_TRUE(df->get_int(1, i) == (i + 1));
        CS4500_ASSERT_TRUE(df->get_string(2, i)->equals(expected));
        CS4500_ASSERT_TRUE(df->get_float(2, i) - ((float)i + 0.22) < 0.001);
        CS4500_ASSERT_TRUE(df->get_float(2, i) - ((float)i + 0.22) > -0.001);
        CS4500_ASSERT_TRUE(df->get_bool(1, i) == (i % 2 == 1));
    }
    exit(0);
}

TEST(test3, dfAddRows) { CS4500_ASSERT_EXIT_ZERO(testDataframeAddingRows); }

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}