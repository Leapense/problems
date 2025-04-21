#include <bits/stdc++.h>
using namespace std;

long long minH(const vector<long long> &h, int k)
{
    int n = h.size();
    auto tiredCount = [&](long long H)
    {
        int tired = 0;
        for (int i = 0; i < n; ++i)
        {
            bool t = false;
            if (i && llabs(h[i] - h[i - 1]) > H)
                t = true;
            if (i + 1 < n && llabs(h[i] - h[i + 1]) > H)
                t = true;
            if (t)
            {
                if (++tired > k)
                    return tired;
            }
        }
        return tired;
    };
    long long hi = 0;
    for (int i = 1; i < n; ++i)
        hi = max(hi, llabs(h[i] - h[i - 1]));
    long long lo = 0, ans = hi;
    while (lo <= hi)
    {
        long long mid = (lo + hi) / 2;
        if (tiredCount(mid) <= k)
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    return ans;
}

#ifndef UNIT_TEST
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    if (!(cin >> n >> k))
        return 0;
    vector<long long> h(n);
    for (auto &x : h)
        cin >> x;
    cout << minH(h, k) << "\n";
    return 0;
}
#endif

#ifdef UNIT_TEST
#include <gtest/gtest.h>
TEST(SampleTest, Provided)
{
    vector<long long> h{1, 5, 2, 4, 3};
    EXPECT_EQ(minH(h, 3), 2);
}
TEST(EdgeTest, SingleStudent)
{
    vector<long long> h{100};
    EXPECT_EQ(minH(h, 0), 0);
}
TEST(EdgeTest, ZeroTolerance)
{
    vector<long long> h{1, 10, 1};
    EXPECT_EQ(minH(h, 0), 9);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif