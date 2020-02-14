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
 * @brief Testing adding a column and then testing the dataframe's schema has changed as expected. 
 * Due to how this test is structured, we also can also use this test to test nrows() and ncols() functions. 
 * 
 */
void testDataframeAddingColumn()
{
    // empty schema, no cols/rows
    Schema *s = new Schema();
    DataFrame *df = new DataFrame(*s);
    CS4500_ASSERT_TRUE(df->nrows() == 0);
    CS4500_ASSERT_TRUE(df->ncols() == 0);
    Column *c = new IntColumn(8, 1, 2, 3, 4, 5, 6, 7, 8);
    df->add_column(c, new String("name"));
    CS4500_ASSERT_TRUE(df->get_schema().width() == 1);
    CS4500_ASSERT_TRUE(df->get_schema().length() == 8);
    CS4500_ASSERT_TRUE(df->get_schema().col_name(0)->equals(new String("name")));
    CS4500_ASSERT_TRUE(df->get_schema().col_type(0) == 'I');
    CS4500_ASSERT_TRUE(df->nrows() == 8);
    CS4500_ASSERT_TRUE(df->ncols() == 1);
    // now adding another column to nonempty dfs
    Column *cc = new BoolColumn(8, true, false, true, false, true, false, true, false);
    df->add_column(cc, new String("2nd col"));
    CS4500_ASSERT_TRUE(df->get_schema().width() == 2);
    CS4500_ASSERT_TRUE(df->get_schema().length() == 8);
    CS4500_ASSERT_TRUE(df->get_schema().col_name(1)->equals(new String("2nd col")));
    CS4500_ASSERT_TRUE(df->get_schema().col_type(1) == 'B');
    CS4500_ASSERT_TRUE(df->nrows() == 8);
    CS4500_ASSERT_TRUE(df->ncols() == 2);
    exit(0);
}

TEST(test4, dfAddColumn) { CS4500_ASSERT_EXIT_ZERO(testDataframeAddingColumn); }

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}