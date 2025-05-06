#include <bits/stdc++.h>
using namespace std;

inline int64_t minCost(int64_t N, int64_t S, int64_t E)
{
    if ((S == 1 && E == N) || (S == N && E == 1))
        return 0;
    if (std::llabs(S - E) == 1)
        return 1;
    return 2;
}

#ifndef UNIT_TEST
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int64_t N, S, E;
        cin >> N >> S >> E;
        cout << minCost(N, S, E);
        if (T)
            cout << '\n';
    }
    return 0;
}
#endif