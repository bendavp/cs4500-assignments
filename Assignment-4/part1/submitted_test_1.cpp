#include <gtest/gtest.h>
#include "dataframe.h"

#define CS4500_ASSERT_TRUE(a) \
    ASSERT_EQ((a), true);
#define CS4500_ASSERT_FALSE(a) \
    ASSERT_EQ((a), false);
#define CS4500_ASSERT_EXIT_ZERO(a) \
    ASSERT_EXIT(a(), ::testing::ExitedWithCode(0), ".*");

/**
 * @brief Checks if get schema returns the expected schema. Schema equality is via pointer equality so checking if 
 * schemas are same via checking size and checking col types.
 * 
 */
void testGetSchema1()
{
    // empty schema
    Schema *s = new Schema();
    DataFrame *df = new DataFrame(*s);
    Schema got = df->get_schema();
    // got should be empty so just check size
    CS4500_ASSERT_TRUE(got.length() == 0);
    CS4500_ASSERT_TRUE(got.width() == 0);

    // schema with just columns
    Schema *s2 = new Schema("IFBIFBFSSS");
    DataFrame *df2 = new DataFrame(*s2);
    Schema got2 = df2->get_schema();
    CS4500_ASSERT_TRUE(got2.length() == 0);
    CS4500_ASSERT_TRUE(got2.width() == s2->width());
    for (size_t i = 0; i < got2.width(); i++)
    {
        CS4500_ASSERT_TRUE(got2.col_type(i) == s2->col_type(2));
    }

    //schema with just rows
    Schema *s3 = new Schema();
    for (int i = 0; i < 17; i++)
    {
        s3->add_row(nullptr);
    }
    DataFrame *df3 = new DataFrame(*s2);
    Schema got3 = df3->get_schema();
    // got should be empty (column-wise) and rows don't have names so just check size
    CS4500_ASSERT_TRUE(got3.length() == s3->length());
    CS4500_ASSERT_TRUE(got3.width() == 0);

    // schema with columns and rows
    Schema *s4 = new Schema("IFBIFBFSSS");
    for (int i = 0; i < 17; i++)
    {
        s4->add_row(nullptr);
    }
    DataFrame *df4 = new DataFrame(*s4);
    Schema got4 = df4->get_schema();
    CS4500_ASSERT_TRUE(got4.length() == s4->length());
    CS4500_ASSERT_TRUE(got4.width() == s4->width());
    for (size_t i = 0; i < got4.width(); i++)
    {
        CS4500_ASSERT_TRUE(got4.col_type(i) == s4->col_type(2));
    }
    delete s;
    delete df;
    delete s2;
    delete df2;
    delete s3;
    delete df3;
    delete s4;
    delete df4;
    exit(0);
}

TEST(df, test1)
{
    CS4500_ASSERT_EXIT_ZERO(testGetSchema1);
}

/**
 * @brief Checks if adding column adds the specified IntColumn the manner expected.
 * 
 */
void testAddIntColumn2()
{
    // empty schema
    Schema *s = new Schema();
    DataFrame *df = new DataFrame(*s);
    Column *c = new IntColumn(17, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17);
    df->add_column(c);
    CS4500_ASSERT_TRUE(df->length() == c->size());
    CS4500_ASSERT_TRUE(df->width() == 1);
    for (size_t i = 0; i < df->length(); i++)
    {
        CS4500_ASSERT_TRUE(df->get_int(0, i) == c->get(i));
    }

    //schema with just rows
    Schema *s3 = new Schema();
    for (int i = 0; i < 17; i++)
    {
        s3->add_row(nullptr);
    }
    DataFrame *df3 = new DataFrame(*s2);
    df->add_column(c);
    CS4500_ASSERT_TRUE(df->length() == c->size());
    CS4500_ASSERT_TRUE(df->width() == 1);
    for (size_t i = 0; i < df->length(); i++)
    {
        CS4500_ASSERT_TRUE(df->get_int(0, i) == c->get(i));
    }

    // schema with columns and rows
    Schema *s4 = new Schema("IFBIFBFSSS");
    for (int i = 0; i < 17; i++)
    {
        s4->add_row(nullptr);
    }
    DataFrame *df4 = new DataFrame(*s4);
    df->add_column(c);
    CS4500_ASSERT_TRUE(df->length() == c->size());
    CS4500_ASSERT_TRUE(df->width() == s4->length() + 1);
    for (size_t i = 0; i < df->length(); i++)
    {
        CS4500_ASSERT_TRUE(df->get_int(0, i) == c->get(i));
    }
    exit(0);
}

