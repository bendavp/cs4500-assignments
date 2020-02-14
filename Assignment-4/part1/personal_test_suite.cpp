#include <gtest/gtest.h>
#include "dataframe.h"
#include <math.h>

#define GT_TRUE(a) ASSERT_EQ((a), true)
#define GT_FALSE(a) ASSERT_EQ((a), false)
#define GT_EQUALS(a, b) ASSERT_EQ(a, b)
#define ASSERT_EXIT_ZERO(a) \
    ASSERT_EXIT(a(), ::testing::ExitedWithCode(0), ".*")

/**
 * @brief Tests if we can actually pass va_list into a constructor as the literal va_list.
 * This is because all Columns take a va_list and pass it into the FastArray constructors
 * 
 * Jan wasn't sure if this would actually work so we decided to test it out!
 */
void doesVaListActuallyWork()
{
    IntFastArray *i = new IntFastArray(5, 1, 2, 3, 4, 5);
    BoolFastArray *b = new BoolFastArray(2, true, false);
    FloatFastArray *f = new FloatFastArray(4, 4.20, 4.20, 4.20, 4.20);
    StringFastArray *s = new StringFastArray(2, new String("hello"), new String("world"));

    IntColumn *ic = new IntColumn(5, 1, 2, 3, 4, 5);
    BoolColumn *bc = new BoolColumn(2, true, false);
    FloatColumn *fc = new FloatColumn(4, 4.20, 4.20, 4.20, 4.20);
    StringColumn *sc = new StringColumn(2, new String("hello"), new String("world"));

    GT_TRUE(i->equals(ic->arr_));
    GT_TRUE(b->equals(bc->arr_));
    GT_TRUE(f->equals(fc->arr_));
    GT_TRUE(s->equals(sc->arr_));

    delete i;
    delete b;
    delete f;
    delete s;
    delete ic;
    delete bc;
    delete fc;
    delete sc;
    exit(0);
}

TEST(a4, p1) { ASSERT_EXIT_ZERO(doesVaListActuallyWork); }

/**
 * @brief Tests the get() function in all FastArrays
 * 
 */
void testGet()
{
    IntFastArray *i = new IntFastArray(5, 1, 2, 3, 4, 5);
    BoolFastArray *b = new BoolFastArray(2, true, false);
    FloatFastArray *f = new FloatFastArray(4, 4.20, 4.20, 4.20, 4.20);
    StringFastArray *s = new StringFastArray(2, new String("hello"), new String("world"));

    GT_EQUALS(i->get(0), 1);
    GT_EQUALS(i->get(4), 5);
    GT_EQUALS(b->get(0), true);
    GT_EQUALS(b->get(1), false);
    GT_TRUE(f->get(0) - 4.20 < 0.001 && f->get(0) - 4.20 > -.001);
    GT_TRUE(f->get(3) - 4.20 < 0.001 && f->get(3) - 4.20 > -.001);
    GT_TRUE(s->get(0)->equals(new String("hello")));
    GT_TRUE(s->get(1)->equals(new String("world")));

    exit(0);
}

TEST(a4, p2) { ASSERT_EXIT_ZERO(testGet); }

/**
 * @brief Tests the set() function in all FastArrays
 * 
 */
void testSet()
{
    IntFastArray *i = new IntFastArray(5, 1, 2, 3, 4, 5);
    BoolFastArray *b = new BoolFastArray(2, true, false);
    FloatFastArray *f = new FloatFastArray(4, 4.20, 4.20, 4.20, 4.20);
    StringFastArray *s = new StringFastArray(2, new String("hello"), new String("world"));

    i->set(0, 420);
    i->set(4, 69);
    GT_EQUALS(i->get(0), 420);
    GT_EQUALS(i->get(4), 69);

    b->set(0, true);
    b->set(1, false);
    GT_EQUALS(b->get(0), true);
    GT_EQUALS(b->get(1), false);

    f->set(0, 4.20);
    f->set(3, 6.9);
    GT_TRUE(f->get(0) - 4.20 < 0.001 && f->get(0) - 4.20 > -.001);
    GT_TRUE(f->get(3) - 6.9 < 0.001 && f->get(3) - 6.9 > -.001);

    String *h = new String("Heeellloooooo"); // no need to delete these as FastArrays own their contents
    String *w = new String("wooooorllddddd");
    s->set(0, h);
    s->set(1, w);
    GT_TRUE(s->get(0)->equals(h));
    GT_TRUE(s->get(1)->equals(w));

    exit(0);
}

