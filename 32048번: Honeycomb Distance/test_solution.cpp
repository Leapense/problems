#include <gtest/gtest.h>
#include <bits/stdc++.h>

using namespace std;

int hexDistance(int x, int y)
{
    int X = x;
    int Z = y;
    int Y = -X - Z;
    return max({abs(X), abs(Y), abs(Z)});
}

TEST(HoneycombDistance, Origin)
{
    EXPECT_EQ(hexDistance(0, 0), 0);
}

TEST(HoneycombDistance, BasicNeighbors)
{
    EXPECT_EQ(hexDistance(1, 0), 1);
    EXPECT_EQ(hexDistance(0, 1), 1);
    EXPECT_EQ(hexDistance(-1, 1), 1);
    EXPECT_EQ(hexDistance(-1, 0), 1);
    EXPECT_EQ(hexDistance(0, -1), 1);
    EXPECT_EQ(hexDistance(1, -1), 1);
}

TEST(HoneycombDistance, SampleBatch)
{
    vector<pair<int, int>> inputs = {
        {0, 0}, {0, 1}, {1, 0}, {2, 1}, {2, -1}, {-3, 2}, {-1, -3}};
    vector<int> expecteds = {0, 1, 1, 3, 2, 3, 4};
    for (size_t i = 0; i < inputs.size(); i++)
    {
        EXPECT_EQ(hexDistance(inputs[i].first, inputs[i].second), expecteds[i]) << "Failed at index " << i;
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}