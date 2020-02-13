//lang CwC
// testing column

#include <gtest/gtest.h>
#include "dataframe.h"

#define CS4500_ASSERT_TRUE(a) \
    ASSERT_EQ((a), true);
#define CS4500_ASSERT_FALSE(a) \
    ASSERT_EQ((a), false);
#define CS4500_ASSERT_EXIT_ZERO(a) \
    ASSERT_EXIT(a(), ::testing::ExitedWithCode(0), ".*");

/**
 * @brief Checking to see if we can accurately get the elements from an IntColumn
 * 
 */
void testIntColumnGet1()
{
    IntColumn *i = new IntColumn(17, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
    for (int j = 0; j < 17; j++)
    {
        CS4500_ASSERT_TRUE(i->get(j) == j);
    }
    delete i;
    exit(0);
}

TEST(t2, int1)
{
    CS4500_ASSERT_EXIT_ZERO(testIntColumnGet1);
}

/**
 * @brief Testing set function via setting the values then getting them to check if we set the value correctly as each location.
 * 
 */
void testIntColumnSet2()
{
    IntColumn *i = new IntColumn(17, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
    // set 1 value in i to something else and check if that one value changed correctly
    i->set(8, 8888);
    CS4500_ASSERT_TRUE(i->get(8) == 8888);
    // set all values in i to something else and check
    for (int j = 0; j < 17; j++)
    {
        i->set(j, j * 3);
    }
    for (size_t j = 0; j < 17; j++)
    {
        CS4500_ASSERT_TRUE(i->get(j) == j * 3);
    }
    delete i;
    exit(0);
}

TEST(t2, int2)
{
    CS4500_ASSERT_EXIT_ZERO(testIntColumnSet2);
}

/**
 * @brief Testing that push_back() function works as expected for empty and nonempty Columns. Check after each push back that the added element is
 * where and what is expected.
 * 
 */
void testIntColumnPushBack3()
{
    // checking empty column
    IntColumn *i_ = new IntColumn();
    // adding to empty column and checking to see if added element is where and what we expect
    for (size_t j = 0; j < 10000000; j++)
    {
        i_->push_back(j);
        CS4500_ASSERT_TRUE(i_->get(j) == j);
    }
    delete i_;

    // checking nonempty array
    IntColumn *i = new IntColumn(17, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
    for (size_t j = 0; j < 10000000; j++)
    {
        i->push_back(j * 3);
        CS4500_ASSERT_TRUE(i->get(j + 17) == (j * 3));
    }
    delete i;
    exit(0);
}

TEST(t2, int3)
{
    CS4500_ASSERT_EXIT_ZERO(testIntColumnPushBack3);
}

/**
 * @brief Testing that size works as expected for empty and nonempty Columns including after we add new elements via push_back() function
 * 
 */
void testIntColumnSize4()
{
    // checking empty column
    IntColumn *i_ = new IntColumn();
    CS4500_ASSERT_TRUE(i_->size() == 0);
    // adding to empty column and checking to see if size is as expected after each add and at the end
    for (size_t j = 0; j < 10000000; j++)
    {
        i_->push_back(j);
        CS4500_ASSERT_TRUE(i_->size() == (j + 1));
    }
    CS4500_ASSERT_TRUE(i_->size() == 10000000);
    delete i_;
    // checking nonempty column
    IntColumn *i = new IntColumn(17, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
    CS4500_ASSERT_TRUE(i->size() == 17);
    // adding to nonempty column and checking to see if size is as expected after each add and at the end
    for (size_t j = 0; j < 10000000; j++)
    {
        i->push_back(j);
        CS4500_ASSERT_TRUE(i->size() == (j + 18));
    }
    for (size_t j = 0; j < 17; j++)
    {
        CS4500_ASSERT_TRUE(i->get(j) == j);
    }
    delete i;
    exit(0);
}

TEST(t2, int4)
{
    CS4500_ASSERT_EXIT_ZERO(testIntColumnSize4);
}

/**
 * @brief Testing if empty/nonempty IntColumn returns the expected pointer
 * 
 */
void testIntColumnAsType5()
{
    // checking empty column
    IntColumn *i_ = new IntColumn();
    CS4500_ASSERT_TRUE(i_ == i_->as_int());
    CS4500_ASSERT_TRUE(i_->as_bool() == nullptr);
    CS4500_ASSERT_TRUE(i_->as_float() == nullptr);
    CS4500_ASSERT_TRUE(i_->as_string() == nullptr);
    // checking nonempty column
    IntColumn *i = new IntColumn(17, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
    CS4500_ASSERT_TRUE(i == i->as_int());
    CS4500_ASSERT_TRUE(i->as_bool() == nullptr);
    CS4500_ASSERT_TRUE(i->as_float() == nullptr);
    CS4500_ASSERT_TRUE(i->as_string() == nullptr);
    delete i;
    delete i_;
    exit(0);
}

TEST(t2, int5)
{
    CS4500_ASSERT_EXIT_ZERO(testIntColumnAsType5);
}

/**
 * @brief Testing if empty/nonempty IntColumn returns the expected char representing its type
 * 
 */
void testIntColumnGetType6()
{
    // checking empty column
    Column *i_ = new IntColumn();
    CS4500_ASSERT_TRUE(i_->get_type() == 'I');
    // checking nonempty column
    IntColumn *i = new IntColumn(17, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
    CS4500_ASSERT_TRUE(i->get_type() == 'I');
    delete i;
    delete i_;
    exit(0);
}

TEST(t2, int6)
{
    CS4500_ASSERT_EXIT_ZERO(testIntColumnGetType6);
}

/**
 * @brief Tests the clone method for an IntColumn. Because Columns have pointer equality, to see if clone is correct, we test to see if each element is the same. 
 * Additionally, because a clone should not directly point at something the Column owns, the original Column is deleted and then the values in the clone are checked
 * again.
 * 
 */
void testIntColumnClone7()
{
    // create and populate IntCol
    IntColumn *i = new IntColumn();
    for (size_t j = 0; j < 10000; j++)
    {
        i->push_back(j);
    }
    IntColumn *i_ = i->clone();
    CS4500_ASSERT_TRUE(i->size() == i_->size());
    // check manually if each element is the same
    for (size_t j = 0; j < i->size(); j++)
    {
        CS4500_ASSERT_TRUE(i->get(j) == i_->get(j));
    }
    delete i;
    // check that the clone retains information/elements after original is deleted
    for (size_t j = 0; j < 10000; j++)
    {
        CS4500_ASSERT_TRUE(i_->get(j) == j);
    }
    delete i_;
    exit(0);
}

TEST(t2, int7)
{
    CS4500_ASSERT_EXIT_ZERO(testIntColumnClone7);
}

/**
 * @brief Checking to see if we can accurately get the elements from an BoolColumn
 * 
 */
void testBoolColumnGet1()
{
    BoolColumn *i = new BoolColumn(18, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false);
    for (size_t j = 0; j < 18; j++)
    {
        CS4500_ASSERT_TRUE(i->get(j) == (j % 2 == 0));
    }
    delete i;
    exit(0);
}

TEST(t2, Bool1)
{
    CS4500_ASSERT_EXIT_ZERO(testBoolColumnGet1);
}

/**
 * @brief Testing set function via setting the values then getting them to check if we set the value correctly as each location.
 * 
 */
void testBoolColumnSet2()
{
    BoolColumn *i = new BoolColumn(18, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false);
    // set 1 value in i to something else and check if that one value changed correctly
    i->set(8, false);
    CS4500_ASSERT_FALSE(i->get(8));
    // set all values in i to something else and check
    for (size_t j = 0; j < 18; j++)
    {
        i->set(j, (j % 2 == 1));
    }
    for (size_t j = 0; j < 18; j++)
    {
        bool expected = (j % 2 == 1);
        CS4500_ASSERT_TRUE(i->get(j) == expected);
    }
    delete i;
    exit(0);
}

TEST(t2, Bool2)
{
    CS4500_ASSERT_EXIT_ZERO(testBoolColumnSet2);
}

/**
 * @brief Testing that push_back() function works as expected for empty and nonempty Columns. Check after each push back that the added element is
 * where and what is expected.
 * 
 */
void testBoolColumnPushBack3()
{
    // checking empty column
    BoolColumn *i_ = new BoolColumn();
    // adding to empty column and checking to see if added element is where and what we expect
    for (size_t j = 0; j < 10000000; j++)
    {
        i_->push_back(j % 2 == 0);
        CS4500_ASSERT_TRUE(i_->get(j) == (j % 2 == 0));
    }
    delete i_;

    // checking nonempty array
    BoolColumn *i = new BoolColumn(18, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false);
    for (size_t j = 0; j < 10000000; j++)
    {
        i->push_back((j % 2 == 1));
        CS4500_ASSERT_TRUE(i->get(j + 18) == (j % 2 == 1));
    }
    // check that the beginning is unchanged by pushback
    for (size_t j = 0; j < 18; j++)
    {
        CS4500_ASSERT_TRUE(i->get(j) == (j % 2 == 0));
    }
    delete i;
    exit(0);
}

TEST(t2, Bool3)
{
    CS4500_ASSERT_EXIT_ZERO(testBoolColumnPushBack3);
}

/**
 * @brief Testing that size works as expected for empty and nonempty Columns including after we add new elements via push_back() function
 * 
 */
void testBoolColumnSize4()
{
    // checking empty column
    BoolColumn *i_ = new BoolColumn();
    CS4500_ASSERT_TRUE(i_->size() == 0);
    // adding to empty column and checking to see if size is as expected after each add and at the end
    for (size_t j = 0; j < 10000000; j++)
    {
        i_->push_back(true);
        CS4500_ASSERT_TRUE(i_->size() == (j + 1));
    }
    CS4500_ASSERT_TRUE(i_->size() == 10000000);
    delete i_;
    // checking nonempty column
    BoolColumn *i = new BoolColumn(18, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false);
    CS4500_ASSERT_TRUE(i->size() == 18);
    // adding to nonempty column and checking to see if size is as expected after each add and at the end
    for (size_t j = 0; j < 10000000; j++)
    {
        i->push_back(true);
        CS4500_ASSERT_TRUE(i->size() == (j + 19));
    }
    //CS4500_ASSERT_TRUE(i->size() == 10000018);
    delete i;
    exit(0);
}

TEST(t2, Bool4)
{
    CS4500_ASSERT_EXIT_ZERO(testBoolColumnSize4);
}

/**
 * @brief Testing if empty/nonempty BoolColumn returns the expected poBooler
 * 
 */
void testBoolColumnAsType5()
{
    // checking empty column
    BoolColumn *i_ = new BoolColumn();
    CS4500_ASSERT_TRUE(i_ == i_->as_bool());
    CS4500_ASSERT_TRUE(i_->as_int() == nullptr);
    CS4500_ASSERT_TRUE(i_->as_float() == nullptr);
    CS4500_ASSERT_TRUE(i_->as_string() == nullptr);
    // checking nonempty column
    BoolColumn *i = new BoolColumn(18, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false);
    CS4500_ASSERT_TRUE(i == i->as_bool());
    CS4500_ASSERT_TRUE(i->as_int() == nullptr);
    CS4500_ASSERT_TRUE(i->as_float() == nullptr);
    CS4500_ASSERT_TRUE(i->as_string() == nullptr);
    delete i;
    delete i_;
    exit(0);
}

TEST(t2, Bool5)
{
    CS4500_ASSERT_EXIT_ZERO(testBoolColumnAsType5);
}

/**
 * @brief Testing if empty/nonempty BoolColumn returns the expected char representing its type
 * 
 */
void testBoolColumnGetType6()
{
    // checking empty column
    Column *i_ = new BoolColumn();
    CS4500_ASSERT_TRUE(i_->get_type() == 'B');
    // checking nonempty column
    BoolColumn *i = new BoolColumn(18, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false, true, false);
    CS4500_ASSERT_TRUE(i->get_type() == 'B');
    delete i;
    delete i_;
    exit(0);
}

TEST(t2, Bool6)
{
    CS4500_ASSERT_EXIT_ZERO(testBoolColumnGetType6);
}

/**
 * @brief Tests the clone method for an BoolColumn. Because Columns have pointer equality, to see if clone is correct, we test to see if each element is the same. 
 * Additionally, because a clone should not directly pointer at something the Column owns, the original Column is deleted and then the values in the clone are checked
 * again.
 * 
 */
void testBoolColumnClone7()
{
    // create and populate BoolCol
    BoolColumn *i = new BoolColumn();
    for (size_t j = 0; j < 10000; j++)
    {
        i->push_back((j % 2 == 1));
    }
    BoolColumn *i_ = i->clone();
    CS4500_ASSERT_TRUE(i->size() == i_->size());
    // check manually if each element is the same
    for (size_t j = 0; j < i->size(); j++)
    {
        CS4500_ASSERT_TRUE(i->get(j) == i_->get(j));
    }
    delete i;
    // check that the clone retains information/elements after original is deleted
    for (size_t j = 0; j < 10000; j++)
    {
        CS4500_ASSERT_TRUE(i_->get(j) == (j % 2 == 1));
    }
    delete i_;
    exit(0);
}

TEST(t2, Bool7)
{
    CS4500_ASSERT_EXIT_ZERO(testBoolColumnClone7);
}

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

TEST(t2, Float1)
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

TEST(t2, Float2)
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
        CS4500_ASSERT_TRUE((i->get(j + 17) - expected) < 0.001);
        CS4500_ASSERT_TRUE((i->get(j + 17) - expected) > -0.001);
    }
    // check that the beginning is unchanged by pushback
    for (size_t j = 0; j < 17; j++)
    {
        float expected = float(j) + 1.22;
        CS4500_ASSERT_TRUE((i->get(j) - expected) < 0.001);
        CS4500_ASSERT_TRUE((i->get(j) - expected) > -0.001);
    }
    delete i;

    exit(0);
}

TEST(t2, Float3)
{
    CS4500_ASSERT_EXIT_ZERO(testFloatColumnPushBack3);
}

/**
 * @brief Testing that size works as expected for empty and nonempty Columns including after we add new elements via push_back() function
 * 
 */
void testFloatColumnSize4()
{
    // checking empty column
    FloatColumn *i_ = new FloatColumn();
    CS4500_ASSERT_TRUE(i_->size() == 0);
    // adding to empty column and checking to see if size is as expected after each add and at the end
    for (size_t j = 0; j < 10000000; j++)
    {
        i_->push_back(2.22);
        CS4500_ASSERT_TRUE(i_->size() == (j + 1));
    }
    CS4500_ASSERT_TRUE(i_->size() == 10000000);
    delete i_;
    // checking nonempty column
    FloatColumn *i = new FloatColumn(17, 1.22, 2.22, 3.22, 4.22, 5.22, 6.22, 7.22, 8.22, 9.22, 10.22, 11.22, 12.22, 13.22, 14.22, 15.22, 16.22, 17.22);
    CS4500_ASSERT_TRUE(i->size() == 17);
    // adding to nonempty column and checking to see if size is as expected after each add and at the end
    for (size_t j = 0; j < 10000000; j++)
    {
        i->push_back(2.22);
        CS4500_ASSERT_TRUE(i->size() == (j + 18));
    }
    //CS4500_ASSERT_TRUE(i->size() == 10000017);
    delete i;
    exit(0);
}

TEST(t2, Float4)
{
    CS4500_ASSERT_EXIT_ZERO(testFloatColumnSize4);
}

/**
 * @brief Testing if empty/nonempty FloatColumn returns the expected poFloater
 * 
 */
void testFloatColumnAsType5()
{
    // checking empty column
    FloatColumn *i_ = new FloatColumn();
    CS4500_ASSERT_TRUE(i_ == i_->as_float());
    CS4500_ASSERT_TRUE(i_->as_bool() == nullptr);
    CS4500_ASSERT_TRUE(i_->as_int() == nullptr);
    CS4500_ASSERT_TRUE(i_->as_string() == nullptr);
    // checking nonempty column
    FloatColumn *i = new FloatColumn(17, 1.22, 2.22, 3.22, 4.22, 5.22, 6.22, 7.22, 8.22, 9.22, 10.22, 11.22, 12.22, 13.22, 14.22, 15.22, 16.22, 17.22);
    CS4500_ASSERT_TRUE(i == i->as_float());
    CS4500_ASSERT_TRUE(i->as_bool() == nullptr);
    CS4500_ASSERT_TRUE(i->as_int() == nullptr);
    CS4500_ASSERT_TRUE(i->as_string() == nullptr);
    delete i;
    delete i_;
    exit(0);
}

TEST(t2, Float5)
{
    CS4500_ASSERT_EXIT_ZERO(testFloatColumnAsType5);
}

/**
 * @brief Testing if empty/nonempty FloatColumn returns the expected char representing its type
 * 
 */
void testFloatColumnGetType6()
{
    // checking empty column
    Column *i_ = new FloatColumn();
    CS4500_ASSERT_TRUE(i_->get_type() == 'F');
    // checking nonempty column
    FloatColumn *i = new FloatColumn(17, 1.22, 2.22, 3.22, 4.22, 5.22, 6.22, 7.22, 8.22, 9.22, 10.22, 11.22, 12.22, 13.22, 14.22, 15.22, 16.22, 17.22);
    CS4500_ASSERT_TRUE(i->get_type() == 'F');
    delete i;
    delete i_;
    exit(0);
}

TEST(t2, Float6)
{
    CS4500_ASSERT_EXIT_ZERO(testFloatColumnGetType6);
}

/**
 * @brief Tests the clone method for an FloatColumn. Because Columns have pointer equality, to see if clone is correct, we test to see if each element is the same. 
 * Additionally, because a clone should not directly pointer at something the Column owns, the original Column is deleted and then the values in the clone are checked
 * again.
 * 
 */
void testFloatColumnClone7()
{
    // create and populate FloatCol
    FloatColumn *i = new FloatColumn();
    for (size_t j = 0; j < 10000; j++)
    {
        i->push_back(j + 2.345);
    }
    FloatColumn *i_ = i->clone();
    CS4500_ASSERT_TRUE(i->size() == i_->size());
    // check manually if each element is the same
    for (size_t j = 0; j < i->size(); j++)
    {
        CS4500_ASSERT_TRUE(i->get(j) - i_->get(j) < 0.001);
        CS4500_ASSERT_TRUE(i->get(j) - i_->get(j) > -0.001);
    }
    delete i;
    // check that the clone retains information/elements after original is deleted
    for (size_t j = 0; j < 10000; j++)
    {
        float expected = j + 2.345;
        CS4500_ASSERT_TRUE(i_->get(j) - expected < 0.001);
        CS4500_ASSERT_TRUE(i_->get(j) - expected > -0.001);
    }
    delete i_;
    exit(0);
}

TEST(t2, Float7)
{
    CS4500_ASSERT_EXIT_ZERO(testFloatColumnClone7);
}

/**
 * @brief Checking to see if we can accurately get the elements from an StringColumn
 * 
 */
void testStringColumnGet1()
{
    String *s1 = new String("h");
    String *s2 = new String("e");
    String *s3 = new String("l");
    String *s4 = new String("l");
    String *s5 = new String("o");
    String *s6 = new String("w");
    String *s7 = new String("o");
    String *s8 = new String("r");
    String *s9 = new String("l");
    String *s10 = new String("d");
    String *s11 = new String("r");
    String *s12 = new String("e");
    String *s13 = new String("j");
    String *s14 = new String("e");
    String *s15 = new String("c");
    String *s16 = new String("t");
    String *s17 = new String("s");
    String *all = new String("helloworldrejects");
    StringColumn *i = new StringColumn(17, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15, s16, s17);
    for (size_t j = 0; j < 17; j++)
    {
        char *c = new char(all->at(j));
        String *expected_ = new String(c);
        CS4500_ASSERT_TRUE(i->get(j)->equals(expected_));
        delete expected_;
        delete c;
    }
    delete i;
    delete all;
    exit(0);
}

TEST(t2, String1)
{
    CS4500_ASSERT_EXIT_ZERO(testStringColumnGet1);
}

/**
 * @brief Testing set function via setting the values then getting them to check if we set the value correctly as each location.
 * 
 */
void testStringColumnSet2()
{
    String *s1 = new String("h");
    String *s2 = new String("e");
    String *s3 = new String("l");
    String *s4 = new String("l");
    String *s5 = new String("o");
    String *s6 = new String("w");
    String *s7 = new String("o");
    String *s8 = new String("r");
    String *s9 = new String("l");
    String *s10 = new String("d");
    String *s11 = new String("r");
    String *s12 = new String("e");
    String *s13 = new String("j");
    String *s14 = new String("e");
    String *s15 = new String("c");
    String *s16 = new String("t");
    String *s17 = new String("s");
    String *all = new String("helloworldrejects");
    String *new_ = new String("blah");
    String *all2 = new String("blahhityblahhityblah");
    StringColumn *i = new StringColumn(17, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15, s16, s17);
    // set 1 value in i to something else and check if that one value changed correctly
    i->set(8, new String("blah"));
    CS4500_ASSERT_TRUE(i->get(8)->equals(new_));
    // set all values in i to something else and check
    for (size_t j = 0; j < 17; j++)
    {
        char *c = new char(all2->at(j));
        String *expected_ = new String(c);
        i->set(j, expected_->clone());
        delete c;
        delete expected_;
    }
    for (size_t j = 0; j < 17; j++)
    {
        char *c = new char(all2->at(j));
        String *expected_ = new String(c);
        CS4500_ASSERT_TRUE(i->get(j)->equals(expected_));
        delete c;
        delete expected_;
    }
    delete i;
    delete all;
    delete all2;
    delete new_;
    exit(0);
}

TEST(t2, String2)
{
    CS4500_ASSERT_EXIT_ZERO(testStringColumnSet2);
}

/**
 * @brief Testing that push_back() function works as expected for empty and nonempty Columns. Check after each push back that the added element is
 * where and what is expected.
 * 
 */
void testStringColumnPushBack3()
{
    String *all = new String("blahhityblahhityblah");
    size_t size_ = all->size();
    // checking empty column
    StringColumn *i_ = new StringColumn();
    // adding to empty column and checking to see if added element is where and what we expect
    for (size_t j = 0; j < 10000000; j++)
    {
        char *c = new char(all->at(j % size_));
        String *expected = new String(c);
        i_->push_back(expected->clone());
        CS4500_ASSERT_TRUE(i_->get(j)->equals(expected));
        delete c;
        delete expected;
    }
    delete i_;
    // checking nonempty array
    String *s1 = new String("h");
    String *s2 = new String("e");
    String *s3 = new String("l");
    String *s4 = new String("l");
    String *s5 = new String("o");
    String *s6 = new String("w");
    String *s7 = new String("o");
    String *s8 = new String("r");
    String *s9 = new String("l");
    String *s10 = new String("d");
    String *s11 = new String("r");
    String *s12 = new String("e");
    String *s13 = new String("j");
    String *s14 = new String("e");
    String *s15 = new String("c");
    String *s16 = new String("t");
    String *s17 = new String("s");
    String *all2 = new String("helloworldrejects");
    StringColumn *i = new StringColumn(17, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15, s16, s17);
    for (size_t j = 0; j < 10000; j++)
    {
        char *c = new char(all->at(j % size_));
        String *expected = new String(c);
        i->push_back(expected->clone());
        CS4500_ASSERT_TRUE(i->size() == j + 18);
        CS4500_ASSERT_TRUE(i->get(j + 17)->equals(expected));
    }
    // check that the beginning is unchanged by pushback
    for (size_t j = 0; j < 17; j++)
    {
        char *c = new char(all2->at(j));
        String *expected = new String(c);
        CS4500_ASSERT_TRUE(i->get(j)->equals(expected));
        delete c;
        delete expected;
    }
    delete i;
    delete all;
    delete all2;
    exit(0);
}

TEST(t2, String3)
{
    CS4500_ASSERT_EXIT_ZERO(testStringColumnPushBack3);
}

/**
 * @brief Testing that size works as expected for empty and nonempty Columns including after we add new elements via push_back() function
 * 
 */
void testStringColumnSize4()
{
    // checking empty column
    StringColumn *i_ = new StringColumn();
    CS4500_ASSERT_TRUE(i_->size() == 0);
    // adding to empty column and checking to see if size is as expected after each add and at the end
    for (size_t j = 0; j < 10000000; j++)
    {
        i_->push_back(new String("h"));
        CS4500_ASSERT_TRUE(i_->size() == (j + 1));
    }
    CS4500_ASSERT_TRUE(i_->size() == 10000000);
    delete i_;
    // checking nonempty column
    String *s1 = new String("h");
    String *s2 = new String("e");
    String *s3 = new String("l");
    String *s4 = new String("l");
    String *s5 = new String("o");
    String *s6 = new String("w");
    String *s7 = new String("o");
    String *s8 = new String("r");
    String *s9 = new String("l");
    String *s10 = new String("d");
    String *s11 = new String("r");
    String *s12 = new String("e");
    String *s13 = new String("j");
    String *s14 = new String("e");
    String *s15 = new String("c");
    String *s16 = new String("t");
    String *s17 = new String("s");
    StringColumn *i = new StringColumn(17, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15, s16, s17);
    CS4500_ASSERT_TRUE(i->size() == 17);
    // adding to nonempty column and checking to see if size is as expected after each add and at the end
    for (size_t j = 0; j < 10000000; j++)
    {
        i->push_back(new String("h"));
        CS4500_ASSERT_TRUE(i->size() == (j + 18));
    }
    CS4500_ASSERT_TRUE(i->size() == 10000017);
    delete i;
    exit(0);
}

TEST(t2, String4)
{
    CS4500_ASSERT_EXIT_ZERO(testStringColumnSize4);
}

/**
 * @brief Testing if empty/nonempty StringColumn returns the expected pointer
 * 
 */
void testStringColumnAsType5()
{
    // checking empty column
    StringColumn *i_ = new StringColumn();
    CS4500_ASSERT_TRUE(i_ == i_->as_string());
    CS4500_ASSERT_TRUE(i_->as_bool() == nullptr);
    CS4500_ASSERT_TRUE(i_->as_int() == nullptr);
    CS4500_ASSERT_TRUE(i_->as_float() == nullptr);
    // checking nonempty column
    String *s1 = new String("h");
    String *s2 = new String("e");
    String *s3 = new String("l");
    String *s4 = new String("l");
    String *s5 = new String("o");
    String *s6 = new String("w");
    String *s7 = new String("o");
    String *s8 = new String("r");
    String *s9 = new String("l");
    String *s10 = new String("d");
    String *s11 = new String("r");
    String *s12 = new String("e");
    String *s13 = new String("j");
    String *s14 = new String("e");
    String *s15 = new String("c");
    String *s16 = new String("t");
    String *s17 = new String("s");
    StringColumn *i = new StringColumn(17, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15, s16, s17);
    CS4500_ASSERT_TRUE(i == i->as_string());
    CS4500_ASSERT_TRUE(i->as_bool() == nullptr);
    CS4500_ASSERT_TRUE(i->as_int() == nullptr);
    CS4500_ASSERT_TRUE(i->as_float() == nullptr);
    delete i;
    delete i_;
    exit(0);
}

TEST(t2, String5)
{
    CS4500_ASSERT_EXIT_ZERO(testStringColumnAsType5);
}

/**
 * @brief Testing if empty/nonempty StringColumn returns the expected char representing its type
 * 
 */
void testStringColumnGetType6()
{
    // checking empty column
    Column *i_ = new StringColumn();
    CS4500_ASSERT_TRUE(i_->get_type() == 'S');
    // checking nonempty column
    String *s1 = new String("h");
    String *s2 = new String("e");
    String *s3 = new String("l");
    String *s4 = new String("l");
    String *s5 = new String("o");
    String *s6 = new String("w");
    String *s7 = new String("o");
    String *s8 = new String("r");
    String *s9 = new String("l");
    String *s10 = new String("d");
    String *s11 = new String("r");
    String *s12 = new String("e");
    String *s13 = new String("j");
    String *s14 = new String("e");
    String *s15 = new String("c");
    String *s16 = new String("t");
    String *s17 = new String("s");
    StringColumn *i = new StringColumn(17, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15, s16, s17);
    CS4500_ASSERT_TRUE(i->get_type() == 'S');
    delete i;
    delete i_;
    exit(0);
}

TEST(t2, String6)
{
    CS4500_ASSERT_EXIT_ZERO(testStringColumnGetType6);
}

/**
 * @brief Tests the clone method for an StringColumn. Because Columns have pointer equality, to see if clone is correct, we test to see if each element is the same. 
 * Additionally, because a clone should not directly pointer at something the Column owns, the original Column is deleted and then the values in the clone are checked
 * again.
 * 
 */
void testStringColumnClone7()
{
    // create and populate StringCol
    String *all = new String("blahhityblahhityblah");
    size_t size_ = all->size();
    StringColumn *i = new StringColumn();
    for (size_t j = 0; j < 10000; j++)
    {
        char *c = new char(all->at(j % size_));
        String *expected = new String(c);
        i->push_back(expected->clone());
        delete c;
        delete expected;
    }
    StringColumn *i_ = i->clone();
    CS4500_ASSERT_TRUE(i->size() == i_->size());
    // check manually if each element is the same
    for (size_t j = 0; j < i->size(); j++)
    {
        CS4500_ASSERT_TRUE(i->get(j)->equals(i_->get(j)));
    }
    delete i;
    // check that the clone retains information/elements after original is deleted
    for (size_t j = 0; j < 10000; j++)
    {
        char *c = new char(all->at(j % size_));
        String *expected = new String(c);
        CS4500_ASSERT_TRUE(i_->get(j)->equals(expected));
        delete c;
        delete expected;
    }
    delete i_;
    delete all;
    exit(0);
}

TEST(t2, String7)
{
    CS4500_ASSERT_EXIT_ZERO(testStringColumnClone7);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}