#include <gtest/gtest.h>
#include "dataframe.h"

#define GT_TRUE(a) ASSERT_EQ((a), true)
#define GT_FALSE(a) ASSERT_EQ((a), false)
#define GT_EQUALS(a, b) ASSERT_EQ(a, b)
#define ASSERT_EXIT_ZERO(a) \
    ASSERT_EXIT(a(), ::testing::ExitedWithCode(0), ".*")

/**
 * @brief Testing adding a row without a name to an nonempty schema via checking that the length of the schema has changed
 * and that the name of the row is as expected.
 * 
 */
void testAddNullRowToSchema()
{
    String *s_str = new String("FIBS");
    Schema *s = new Schema(s_str->c_str());
    GT_TRUE(s->length() == 0);
    GT_TRUE(s->width() == 4);

    s->add_row(nullptr);
    GT_TRUE(s->length() == 1);
    GT_TRUE(s->width() == 4);
    GT_TRUE(s->row_name(0) == nullptr);

    exit(0);
}

TEST(test6, NonemptySchemaAddRow) { ASSERT_EXIT_ZERO(testAddNullRowToSchema); }

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}