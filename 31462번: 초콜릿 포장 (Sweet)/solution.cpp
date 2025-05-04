// solution.cpp
// C++26 – compile with: g++ -std=c++2b -O2 -pipe -static -s solution.cpp -o solution
#include <bits/stdc++.h>
using namespace std;

bool isValid(const vector<string> &g)
{
    const int N = static_cast<int>(g.size());
    if (N == 0)
        return true;

    // Triangular "used" array
    vector<vector<uint8_t>> used(N);
    for (int r = 0; r < N; ++r)
        used[r].assign(r + 1, 0);

    auto markR = [&](int r, int c) -> bool
    {
        if (r + 1 >= N)
            return false;
        if (g[r + 1][c] != 'R' || g[r + 1][c + 1] != 'R')
            return false;
        if (used[r][c] || used[r + 1][c] || used[r + 1][c + 1])
            return false;
        used[r][c] = used[r + 1][c] = used[r + 1][c + 1] = 1;
        return true;
    };

    auto markB = [&](int r, int c) -> bool
    {
        if (r == 0 || c == 0)
            return false; // needs two cells above
        if (g[r - 1][c - 1] != 'B' || g[r - 1][c] != 'B')
            return false;
        if (used[r][c] || used[r - 1][c - 1] || used[r - 1][c])
            return false;
        used[r][c] = used[r - 1][c - 1] = used[r - 1][c] = 1;
        return true;
    };

    const long long total = 1LL * N * (N + 1) / 2;
    long long usedCnt = 0;

    // Pass 1 – reds (top → bottom)
    for (int r = 0; r < N - 1; ++r)
    {
        for (int c = 0; c <= r; ++c)
        {
            if (g[r][c] == 'R' && !used[r][c])
            {
                if (!markR(r, c))
                    return false;
                usedCnt += 3;
            }
        }
    }

    // Pass 2 – blues (bottom → top)
    for (int r = N - 1; r >= 1; --r)
    {
        for (int c = 1; c <= r - 1; ++c)
        { // c==0 or c==r can’t be a blue apex
            if (g[r][c] == 'B' && !used[r][c])
            {
                if (!markB(r, c))
                    return false;
                usedCnt += 3;
            }
        }
    }

    // Everything must be covered exactly once
    return usedCnt == total;
}

#ifndef UNIT_TEST
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if (!(cin >> N))
        return 0;
    vector<string> g(N);
    for (int i = 0; i < N; ++i)
        cin >> g[i];

    cout << (isValid(g) ? 1 : 0) << '\n';
    return 0;
}
#endif