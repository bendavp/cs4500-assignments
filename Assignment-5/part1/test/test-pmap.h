#include "../dataframe.h"

class IntAdder : public Fielder
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
        int first = 0;
        int second = 1;
        if (i == 0)
        {
            row_total = first;
        }
        else if (i == 2)
        {
            row_total = second;
        }
        else
        {
            int next;
            for (int j = 2; j < i; j++)
            {
                next = first + second;
                first = second;
                second = next;
            }
            row_total = next;
        }
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
        int val1 = r.get_int(0);
        int val2 = r.get_int(1);
        int val3 = r.get_int(2);
        total = calcFib(val1) + calcFib(val2) + calcFib(val3);
        std::cout << calcFib(val1) << "\n";
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

    int calcFib(int i)
    {
        int first = 0;
        int second = 1;
        int total = 0;
        if (i == 0)
        {
            total = first;
        }
        else if (i == 2)
        {
            total = second;
        }
        else
        {
            int next;
            for (int j = 2; j < i; j++)
            {
                next = first + second;
                first = second;
                second = next;
            }
            total = next;
        }
        return total;
    }
};

void testPmapLargeDf()
{
    Schema scm("IIIIIIIIII");           // the schema
    DataFrame *df = new DataFrame(scm); // the data frame

    IntColumn *i_ = new IntColumn();
    for (size_t j = 0; j < 10000000; j++)
    {
        i_->push_back(j);
    }

    for (int i = 0; i < 10; i++)
    {
        df->add_column(i_, StrBuff().c(i).get());
    }

    Rower rower_ = AddAllInts();
    df->pmap(rower_);

    //delete df;

    exit(0);
}

TEST(a40, t2) { ASSERT_EXIT_ZERO(testPmapLargeDf); }

void testMapLargeDf()
{
    Schema scm("IFBII");                // the schema
    DataFrame *df = new DataFrame(scm); // the data frame

    IntColumn *i_ = new IntColumn();
    for (size_t j = 0; j < 10000000; j++)
    {
        i_->push_back(j);
    }

    for (int i = 0; i < 10; i++)
    {
        df->add_column(i_, StrBuff().c(i).get());
    }

    Rower rower_ = AddAllInts();
    df->map(rower_);

    //delete df;

    exit(0);
}

TEST(a41, t2) { ASSERT_EXIT_ZERO(testMapLargeDf); }

void testPmapSmallDf()
{
    Schema scm("IFBII");                // the schema
    DataFrame *df = new DataFrame(scm); // the data frame

    IntColumn *i_ = new IntColumn();
    for (size_t j = 0; j < 10; j++)
    {
        i_->push_back(j);
    }

    for (int i = 0; i < 10; i++)
    {
        df->add_column(i_, StrBuff().c(i).get());
    }

    Rower rower_ = AddAllInts();
    df->pmap(rower_);

    //delete df;

    exit(0);
}

TEST(a41, t3) { ASSERT_EXIT_ZERO(testPmapSmallDf); }

void testMapSmallDf()
{
    Schema scm("IFBII");                // the schema
    DataFrame *df = new DataFrame(scm); // the data frame

    IntColumn *i_ = new IntColumn();
    for (size_t j = 0; j < 10; j++)
    {
        i_->push_back(j);
    }

    for (int i = 0; i < 10; i++)
    {
        df->add_column(i_, StrBuff().c(i).get());
    }

    Rower rower_ = AddAllInts();
    df->map(rower_);

    //delete df;

    exit(0);
}

TEST(a41, t4) { ASSERT_EXIT_ZERO(testMapSmallDf); }
