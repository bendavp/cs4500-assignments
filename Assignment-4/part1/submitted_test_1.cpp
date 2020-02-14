#include <gtest/gtest.h>
#include "dataframe.h"

#define CS4500_ASSERT_TRUE(a) \
    ASSERT_EQ((a), true);
#define CS4500_ASSERT_FALSE(a) \
    ASSERT_EQ((a), false);
#define CS4500_ASSERT_EXIT_ZERO(a) \
    ASSERT_EXIT(a(), ::testing::ExitedWithCode(0), ".*");

/**
 * @brief Runs all Google Tests in this file
 */
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}