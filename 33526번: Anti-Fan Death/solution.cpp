#include <bits/stdc++.h>
using namespace std;

vector<string> build(int N)
{
    if (N == 1)
        return {"ZNA", "NAZ", "AZN"};
    const char B[3][3] = {{'Z', 'N', 'A'},
                          {'N', 'A', 'Z'},
                          {'A', 'Z', 'N'}};
    vector<string> g(3 * N, string(3 * N, 'A'));
    for (int i = 0; i < 3 * N; ++i)
    {
        int r = i / N;
        for (int j = 0; j < 3 * N; ++j)
        {
            int c = j / N;
            g[i][j] = B[r][c];
        }
    }

    return g;
}

#ifndef UNIT_TEST
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N))
        return 0;
    auto g = build(N);

    if (g.empty())
    {
        cout << -1 << "\n";
        return 0;
    }

    for (auto &row : g)
        cout << row << "\n";
    return 0;
}
#endif