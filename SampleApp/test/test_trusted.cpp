#include "gtest/gtest.h"

extern int wrapped_trusted_sum(int a, int b);

TEST(TestTrusted, WrappedTrustedSum)
{
    int a = 2;
    int b = 3;
    int expected_sum = 5;
    int given_sum = wrapped_trusted_sum(a, b);
    EXPECT_EQ(given_sum, expected_sum);
}
