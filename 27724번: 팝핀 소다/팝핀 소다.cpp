#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    long long N, M, K;
    cin >> N >> M >> K;

    int totalRounds = __builtin_ctzll(N);
    int weakRounds = 63 - __builtin_clzll(K);
    long long answer = min<long long>(totalRounds, weakRounds + M);
    cout << answer << "\n";
    return 0;
}