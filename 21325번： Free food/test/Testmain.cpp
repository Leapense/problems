#include <gtest/gtest.h>
#include "../cpp/src/main.h"
#include <vector>
using namespace std;
TEST(FreeFoodTest, SampleTest1)
{
    int N = 5, M = 3;
    vector<int> bosses = {5, 5, 4, 1, 0};
    vector<int> table = {1, 2, 3};
    int expected = 2;
    EXPECT_EQ(solve(N, M, bosses, table), expected);
}
TEST(FreeFoodTest, SampleTest2)
{
    int N = 6, M = 5;
    vector<int> bosses = {5, 4, 4, 5, 0, 1};
    vector<int> table = {5, 1, 3, 2, 4};
    int expected = 1;
    EXPECT_EQ(solve(N, M, bosses, table), expected);
}
TEST(FreeFoodTest, OnlyCEOAtTable)
{
    int N = 4, M = 1;
    vector<int> bosses = {0, 1, 1, 2};
    vector<int> table = {1};
    int expected = 1;
    EXPECT_EQ(solve(N, M, bosses, table), expected);
}
TEST(FreeFoodTest, NoEligible)
{
    int N = 4, M = 4;
    vector<int> bosses = {0, 1, 2, 3};
    vector<int> table = {1, 2, 3, 4};
    int expected = 1;
    EXPECT_EQ(solve(N, M, bosses, table), expected);
}
TEST(FreeFoodTest, StarStructure)
{
    int N = 5, M = 5;
    vector<int> bosses = {0, 1, 1, 1, 1};
    vector<int> table = {1, 2, 3, 4, 5};
    int expected = 1;
    EXPECT_EQ(solve(N, M, bosses, table), expected);
}
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}