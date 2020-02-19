#include <gtest/gtest.h>
#include "dataframe.h"

#define GT_TRUE(a) ASSERT_EQ((a), true)
#define GT_FALSE(a) ASSERT_EQ((a), false)
#define GT_EQUALS(a, b) ASSERT_EQ(a, b)
#define ASSERT_EXIT_ZERO(a) \
    ASSERT_EXIT(a(), ::testing::ExitedWithCode(0), ".*")

/**
 * @brief Testing adding a Column with a name to a nonempty schema via checking that col_types is as expected and the 
 * number of columns is the expected number.
 * 
 */
void testSchemaAddingColumns()
{
    String *s_str = new String("FIBS");
    Schema *s = new Schema(s_str->c_str());
    GT_TRUE(s->coltypes_->equals(s_str));

    s->add_column('S', new String("Lies"));
    String *s5 = new String("FIBSS");
    GT_EQUALS(s->width(), 5);
    GT_TRUE(s->coltypes_->equals(s5));
    GT_TRUE(s->col_name(4)->equals(new String("Lies")));
    GT_TRUE(s->col_idx("Lies") == 4);
    delete s5;

    s->add_column('I', new String("int col"));
    String *s6 = new String("FIBSSI");
    GT_EQUALS(s->width(), 6);
    GT_TRUE(s->coltypes_->equals(s6));
    GT_TRUE(s->col_name(5)->equals(new String("int col")));
    GT_TRUE(s->col_idx("int col") == 5);
    delete s6;

    s->add_column('F', nullptr);
    GT_EQUALS(s->width(), 7);
    String *s7 = new String("FIBSSIF");
    GT_TRUE(s->coltypes_->equals(s7));
    GT_TRUE(s->col_name(6) == nullptr);
    delete s7;

    s->add_column('B', new String("no name"));
    GT_EQUALS(s->width(), 8);
    String *s8 = new String("FIBSSIFB");
    GT_TRUE(s->coltypes_->equals(s8));
    GT_TRUE(s->col_idx("no name") == 7);
    delete s8;

    exit(0);
}

TEST(test7, schemaAddColumn) { ASSERT_EXIT_ZERO(testSchemaAddingColumns); }

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}