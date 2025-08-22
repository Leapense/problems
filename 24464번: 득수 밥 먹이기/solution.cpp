#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 1000000007;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    array<long long, 5> prev{}, curr{};
    prev.fill(1);
    prev[0] = 1;

    if (N == 1) {
        cout << accumulate(prev.begin(), prev.end(), 0LL) % MOD << '\n';
        return 0;
    }

    for (int day = 2; day <= N; ++day) {
        curr[0] = (prev[1] + prev[2] + prev[3] + prev[4]) % MOD;
        curr[1] = (prev[0] + prev[3] + prev[4]) % MOD;
        curr[2] = (prev[0] + prev[4]) % MOD;
        curr[3] = (prev[0] + prev[1]) % MOD;
        curr[4] = (prev[0] + prev[1] + prev[2]) % MOD;
        prev = curr;
    }

    cout << accumulate(prev.begin(), prev.end(), 0LL) % MOD << '\n';
    return 0;
}