#include <bits/stdc++.h>

using namespace std;

constexpr int LIM = 1'000'000;
constexpr int INF = 1'000'000;

static array<int, LIM + 1> dpAll{};
static array<int, LIM + 1> dpOdd{};

static vector<int> tetra_full;
static vector<int> tetra_odd;

static void precompute()
{
    for (long long n = 1;; ++n)
    {
        long long t = n * (n + 1) * (n + 2) / 6;
        if (t > LIM)
            break;
        tetra_full.push_back(static_cast<int>(t));
        if (t & 1)
            tetra_odd.push_back(static_cast<int>(t));
    }

    dpAll.fill(INF);
    dpOdd.fill(INF);
    dpAll[0] = dpOdd[0] = 0;

    for (int c : tetra_full)
    {
        for (int x = c; x <= LIM; ++x)
        {
            if (dpAll[x - c] + 1 < dpAll[x])
                dpAll[x] = dpAll[x - c] + 1;
        }
    }

    for (int c : tetra_odd)
    {
        for (int x = c; x <= LIM; ++x)
        {
            if (dpOdd[x - c] + 1 < dpOdd[x])
                dpOdd[x] = dpOdd[x - c] + 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int n;
    while (cin >> n && n != 0)
    {
        cout << int(dpAll[n]) << ' ' << int(dpOdd[n]) << '\n';
    }

    return 0;
}