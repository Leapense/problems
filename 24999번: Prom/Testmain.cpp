#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;

long long countPairs(const vector<int> &girls, const vector<int> &boys, long long k)
{
    vector<int> sorted_girls = girls;
    vector<int> sorted_boys = boys;

    sort(sorted_girls.begin(), sorted_girls.end());
    sort(sorted_boys.begin(), sorted_boys.end());

    long long result = 0;
    for (int h : sorted_girls)
    {
        auto low = lower_bound(sorted_boys.begin(), sorted_boys.end(), h - k);
        auto high = upper_bound(sorted_boys.begin(), sorted_boys.end(), h + k);
        result += high - low;
    }

    return result;
}

TEST(PromProblemTest, SampleInput)
{
    vector<int> girls = {15, 2, 5, 7};
    vector<int> boys = {1, 5, 10, 15, 1};
    long long k = 5;

    EXPECT_EQ(countPairs(girls, boys, k), 11);
}

TEST(PromProblemTest, NoPossiblePairs)
{
    vector<int> girls = {100};
    vector<int> boys = {1, 2, 3};
    long long k = 10;

    EXPECT_EQ(countPairs(girls, boys, k), 0);
}

TEST(PromProblemTest, AllPairsPossible)
{
    vector<int> girls = {10, 20};
    vector<int> boys = {11, 19, 20};
    long long k = 10;

    EXPECT_EQ(countPairs(girls, boys, k), 6);
}

TEST(PromProblemTest, LargeInputPerformance)
{
    const int N = 250000;
    vector<int> girls(N, 500000000);
    vector<int> boys(N, 500000000);
    long long k = 1000000000;

    EXPECT_EQ(countPairs(girls, boys, k), static_cast<long long>(N) * N);
}

TEST(PromProblemTest, EdgeCaseSingleGirlSingleBoy)
{
    vector<int> girls = {5};
    vector<int> boys = {10};
    long long k = 5;

    EXPECT_EQ(countPairs(girls, boys, k), 1);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}