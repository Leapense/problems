#include <iostream>
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>
using namespace std;

int minCakes(int N) {
    const int INF = 1e9;
    vector<int> dp(N + 1, INF);

    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int k = 1; k * k <= i; k++) {
            dp[i] = min(dp[i], dp[i - k * k] + 1);
        }
    }

    return dp[N];
}

TEST(MinCakesTest, SampleTests) {
    EXPECT_EQ(minCakes(3), 3);
    EXPECT_EQ(minCakes(4), 1);
    EXPECT_EQ(minCakes(5), 2);
}

TEST(MinCakesTest, AdditionalTests) {
    EXPECT_EQ(minCakes(1), 1);
    EXPECT_EQ(minCakes(2), 2);
    EXPECT_EQ(minCakes(6), 3);
    EXPECT_EQ(minCakes(12), 3);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
