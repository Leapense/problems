#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios::failbit);

    ll N, M, T, K;
    cin >> N >> M >> T >> K;

    ll q = N / M;
    ll r = N % M;

    ll c_max = K / T + 1;

    ll k1 = min(q + 1, c_max);
    ll sum1 = r * (k1 * K - T * k1 * (k1 - 1) / 2);

    ll k2 = min(q, c_max);
    ll sum2 = (M - r) * (k2 * K - T * k2 * (k2 - 1) / 2);

    ll total = sum1 + sum2;

    total = min(total, (ll)2000000000);

    cout << total;

    return 0;
}