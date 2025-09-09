#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<long long> t(N);
    for (int i = 0; i < N; ++i) cin >> t[i];

    vector<long long> a(N + 1);
    long long T = 0;
    a[1] = 0;
    for (int s = 2; s <= N; ++s) {
        T += t[s - 2];
        a[s] = T;
    }
    T += t[N - 1];

    long long ans = 0;
    for (int i = 0; i < M; ++i) {
        int p, r;
        long long c;
        cin >> p >> r >> c;

        long long base = a[p];
        long long k = 0;
        if (c > base) {
            long long diff = c - base;
            k = (diff + T - 1) / T;
        }

        long long b = base + k * T;
        long long d = (a[r] - a[p]) % T;
        if (d < 0) d += T;
        
        long long f = b + d;
        ans = max(ans, f);
    }

    cout << ans << '\n';

    return 0;
}