TEST(a4, p3) { ASSERT_EXIT_ZERO(testSet); }

/**
 * @brief Tests the grow() function in all FastArrays by
 * adding 512 elements to each, which would grow
 * the outer array twice and the inner array(s) multiple
 * times
 * 
 * Also tests push_back() because we have to use that
 * function to test grow()
 * 
 */
void testGrowAndPushBack()
{
    IntFastArray *i = new IntFastArray(5, 1, 2, 3, 4, 5);
    BoolFastArray *b = new BoolFastArray(2, true, false);
    FloatFastArray *f = new FloatFastArray(4, 4.20, 4.20, 4.20, 4.20);
    StringFastArray *s = new StringFastArray(2, new String("hello"), new String("world"));

    for (int j = 0; j < 512; j++)
    {
        i->push_back(j);
        GT_EQUALS(i->get(j + 5), j);
    }

    for (int j = 0; j < 512; j++)
    {
        b->push_back(0);
        GT_EQUALS(b->get(j + 2), 0);
    }

    for (int j = 0; j < 512; j++)
    {
        f->push_back(4.20);
        GT_TRUE(f->get(j + 4) - 4.20 < 0.001 && f->get(j + 4) - 4.20 > -.001);
    }

    String *str = new String("hello world"); // FastArrays own their contents, so no need to delete this at the end
    for (int j = 0; j < 512; j++)
    {
        s->push_back(str);
        GT_TRUE(s->get(j + 2)->equals(str));
    }

    exit(0);
}

TEST(a4, p4) { ASSERT_EXIT_ZERO(testGrowAndPushBack); }

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
    GT_TRUE(s->row_name(0)->equals(new String("easepease")));

    exit(0);
}

TEST(t6, addRowEmptySchema) { ASSERT_EXIT_ZERO(testAddRowToEmptySchema); }

void testAddNullRowToEmptySchema()
{
    Schema *s = new Schema();
    s->add_row(nullptr);
    GT_TRUE(s->row_name(0) == nullptr);

    exit(0);
}

TEST(t6, addNullRowEmptySchema) { ASSERT_EXIT_ZERO(testAddNullRowToEmptySchema); }

void testAddRowToSchema()
{
    String *s_str = new String("FIBS");
    Schema *s = new Schema(s_str->c_str());

    s->add_row(new String("easepease"));

    GT_TRUE(s->row_name(0)->equals(new String("easepease")));

    exit(0);
}

TEST(t6, addRowSchema) { ASSERT_EXIT_ZERO(testAddRowToSchema); }

void testAddNullRowToSchema()
{
    String *s_str = new String("FIBS");
    Schema *s = new Schema(s_str->c_str());

    s->add_row(nullptr);

    GT_TRUE(s->row_name(0) == nullptr);

    exit(0);
}

TEST(t6, addNullRowToSchema) { ASSERT_EXIT_ZERO(testAddNullRowToSchema); }

void testGetColIdxEmptySchema()
{
    Schema *s = new Schema();

    s->add_column('B', new String("b"));
    s->add_column('I', new String("i"));
    s->add_column('F', new String("f"));
    s->add_column('S', new String("s"));

    GT_EQUALS(s->width(), 4);
    GT_EQUALS(s->col_idx("b"), 0);
    GT_EQUALS(s->col_idx("i"), 1);
    GT_EQUALS(s->col_idx("f"), 2);
    GT_EQUALS(s->col_idx("s"), 3);

    exit(0);
}

TEST(t6, getColIdxEmpty) { ASSERT_EXIT_ZERO(testGetColIdxEmptySchema); }

void testGetColIdx()
{
    String *s_str = new String("FIBS");
    Schema *s = new Schema(s_str->c_str());

    s->add_column('B', new String("b"));
    s->add_column('I', new String("i"));
    s->add_column('F', new String("f"));
    s->add_column('S', new String("s"));

    GT_EQUALS(s->width(), 8);
    GT_EQUALS(s->col_idx("b"), 4);
    GT_EQUALS(s->col_idx("i"), 5);
    GT_EQUALS(s->col_idx("f"), 6);
    GT_EQUALS(s->col_idx("s"), 7);

    exit(0);
}

