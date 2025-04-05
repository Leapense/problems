#include <iostream>
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>
using namespace std;

int max_decorated_buildings(const vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;
    vector<int> dp(n, 1);
    int max_length = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (height[j] < height[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        max_length = max(max_length, dp[i]);
    }

    return max_length;
}

TEST(BuildingTest, SampleTest1) {
    vector<int> heights = {3, 7, 5, 9, 8, 10, 10, 11, 9};
    EXPECT_EQ(max_decorated_buildings(heights), 5);
}

TEST(BuildingTest, SingleBuilding) {
    vector<int> heights = {100};
    EXPECT_EQ(max_decorated_buildings(heights), 1);
}

TEST(BuildingTest, AllIncreasing) {
    vector<int> heights = {1, 2, 3, 4, 5};
    EXPECT_EQ(max_decorated_buildings(heights), 5);
}

TEST(BuildingTest, AllSame) {
    vector<int> heights = {2, 2, 2, 2, 2};
    EXPECT_EQ(max_decorated_buildings(heights), 1);
}

TEST(BuildingTest, RandomCase) {
    vector<int> heights = {4, 2, 3, 1, 5, 6};
    EXPECT_EQ(max_decorated_buildings(heights), 4);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
