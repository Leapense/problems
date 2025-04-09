#include <bits/stdc++.h>
#include <gtest/gtest.h>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

pair<ll, ll> addFraction(pair<ll, ll> f, pair<ll, ll> g)
{
    ll num = f.first * g.second + g.first * f.second;
    ll den = f.second * g.second;
    ll d = gcd(num, den);
    return {num / d, den / d};
}

void solve(istream &in, ostream &out)
{
    int N;
    in >> N;
    vector<int> cake(N);
    for (auto &v : cake)
        in >> v;
    int ans = 0;
    for (int mask = 1; mask < (1 << N); mask++)
    {
        pair<ll, ll> sum = {0, 1};
        for (int i = 0; i < N; i++)
        {
            if (mask & (1 << i))
            {
                pair<ll, ll> piece = {1, cake[i]};
                sum = addFraction(sum, piece);
            }
        }
        if (100 * sum.first >= 99 * sum.second && 100 * sum.first <= 101 * sum.second)
            ans++;
    }
    out << ans;
}

TEST(SampleTests, Case1)
{
    string input = "6\n3 4 6 7 9 10\n";
    stringstream ss(input), os;
    solve(ss, os);
    EXPECT_EQ(os.str(), "2");
}

TEST(SampleTests, Case2)
{
    string input = "10\n2 2 4 4 4 4 8 8 8 8\n";
    stringstream ss(input), os;
    solve(ss, os);
    EXPECT_EQ(os.str(), "94");
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}