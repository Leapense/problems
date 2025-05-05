#include <bits/stdc++.h>

using namespace std;
using int64 = long long;
constexpr int64 MOD = 1'000'000'007LL;

static vector<int64> buildPow2(int n)
{
    vector<int64> p(n);
    p[0] = 1;
    for (int i = 1; i < n; ++i)
        p[i] = (p[i - 1] * 2) % MOD;
    return p;
}

#ifndef UNIT_TEST
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N))
        return 0;

    vector<int64> H(N);
    for (auto &x : H)
        cin >> x;

    sort(H.begin(), H.end(), greater<>());

    auto pow2 = buildPow2(N);
    int64 ans = 0;

    for (int i = 0; i < N; ++i)
    {
        int idx = N - 1 - i;
        ans = (ans + H[i] % MOD * pow2[idx]) % MOD;
    }

    cout << ans << "\n";
    return 0;
}
#endif