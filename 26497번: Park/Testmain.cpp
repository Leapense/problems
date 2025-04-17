#include <gtest/gtest.h>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int countVisibleTrees(int N, int M,
                      const vector<pair<ll, ll>> &trees,
                      const vector<string> &paths)
{
    vector<ll> vertPaths, horzPaths;
    vertPaths.reserve(M);
    horzPaths.reserve(M);
    for (auto &s : paths)
    {
        if (s[0] == 'x')
        {
            ll a = stoll(s.substr(2));
            vertPaths.push_back(a);
        }
        else
        {
            ll b = stoll(s.substr(2));
            horzPaths.push_back(b);
        }
    }
    sort(vertPaths.begin(), vertPaths.end());
    vertPaths.erase(unique(vertPaths.begin(), vertPaths.end()), vertPaths.end());
    sort(horzPaths.begin(), horzPaths.end());
    horzPaths.erase(unique(horzPaths.begin(), horzPaths.end()), horzPaths.end());

    unordered_map<ll, vector<int>> rows, cols;
    rows.reserve(N);
    cols.reserve(N);
    for (int i = 0; i < N; i++)
    {
        auto [x, y] = trees[i];
        rows[y].push_back(i);
        cols[x].push_back(i);
    }

    const ll INF = LLONG_MAX;
    vector<ll> L(N), R(N), D(N), U(N);

    // Row neighbors
    for (auto &kv : rows)
    {
        auto &idxs = kv.second;
        vector<pair<ll, int>> vx;
        vx.reserve(idxs.size());
        for (int i : idxs)
            vx.emplace_back(trees[i].first, i);
        sort(vx.begin(), vx.end());
        int K = vx.size();
        for (int j = 0; j < K; j++)
        {
            int idx = vx[j].second;
            L[idx] = (j > 0 ? vx[j - 1].first : LLONG_MIN);
            R[idx] = (j + 1 < K ? vx[j + 1].first : INF);
        }
    }
    // Column neighbors
    for (auto &kv : cols)
    {
        auto &idxs = kv.second;
        vector<pair<ll, int>> vy;
        vy.reserve(idxs.size());
        for (int i : idxs)
            vy.emplace_back(trees[i].second, i);
        sort(vy.begin(), vy.end());
        int K = vy.size();
        for (int j = 0; j < K; j++)
        {
            int idx = vy[j].second;
            D[idx] = (j > 0 ? vy[j - 1].first : LLONG_MIN);
            U[idx] = (j + 1 < K ? vy[j + 1].first : INF);
        }
    }

    vector<char> visible(N, 0);
    for (int i = 0; i < N; i++)
    {
        auto [x, y] = trees[i];
        // Left
        auto itL = upper_bound(vertPaths.begin(), vertPaths.end(), L[i]);
        if (itL != vertPaths.end() && *itL < x)
            visible[i] = 1;
        // Right
        auto itR = upper_bound(vertPaths.begin(), vertPaths.end(), x);
        if (itR != vertPaths.end() && *itR < R[i])
            visible[i] = 1;
        // Down
        auto itD = upper_bound(horzPaths.begin(), horzPaths.end(), D[i]);
        if (itD != horzPaths.end() && *itD < y)
            visible[i] = 1;
        // Up
        auto itU = upper_bound(horzPaths.begin(), horzPaths.end(), y);
        if (itU != horzPaths.end() && *itU < U[i])
            visible[i] = 1;
    }
    return accumulate(visible.begin(), visible.end(), 0);
}

TEST(ParkVisibilityTest, Sample1)
{
    int N = 6, M = 3;
    vector<pair<ll, ll>> trees = {{-1, 3}, {4, 2}, {6, 2}, {6, 3}, {6, 4}, {4, 3}};
    vector<string> paths = {"x=0", "y=-1", "y=5"};
    EXPECT_EQ(countVisibleTrees(N, M, trees, paths), 5);
}

TEST(ParkVisibilityTest, Sample2)
{
    int N = 1, M = 2;
    vector<pair<ll, ll>> trees = {{2, 3}};
    vector<string> paths = {"x=5", "y=5"};
    EXPECT_EQ(countVisibleTrees(N, M, trees, paths), 1);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}