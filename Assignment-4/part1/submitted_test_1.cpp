//lang CwC
// testing rower

#include <gtest/gtest.h>
#include "dataframe.h"

#define CS4500_ASSERT_TRUE(a) \
    ASSERT_EQ((a), true);
#define CS4500_ASSERT_FALSE(a) \
    ASSERT_EQ((a), false);
#define CS4500_ASSERT_EXIT_ZERO(a) \
    ASSERT_EXIT(a(), ::testing::ExitedWithCode(0), ".*");

// example cases
//  CS4500_ASSERT_TRUE(s->equals(s));
//  CS4500_ASSERT_FALSE(s->equals(t));
//  CS4500_ASSERT_FALSE(s->equals(u));
// exit(0) at end of each test

/**
 * @brief tests Rower's accept() function on rows populated via a nonempty dataframe/schema.
 * 
 */
void testAcceptNonemptyRow()
{
    Schema s = Schema("IISFB");  // nonempty schema
    DataFrame df = Dataframe(s); // make df based on nonempty schema
    Row r(df.get_schema());      // making a row based off the schema
    // filling df with rows
    for (size_t i = 0; i < 1000; i++)
    {
        r.set(0, (int)i);
        r.set(1, (int)i + 1);
        r.set(2, "string hello");
        r.set(3, (float)i + 0.22);
        r.set(4, i % 2 == 1);
        df.add_row(r);
    }
    Rower rower_ = Rower(); // creating rower object
    // iterating through the rows and checking that the rower accepts each row given to it
    for (size_t i = 0; i < df.nrows(); i++)
    {
        Row *r_ = new Row(df.get_schema());
        df.fill_row(i, r_);
        CS4500_ASSERT_TRUE(rower_.accept(*r_));
        delete r_;
    }
    exit(0);
}

TEST(W1, testAcceptNonemptyRow)
{
    CS4500_ASSERT_EXIT_ZERO(testAcceptNonemptyRow);
}

/**
 * @brief tests Rower's accept() function on a row created via an empty Schema
 * 
 */
void testAcceptEmptyRow()
{
    Schema = Schema s(); // empty schema
    Row r = Row(s);      // making a row from empty schema
    Rower rower_ = Rower();
    CS4500_ASSERT_TRUE(rower_.accept(r));
    exit(0);
}

TEST(W1, testAcceptNonemptyRow)
{
    CS4500_ASSERT_EXIT_ZERO(testAcceptEmptyRow);
}

/**
 * @brief tests Rower's accept() function on a row created from an dataframe based on Schema that has no columns but many rows
 * 
 */
void testAcceptEmptyRow2()
{
    Schema = Schema s(); // empty schema
    // adding rows to schema
    for (size_t i = 0; i < 1000; i++)
    {
        s.addRow(nullptr);
    }
    DataFrame df = DataFrame(s); // dataframe which has 1000 rows and no columns
    Rower rower_ = Rower();      // creating rower object
    // iterating through the rows and checking that the rower accepts each row given to it
    for (size_t i = 0; i < df.nrows(); i++)
    {
        Row *r_ = new Row(df.get_schema());
        df.fill_row(i, r_);
        CS4500_ASSERT_TRUE(rower_.accept(*r_));
        delete r_;
    }
    exit(0);
}

TEST(W1, testAcceptNonemptyRow)
{
    CS4500_ASSERT_EXIT_ZERO(testAcceptEmptyRow2);
}

/** there is no way to test join_delete since join_delete() function presumably as of now only should delete the *Rower passed 
 * into the function and there is no way to check if it is actually deleted since the pointer can still technically be called
 * and that would just be undefined behavior
 *
 **/

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
