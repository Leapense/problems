#include <bits/stdc++.h>
using namespace std;

using u128 = __uint128_t;
using u64 = unsigned long long;

u128 upow(u64 a, int e) {
    u128 r = 1, b = a;
    while (e) {
        if (e & 1) r *= b;
        b *= b;
        e >>= 1;
    }
    return r;
}

u128 ugcd(u128 a, u128 b) {
    while (b) {
        u128 t = a % b;
        a = b;
        b = t;
    }

    return a;
}

string to_str(u128 x) {
    if (x == 0) return "0";
    string s;
    while (x) {
        int d = x % 10;
        s.push_back('0' + d);
        x /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, K;
    if (!(cin >> N >> M >> K)) return 0;
    vector<int> cnt(N + 1, 0);
    for (int i = 0; i < M - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cnt[a]++;
        cnt[b]++;
        cnt[c]++;
    }

    u64 T = 3ull * (u64)M;
    u128 best = 0;
    array<int, 3> bestS = {1, 2, 3};

    for (int i = 1; i <= N; i++)
    for (int j = i + 1; j <= N; j++)
    for (int k = j + 1; k <= N; k++) {
        u64 x = 3ull + (u64)cnt[i] + (u64)cnt[j] + (u64)cnt[k];
        u64 Tx = T - x;
        u128 v = (u128)x * upow(Tx, K);
        if (v > best) {
            best = v;
            bestS = {i, j, k};
        }
    }

    u128 q = upow(T, K + 1);
    u128 g = ugcd(best, q);
    best /= g;
    q /= g;
    cout << to_str(best) << ' ' << to_str(q) << "\n";
    sort(bestS.begin(), bestS.end());
    cout << bestS[0] << ' ' << bestS[1] << ' ' << bestS[2] << "\n";
    return 0;
}