#include <gtest/gtest.h>
#include <bits/stdc++.h>

using namespace std;

string solve(const string &in)
{
    istringstream iss(in);
    ostringstream oss;
    long long N;

    iss >> N;
    vector<int> parent(N), sz(N, 1);
    iota(parent.begin(), parent.end(), 0);
    auto find = [&](auto self, int x) -> int
    {
        while (x != parent[x])
        {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }

        return x;
    };
    auto unite = [&](int a, int b)
    {
        a = find(find, a);
        b = find(find, b);
        if (a == b)
            return;
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    };

    for (long long i = 0; i < N; ++i)
        unite(i, (3 * i + 7) % N);
    int root = find(find, 0);
    int bad = -1;
    for (int i = 1; i < N; ++i)
    {
        if (find(find, i) != root)
        {
            bad = i;
            break;
        }
    }
    if (bad == -1)
        oss << "YES\n";
    else
        oss << "NO\n0 " << bad << "\n";
    return oss.str();
}

TEST(Samples, Sample1)
{
    EXPECT_EQ("NO\n0 1\n", solve("4\n"));
}

TEST(Samples, Sample2)
{
    EXPECT_EQ("YES\n", solve("6\n"));
}

TEST(Edge, OneCity)
{
    EXPECT_EQ("YES\n", solve("1\n"));
}