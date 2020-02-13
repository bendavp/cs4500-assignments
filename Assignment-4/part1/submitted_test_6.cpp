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
    std::cout << s->coltypes_->get()->c_str() << '\n';
    GT_TRUE(s->coltypes_->get()->equals(s_str));
    std::cout << "here" << '\n';
    s->add_column('S', new String("Lies"));
    GT_EQUALS(s->width(), 5);
    std::cout << "here" << '\n';
    GT_TRUE(s->coltypes_->get()->equals(new String("FIBSS")));
    std::cout << "here" << '\n';

    exit(0);
}

TEST(a4, schema1) { ASSERT_EXIT_ZERO(testAddColumn); }

/**
 * @brief Runs all Google Tests in this file
 */
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}