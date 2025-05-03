#define UNIT_TEST
#include "solution.cpp"
#include <gtest/gtest.h>

TEST(SampleTests, Example1)
{
    int N = 4;
    long long K = 2;
    string S = "URLD";
    EXPECT_TRUE(checkReturnToOrigin(N, K, S));
}

TEST(SampleTests, Example2)
{
    int N = 3;
    long long K = 2;
    string S = "URD";
    EXPECT_FALSE(checkReturnToOrigin(N, K, S));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}