#include "../cpp/src/main.h"
#include <gtest/gtest.h>
#include <vector>
#include <utility>

TEST(CubeCountTest, SampleTest1)
{
    int N = 3;
    std::vector<int> r = {2, 3, 1};
    std::vector<int> c = {3, 1, 3};
    std::pair<int, int> result = computeCubeCounts(N, r, c);
    EXPECT_EQ(result.first, 14);
    EXPECT_EQ(result.second, 15);
}

TEST(CubeCountTest, SampleTest2)
{
    int N = 4;
    std::vector<int> r = {5, 5, 5, 5};
    std::vector<int> c = {5, 5, 5, 5};
    std::pair<int, int> result = computeCubeCounts(N, r, c);
    EXPECT_EQ(result.first, 32);
    EXPECT_EQ(result.second, 80);
}

TEST(CubeCountTest, AllOnes)
{
    int N = 3;
    std::vector<int> r = {1, 1, 1};
    std::vector<int> c = {1, 1, 1};
    std::pair<int, int> result = computeCubeCounts(N, r, c);
    EXPECT_EQ(result.first, 9);
    EXPECT_EQ(result.second, 9);
}

TEST(CubeCountTest, AllTwos)
{
    int N = 3;
    std::vector<int> r = {2, 2, 2};
    std::vector<int> c = {2, 2, 2};
    std::pair<int, int> result = computeCubeCounts(N, r, c);
    EXPECT_EQ(result.first, 12);
    EXPECT_EQ(result.second, 18);
}

TEST(CubeCountTest, Asymmetric)
{
    int N = 4;
    std::vector<int> r = {1, 2, 3, 4};
    std::vector<int> c = {4, 3, 2, 1};
    std::pair<int, int> result = computeCubeCounts(N, r, c);

    int baseline = N * N;
    EXPECT_GE(result.first, baseline);
    EXPECT_GE(result.second, baseline);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}