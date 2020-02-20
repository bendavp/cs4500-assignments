#include <gtest/gtest.h>
#include "modified_dataframe.h"

#define GT_TRUE(a) ASSERT_EQ((a), true)
#define GT_FALSE(a) ASSERT_EQ((a), false)
#define GT_EQUALS(a, b) ASSERT_EQ(a, b)
#define ASSERT_EXIT_ZERO(a) \
    ASSERT_EXIT(a(), ::testing::ExitedWithCode(0), ".*")

Schema scm("IFBII"); // the schema
DataFrame df(scm);   // the data frame

class IntAdder : public Object
{
public:
    size_t row_num_;
    int row_total = 0;
    /** Called before visiting a row, the argument is the row offset in the
    dataframe. */
    virtual void start(size_t r)
    {
        row_num_ = r;
    }

    /** Called for fields of the argument's type with the value of the field. */
    virtual void accept(bool b)
    {
        // do nothing
    }
    virtual void accept(float f)
    {
        // do nothing
    }
    virtual void accept(int i)
    {
        row_total += i;
    }
    virtual void accept(String *s)
    {
        // do nothing
    }

    /** Called when all fields have been seen. */
    virtual void done()
    {
        // do nothing
    }
};

class AddAllInts : public Rower
{
public:
    int total = 0;

    bool accept(Row &r)
    {
        IntAdder i = IntAdder();
        total = i.row_total;
        return true;
    }

    void join_delete(Rower *other)
    {
        AddAllInts *r = static_cast<AddAllInts *>(other);
        total += r->total;
        delete r;
        delete other;
    }

    Rower *clone()
    {
        return new AddAllInts();
    }
};

DataFrame *init()
{
    IntColumn *i_ = new IntColumn();
    for (size_t j = 0; j < 10000000; j++)
    {
        i_->push_back(j);
    }

    Schema *s = new Schema();
    DataFrame *df = new DataFrame(*s);
    for (int i = 0; i < 100; i++)
    {
        df->add_column(i_, StrBuff().c(i).get());
    }
}

void testPmapSmallDf()
{
    DataFrame *df = init();
    Rower rower_ = AddAllInts();
    df->pmap(rower_);

    exit(0);
}

TEST(a41, t1) { ASSERT_EXIT_ZERO(testPmapSmallDf); }

void testMapSmallDf()
{
    DataFrame *df = init();
    Rower rower_ = AddAllInts();
    df->map(rower_);

    exit(0);
}

TEST(a41, t2) { ASSERT_EXIT_ZERO(testMapSmallDf); }

void testPmapLargeDf()
{
    DataFrame *df = init();
    Rower rower_ = AddAllInts();
    df->pmap(rower_);

    exit(0);
}

TEST(a41, t3) { ASSERT_EXIT_ZERO(testPmapLargeDf); }

void testMapLargeDf()
{
    DataFrame *df = init();
    Rower rower_ = AddAllInts();
    df->map(rower_);

    exit(0);
}

TEST(a41, t4) { ASSERT_EXIT_ZERO(testPmapSmallDf); }

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
