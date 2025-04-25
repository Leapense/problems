#include <gtest/gtest.h>
#include <vector>
#include <string>
using namespace std;

static string winner(const vector<long long> &a)
{
    long long evenCnt = 0, prev = 0;
    for (auto v : a)
    {
        if (((v - prev) & 1) == 0)
            ++evenCnt;
        prev = v;
    }
    return (evenCnt & 1) ? "First" : "Second";
}

TEST(Sample, FiveNumbers)
{
    vector<long long> a = {1, 2, 3, 4, 5};
    EXPECT_EQ(winner(a), "Second");
}

TEST(Sample, SingleEvenGap)
{
    vector<long long> a = {100};
    EXPECT_EQ(winner(a), "First");
}

TEST(Edge, SingleOddGap)
{
    vector<long long> a = {3};
    EXPECT_EQ(winner(a), "Second");
}

TEST(Random, Mixed)
{
    vector<long long> a = {2, 5, 9, 10};
    EXPECT_EQ(winner(a), "First");
}