#include "gtest/gtest.h"

extern int untrusted_sum(int a, int b);

TEST(TestUntrusted, UntrustedSum)
{
    int a = 2;
    int b = 3;
    int expected_sum = 5;
    int given_sum = untrusted_sum(a, b);
    EXPECT_EQ(given_sum, expected_sum);
}
