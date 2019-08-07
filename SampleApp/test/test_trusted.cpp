#include "gtest/gtest.h"
#include "../App/Enclave_u.h"

extern int wrapped_trusted_sum(int a, int b);
extern uint64_t global_eid;

TEST(TestTrusted, WrappedTrustedSum)
{
    int a = 2;
    int b = 3;
    int expected_sum = 5;
    int given_sum = wrapped_trusted_sum(a, b);
    EXPECT_EQ(given_sum, expected_sum);
}

TEST(TestTrusted, EcallTrustedSum)
{
    int a = 2;
    int b = 3;
    int given_sum = 0;
    int expected_sum = 5;
    trusted_sum(global_eid, &given_sum, a, b);
    EXPECT_EQ(given_sum, expected_sum);
}

TEST(TestTrusted, EcallCallingAnotherFunc)
{
    int given_number = 0;
    int expected_number = 69; // This number is hard coded in Enclave.cpp
    ecall_that_calls_another_function(global_eid, &given_number);
    EXPECT_EQ(given_number, expected_number);
}

TEST(TestTrusted, EnclavePrivateFunction)
{
    int initial_value = 0;
    int expected_value = 1;
    int given_value = 0;
    private_increment_inside_enclave(global_eid, &given_value, initial_value);
    EXPECT_EQ(given_value, expected_value);
}