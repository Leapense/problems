#include "gtest/gtest.h"
#include "../cpp/src/main.h"
#include <vector>
#include <cmath>

using namespace std;

bool isValidOrdering(const vector<int> &order)
{
    int n = order.size();
    for (int i = 1; i < n - 1; i++)
    {
        int diff1 = abs(order[i] - order[i - 1]);
        int diff2 = abs(order[i + 1] - order[i]);
        if (diff1 > diff2)
            return false;
    }

    return true;
}

TEST(HotSpringsTest, SampleTest1)
{
    vector<int> temps = {1, 3, 4};
    vector<int> order = rearrangePools(temps);
    EXPECT_TRUE(isValidOrdering(order));
}

TEST(HotSpringsTest, SampleTest2)
{
    vector<int> temps = {0, 0, 1, -1, -6, 3};
    vector<int> order = rearrangePools(temps);
    EXPECT_TRUE(isValidOrdering(order));
}

TEST(HotSpringsTest, AllSame)
{
    vector<int> temp = {5, 5, 5, 5};
    vector<int> order = rearrangePools(temp);
    EXPECT_TRUE(isValidOrdering(order));
}

TEST(HotSpringsTest, TwoElements)
{
    vector<int> temp = {10, -10};
    vector<int> order = rearrangePools(temp);
    EXPECT_TRUE(isValidOrdering(order));
}

TEST(HotSpringsTest, IncreasingOrder)
{
    vector<int> temps = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> order = rearrangePools(temps);
    EXPECT_TRUE(isValidOrdering(order));
}

TEST(HotSpringsTest, DecreasingOrder)
{
    vector<int> temps = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> order = rearrangePools(temps);
    EXPECT_TRUE(isValidOrdering(order));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}