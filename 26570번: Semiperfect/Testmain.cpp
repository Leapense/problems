#include <gtest/gtest.h>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool dfs_semiperfect(const vector<int> &divs, const vector<ll> &suffix, int idx, ll sum, ll target)
{
    if (sum == target)
        return true;
    if (idx >= (int)divs.size())
        return false;
    if (sum + suffix[idx] < target)
        return false;
    if (sum + divs[idx] <= target)
    {
        if (dfs_semiperfect(divs, suffix, idx + 1, sum + divs[idx], target))
            return true;
    }
    return dfs_semiperfect(divs, suffix, idx + 1, sum, target);
}

bool is_semiperfect(int m)
{
    vector<int> divs;
    divs.reserve(64);
    ll sum_div = 0;
    for (int i = 1; 1LL * i * i <= m; ++i)
    {
        if (m % i == 0)
        {
            if (i < m)
            {
                divs.push_back(i);
                sum_div += i;
            }

            int j = m / i;
            if (j != i && j < m)
            {
                divs.push_back(j);
                sum_div += j;
            }
        }
    }

    if (sum_div < m)
        return false;

    sort(divs.begin(), divs.end(), greater<>());
    vector<ll> suffix(divs.size());
    for (int i = (int)divs.size() - 1; i >= 0; --i)
    {
        suffix[i] = divs[i] + (i + 1 < (int)divs.size() ? suffix[i + 1] : 0LL);
    }

    return dfs_semiperfect(divs, suffix, 0, 0LL, m);
}

TEST(SemiperfectTest, NotSemiperfect_3)
{
    EXPECT_FALSE(is_semiperfect(3));
}

TEST(SemiperfectTest, Semiperfect_6)
{
    EXPECT_TRUE(is_semiperfect(6));
}

TEST(SemiperfectTest, NotSemiperfect_32)
{
    EXPECT_FALSE(is_semiperfect(32));
}

TEST(SemiperfectTest, Semiperfect_12)
{
    EXPECT_TRUE(is_semiperfect(12));
}

TEST(SemiperfectTest, Semiperfect_228)
{
    EXPECT_TRUE(is_semiperfect(228));
}

TEST(SemiperfectTest, Perfect_28)
{
    // 28은 완전수이기도 하지만, semiperfect으로 간주함 (1+2+4+7+14 = 28)
    EXPECT_TRUE(is_semiperfect(28));
}

TEST(SemiperfectTest, AbundantButNotSemiperfect_70)
{
    // 70은 풍부수이나 semiperfect이 아님
    EXPECT_FALSE(is_semiperfect(70));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}