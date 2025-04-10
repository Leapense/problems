#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <gtest/gtest.h>

void solve(std::istream &in, std::ostream &out)
{
    int n, k;
    in >> n >> k;

    std::vector<long long> x(n);
    for (int i = 0; i < n; i++)
    {
        in >> x[i];
    }

    const long long INF = 1e18;
    std::vector<long long> dp(n, INF);
    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n && j <= i + k; j++)
        {
            long long jump_cost = std::abs(x[i] - x[j]) + (j - i) * (j - i);
            dp[j] = std::min(dp[j], dp[i] + jump_cost);
        }
    }

    out << dp[n - 1] << "\n";
}

TEST(TowerClimbingTest, Sample1)
{
    std::istringstream iss("4 3\n5\n4\n10\n6\n");
    std::ostringstream oss;
    solve(iss, oss);
    std::string expected = "8\n";
    EXPECT_EQ(oss.str(), expected);
}

TEST(TowerClimbingTest, Sample2)
{
    std::istringstream iss("2 1\n99\n100\n");
    std::ostringstream oss;
    solve(iss, oss);
    std::string expected = "2\n";
    EXPECT_EQ(oss.str(), expected);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}