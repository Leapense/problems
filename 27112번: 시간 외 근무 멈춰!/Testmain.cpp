#include "gtest/gtest.h"
using namespace std;
using ll = long long;

ll reg_days(ll d)
{
    ll w = d / 7;
    ll r = d % 7;
    return w * 5 + min(r, 5LL);
}

int minimalOvertime(int N, vector<pair<int, int>> a)
{
    sort(a.begin(), a.end());
    ll req = 0, ans = 0;
    for (auto &[d, t] : a)
    {
        req += t;
        ll reg = reg_days(d);
        if (req > reg + d)
            return -1;
        ans = max(ans, max(0LL, req - reg));
    }

    return int(ans);
}

TEST(OvertimeTest, Sample1)
{
    vector<pair<int, int>> a = {{5, 4}, {6, 2}, {2, 1}, {9, 1}, {10, 3}};
    EXPECT_EQ(minimalOvertime(5, a), 3);
}

TEST(OvertimeTest, Sample2)
{
    vector<pair<int, int>> a = {{5, 3}, {3, 5}, {4, 3}};
    EXPECT_EQ(minimalOvertime(3, a), -1);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}