TEST(t6, getColIdx) { ASSERT_EXIT_ZERO(testGetColIdx); }

void testGetRowIdxEmptySchema()
{
    Schema *s = new Schema();

    s->add_row(new String("b"));
    s->add_row(new String("i"));
    s->add_row(new String("f"));
    s->add_row(new String("s"));

    GT_EQUALS(s->length(), 4);
    GT_EQUALS(s->row_idx("b"), 0);
    GT_EQUALS(s->row_idx("i"), 1);
    GT_EQUALS(s->row_idx("f"), 2);
    GT_EQUALS(s->row_idx("s"), 3);

    exit(0);
}

TEST(t6, getRowIdxEmpty) { ASSERT_EXIT_ZERO(testGetRowIdxEmptySchema); }

void testGetRowIdx()
{
    String *s_str = new String("FIBS");
    Schema *s = new Schema(s_str->c_str());

    s->add_row(new String("b"));
    s->add_row(new String("i"));
    s->add_row(new String("f"));
    s->add_row(new String("s"));

    GT_EQUALS(s->length(), 4);
    GT_EQUALS(s->row_idx("b"), 0);
    GT_EQUALS(s->row_idx("i"), 1);
    GT_EQUALS(s->row_idx("f"), 2);
    GT_EQUALS(s->row_idx("s"), 3);

    exit(0);
}

TEST(t6, getRowIdx) { ASSERT_EXIT_ZERO(testGetRowIdx); }

/**
 * @brief tests Rower's accept() function on rows populated via a nonempty dataframe/schema.
 * 
 */
void testAcceptNonemptyRow()
{
    Schema *s = new Schema("IISFB");    // nonempty schema
    DataFrame *df = new DataFrame(*s);  // make df based on nonempty schema
    Row *r = new Row(df->get_schema()); // making a row based off the schema
    // filling df with rows
    for (size_t i = 0; i < 1000; i++)
    {
        r->set(0, (int)i);
        r->set(1, (int)i + 1);
        r->set(2, new String("string hello"));
        r->set(3, (float)(i + 0.22));
        r->set(4, i % 2 == 1);
        df->add_row(*r);
        delete r;
    }
    Rower rower_ = Rower(); // creating rower object
    // iterating through the rows and checking that the rower accepts each row given to it
    Row *r_ = new Row(df->get_schema());
    for (size_t i = 0; i < df->nrows(); i++)
    {
        r_ = new Row(df->get_schema());
        df->fill_row(i, *r_);
        GT_TRUE(rower_.accept(*r_));
        delete r_;
    }
    delete df;
    exit(0);
}

TEST(t1, testAcceptNonemptyRow)
{
    ASSERT_EXIT_ZERO(testAcceptNonemptyRow);
}

/**
 * @brief tests Rower's accept() function on a row created via an empty Schema
 * 
 */
void testAcceptEmptyRow()
{
    Schema *s = new Schema(); // empty schema
    Row r = Row(*s);          // making a row from empty schema
    Rower rower_ = Rower();
    GT_TRUE(rower_.accept(r));
    delete s;
    exit(0);
}

TEST(t1, testAcceptEmptyRow)
{
    ASSERT_EXIT_ZERO(testAcceptEmptyRow);
}

/**
 * @brief tests Rower's accept() function on a row created from an dataframe based on Schema that has no columns but many rows
 * 
 */
void testAcceptEmptyRow2()
{
    Schema *s = new Schema(); // empty schema
    // adding rows to schema
    for (size_t i = 0; i < 1000; i++)
    {
        s->add_row(nullptr);
    }
    DataFrame *df = new DataFrame(*s); // dataframe which has 1000 rows and no columns
    Rower rower_ = Rower();            // creating rower object
    // iterating through the rows and checking that the rower accepts each row given to it
    Row *r_ = new Row(df->get_schema());
    for (size_t i = 0; i < df->nrows(); i++)
    {
        r_ = new Row(df->get_schema());
        df->fill_row(i, *r_);
        GT_TRUE(rower_.accept(*r_));
        //delete r_;
    }
    delete df;
    exit(0);
}

TEST(t1, testAcceptEmptyRow2)
{
    ASSERT_EXIT_ZERO(testAcceptEmptyRow2);
}

/**
 * @brief Runs all Google Tests in this file
 */
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}