TEST(df, test2)
{
    CS4500_ASSERT_EXIT_ZERO(testAddIntColumn2);
}

/**
 * @brief Checks if adding column adds the specified BoolColumn the manner expected.
 * 
 */
void testAddBoolColumn3()
{
    // empty schema
    Schema *s = new Schema();
    DataFrame *df = new DataFrame(*s);
    Column *c = new BoolColumn(18, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false);
    df->add_column(c);
    CS4500_ASSERT_TRUE(df->length() == c->size());
    CS4500_ASSERT_TRUE(df->width() == 1);
    for (size_t i = 0; i < df->length(); i++)
    {
        CS4500_ASSERT_TRUE(df->get_int(0, i) == c->get(i));
    }

    //schema with just rows
    Schema *s3 = new Schema();
    for (int i = 0; i < 18; i++)
    {
        s3->add_row(nullptr);
    }
    DataFrame *df3 = new DataFrame(*s2);
    df->add_column(c);
    CS4500_ASSERT_TRUE(df->length() == c->size());
    CS4500_ASSERT_TRUE(df->width() == 1);
    for (size_t i = 0; i < df->length(); i++)
    {
        CS4500_ASSERT_TRUE(df->get_int(0, i) == c->get(i));
    }

    // schema with columns and rows
    Schema *s4 = new Schema("IFBIFBFSSS");
    for (int i = 0; i < 18; i++)
    {
        s4->add_row(nullptr);
    }
    DataFrame *df4 = new DataFrame(*s4);
    df->add_column(c);
    CS4500_ASSERT_TRUE(df->length() == c->size());
    CS4500_ASSERT_TRUE(df->width() == s4->length() + 1);
    for (size_t i = 0; i < df->length(); i++)
    {
        CS4500_ASSERT_TRUE(df->get_int(0, i) == c->get(i));
    }
    exit(0);
}

TEST(df, test3)
{
    CS4500_ASSERT_EXIT_ZERO(testAddBoolColumn3);
}

/**
 * @brief Checks if adding column adds the specified FloatColumn the manner expected.
 * 
 */
void testAddFloatColumn4()
{
    // empty schema
    Schema *s = new Schema();
    DataFrame *df = new DataFrame(*s);
    Column *c = new FloatColumn(17, 1.22, 2.22, 3.22, 4.22, 5.22, 6.22, 7.22, 8.22, 9.22, 10.22, 11.22, 12.22, 13.22, 14.22, 15.22, 16.22, 17.22);
    df->add_column(c);
    CS4500_ASSERT_TRUE(df->length() == c->size());
    CS4500_ASSERT_TRUE(df->width() == 1);
    for (size_t i = 0; i < df->length(); i++)
    {
        float expected = float(j) + 1.22;
        CS4500_ASSERT_TRUE(df->get_int(0, i) - expected < 0.001);
        CS4500_ASSERT_TRUE(df->get_int(0, i) - expected > -0.001);
    }

    //schema with just rows
    Schema *s3 = new Schema();
    for (int i = 0; i < 17; i++)
    {
        s3->add_row(nullptr);
    }
    DataFrame *df3 = new DataFrame(*s2);
    df->add_column(c);
    CS4500_ASSERT_TRUE(df->length() == c->size());
    CS4500_ASSERT_TRUE(df->width() == 1);
    for (size_t i = 0; i < df->length(); i++)
    {
        float expected = float(j) + 1.22;
        CS4500_ASSERT_TRUE(df->get_int(0, i) - expected < 0.001);
        CS4500_ASSERT_TRUE(df->get_int(0, i) - expected > -0.001);
    }

    // schema with columns and rows
    Schema *s4 = new Schema("IFBIFBFSSS");
    for (int i = 0; i < 17; i++)
    {
        s4->add_row(nullptr);
    }
    DataFrame *df4 = new DataFrame(*s4);
    df->add_column(c);
    CS4500_ASSERT_TRUE(df->length() == c->size());
    CS4500_ASSERT_TRUE(df->width() == s4->length() + 1);
    for (size_t i = 0; i < df->length(); i++)
    {
        float expected = float(j) + 1.22;
        CS4500_ASSERT_TRUE(df->get_int(0, i) - expected < 0.001);
        CS4500_ASSERT_TRUE(df->get_int(0, i) - expected > -0.001);
    }
    exit(0);
}

TEST(df, test4)
{
    CS4500_ASSERT_EXIT_ZERO(testAddFloatColumn4);
}

/**
 * @brief Runs all Google Tests in this file
 */
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
