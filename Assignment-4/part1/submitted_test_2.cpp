//lang CwC

#include <gtest/gtest.h>
#include "dataframe.h"

#define CS4500_ASSERT_TRUE(a) \
    ASSERT_EQ((a), true);
#define CS4500_ASSERT_FALSE(a) \
    ASSERT_EQ((a), false);
#define CS4500_ASSERT_EXIT_ZERO(a) \
    ASSERT_EXIT(a(), ::testing::ExitedWithCode(0), ".*");

/**
 * @brief Setting the different cells and then checking if we can get the expected value.
 * We do this for each type of cell (int, bool, string, float)
 * 
 */
void testDataframeSetFunctions()
{
    // empty schema, no cols/rows
    Schema *s = new Schema();
    DataFrame *df = new DataFrame(*s);
    Column *c = new IntColumn(8, 1, 2, 3, 4, 5, 6, 7, 8);
    df->add_column(c, new String("name"));
    // now adding another column to nonempty dfs
    Column *c2 = new BoolColumn(8, true, false, true, false, true, false, true, false);
    df->add_column(c2, new String("2nd col"));
    Column *c3 = new FloatColumn(8, 1.22, 2.22, 3.22, 4.22, 5.22, 6.22, 7.22, 8.22);
    df->add_column(c3, new String("3rd"));
    Column *c4 = new StringColumn(8, new String("h"), new String("e"), new String("l"), new String("l"), new String("o"), new String("w"), new String("o"), new String("r"));
    df->add_column(c4, new String("4th"));
    CS4500_ASSERT_TRUE(df->get_schema().coltypes_->equals((new String("IBFS"))));
    char *ch;
    String *all = new String("helloworld");
    String *toAdd;
    for (int i = 0; i < 8; i++)
    {
        df->set(0, i, (int)i * 2);
        df->set(1, i, i % 2 == 1);
        df->set(2, i, (float)(i + 2.22));
        ch = new char(all->at(i + 1));
        toAdd = new String(ch);
        df->set(3, i, toAdd);
    }
    String *expected;
    for (int i = 0; i < 8; i++)
    {
        CS4500_ASSERT_TRUE(df->get_int(0, i) == (i * 2));
        CS4500_ASSERT_TRUE(df->get_bool(1, i) == (i % 2 == 1));
        CS4500_ASSERT_TRUE(df->get_float(2, i) - ((float)i + 2.22) < 0.001);
        CS4500_ASSERT_TRUE(df->get_float(2, i) - ((float)i + 2.22) > -0.001);
        ch = new char(all->at(i + 1));
        expected = new String(ch);
        CS4500_ASSERT_TRUE(df->get_string(3, i)->equals(expected));
    }
    exit(0);
}

TEST(test2, dfSetFunctions) { CS4500_ASSERT_EXIT_ZERO(testDataframeSetFunctions); }

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}