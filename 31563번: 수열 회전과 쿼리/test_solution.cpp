#define UNIT_TEST
#include "solution.cpp"

#include <gtest/gtest.h>

TEST(Sample, Provided)
{
    int N = 7;
    std::vector<long long> A = {3, 2, 1, 5, 10, 6, 2};
    std::vector<std::tuple<int, long long, long long>> qs = {
        {3, 1, 3},
        {2, 1, 0},
        {3, 1, 3},
        {1, 3, 0},
        {3, 2, 6}};

    std::vector<long long> expect = {6, 8, 13};
    EXPECT_EQ(processQueries(N, A, qs), expect);
}

TEST(Edge, FullRotation)
{
    int N = 4;
    std::vector<long long> A = {1, 2, 3, 4};
    std::vector<std::tuple<int, long long, long long>> qs = {
        {1, 4, 0},
        {3, 1, 4}};

    EXPECT_EQ(processQueries(N, A, qs), std::vector<long long>{10});
}

TEST(Edge, WrapQuery)
{
    int N = 5;
    std::vector<long long> A = {10, 20, 30, 40, 50};
    std::vector<std::tuple<int, long long, long long>> qs = {
        {2, 2, 0},
        {3, 4, 5}};
    EXPECT_EQ(processQueries(N, A, qs), std::vector<long long>{30});
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}