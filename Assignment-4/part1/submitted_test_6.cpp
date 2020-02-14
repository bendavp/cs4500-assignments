#include <gtest/gtest.h>
#include "schema.h"
#include <math.h>

#define GT_TRUE(a) ASSERT_EQ((a), true)
#define GT_FALSE(a) ASSERT_EQ((a), false)
#define GT_EQUALS(a, b) ASSERT_EQ(a, b)
#define ASSERT_EXIT_ZERO(a) \
    ASSERT_EXIT(a(), ::testing::ExitedWithCode(0), ".*")

void testAddColumn()
{
    String *s_str = new String("FIBS");
    Schema *s = new Schema(s_str->c_str());

    GT_TRUE(s->coltypes_->equals(s_str));
    s->add_column('S', new String("Lies"));
    String *s_str_new = new String("FIBSS");

    GT_EQUALS(s->width(), 5);
    GT_TRUE(s->coltypes_->equals(s_str_new));
    GT_TRUE(s->col_name(4)->equals(new String("Lies")));

    exit(0);
}

TEST(t6, addCol) { ASSERT_EXIT_ZERO(testAddColumn); }

void testAddEmptyNameColumn()
{
    String *s_str = new String("FIBS");
    Schema *s = new Schema(s_str->c_str());

    GT_TRUE(s->coltypes_->equals(s_str));
    s->add_column('S', nullptr);
    String *s_str_new = new String("FIBSS");

    GT_EQUALS(s->width(), 5);
    GT_TRUE(s->coltypes_->equals(s_str_new));
    GT_TRUE(s->col_name(4) == nullptr);

    exit(0);
}

TEST(t6, addNoName) { ASSERT_EXIT_ZERO(testAddEmptyNameColumn); }

void testAddColToEmptySchemaNoName()
{
    Schema *s = new Schema();

    s->add_column('S', nullptr);

    GT_EQUALS(s->width(), 1);
    GT_TRUE(s->coltypes_->equals(new String("S")));
    GT_TRUE(s->col_name(0) == nullptr);

    exit(0);
}

TEST(t6, addColEmptyNoName) { ASSERT_EXIT_ZERO(testAddColToEmptySchemaNoName); }

void testAddColToEmptySchema()
{
    Schema *s = new Schema();

    s->add_column('S', new String("Lies"));

    GT_EQUALS(s->width(), 1);
    GT_TRUE(s->coltypes_->equals(new String("S")));
    GT_TRUE(s->col_name(0)->equals(new String("Lies")));

    exit(0);
}

TEST(t6, addColEmpty) { ASSERT_EXIT_ZERO(testAddColToEmptySchema); }

void testAddRowToEmptySchema()
{
    Schema *s = new Schema();
    s->add_row(new String("easepease"));
    GT_TRUE(s->length() == 1);
    //GT_TRUE(s->row_name(0)->equals(new String("easepease")));
}

TEST(t6, addRowEmptySchema) { ASSERT_EXIT_ZERO(testAddRowToEmptySchema); }

void testAddNullRowToEmptySchema()
{
    Schema *s = new Schema();
    s->add_row(nullptr);
    GT_TRUE(s->row_name(0) == nullptr);
}

TEST(t6, addNullRowEmptySchema) { ASSERT_EXIT_ZERO(testAddNullRowToEmptySchema); }

void testAddRowToSchema()
{
    String *s_str = new String("FIBS");
    Schema *s = new Schema(s_str->c_str());

    s->add_row(new String("easepease"));

    GT_TRUE(s->row_name(4)->equals(new String("easepease")));
}

TEST(t6, addRowSchema) { ASSERT_EXIT_ZERO(testAddRowToSchema); }

void testAddNullRowToSchema()
{
    String *s_str = new String("FIBS");
    Schema *s = new Schema(s_str->c_str());

    s->add_row(nullptr);

    GT_TRUE(s->row_name(4) == nullptr);
}

TEST(t6, addNullRowToSchema) { ASSERT_EXIT_ZERO(testAddNullRowToSchema); }

/**
 * @brief Runs all Google Tests in this file
 */
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}