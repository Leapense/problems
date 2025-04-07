#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include "gtest/gtest.h"

using namespace std;

long long computeCongestion(const vector<long long> &A)
{
    int N = A.size();
    long long total = 0;
    for (int i = 0; i < N; i++)
    {
        total += A[i];
    }

    long long T = total / N;
    long long congestion = 0;
    long long prefixDiff = 0;

    for (int i = 0; i < N - 1; i++)
    {
        prefixDiff += (A[i] - T);
        congestion += std::abs(prefixDiff);
    }

    return congestion;
}

#ifndef UNIT_TEST
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    cout << computeCongestion(A) << "\n";
    return 0;
}
#endif

#ifdef UNIT_TEST
TEST(KitDistributionTest, Sample1)
{
    vector<long long> A = {1, 3, 2};
    long long expected = 1;
    EXPECT_EQ(computeCongestion(A), expected);
}

TEST(KitDistributionTest, Sample2)
{
    vector<long long> A = {2, 6, 3, 2, 5, 4, 6};
    long long expected = 10;
    EXPECT_EQ(computeCongestion(A), expected);
}

TEST(KitDistributionTest, AllEqual)
{
    vector<long long> A = {5, 5, 5, 5, 5};
    long long expected = 0;
    EXPECT_EQ(computeCongestion(A), expected);
}

TEST(KitDistributionTest, SingleRoom)
{
    vector<long long> A = {42};
    long long expected = 0;
    EXPECT_EQ(computeCongestion(A), expected);
}

TEST(KitDistributionTest, CustomTest)
{
    vector<long long> A = {4, 1, 7, 3};
    long long expected = 5;
    EXPECT_EQ(computeCongestion(A), expected);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif