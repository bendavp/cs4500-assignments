#include <gtest/gtest.h>
#include "modified_dataframe.h"

#define GT_TRUE(a) ASSERT_EQ((a), true)
#define GT_FALSE(a) ASSERT_EQ((a), false)
#define GT_EQUALS(a, b) ASSERT_EQ(a, b)
#define ASSERT_EXIT_ZERO(a) \
    ASSERT_EXIT(a(), ::testing::ExitedWithCode(0), ".*")

Schema scm("IFBII"); // the schema
DataFrame df(scm);   // the data frame

class Taxes : public Rower
{
public:
    DataFrame *df_;
    Taxes(DataFrame *df) : df_(df) {}
    size_t salary = 0, rate = 1, isded = 2, ded = 3, taxes = 4; // these are for convenience
    bool accept(Row &r)
    {
        int tx = (int)r.get_int(salary) * r.get_float(rate);
        tx -= r.get_bool(isded) ? r.get_int(ded) : 0;
        df.set(taxes, r.get_idx(), tx);
        return true;
    }
};

void test()
{

    exit(0);
}

TEST(a4, t1) { ASSERT_EXIT_ZERO(test); }

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
