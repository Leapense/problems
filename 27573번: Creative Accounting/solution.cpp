#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l, h;
    if (!(cin >> n >> l >> h)) return 0;

    vector<long long> S(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        long long p;
        cin >> p;
        S[i + 1] = S[i] + p;
    }

    int global_min = INT_MAX;
    int global_max = INT_MIN;

    vector<unsigned char> D;

    for (int k = l; k <= h; ++k) {
        int m = n - k + 1;
        if (m < 0) m = 0;
        D.assign(m, 0);
        for (int x = 0; x < m; ++x) {
            long long diff = S[x + k] - S[x];
            D[x] = (diff > 0) ? 1 : 0;
        }

        int k_min = INT_MAX, k_max = INT_MIN;

        for (int r = 0; r < k; ++r) {
            int sum_stride = 0;
            for (int x = r; x <= n - k; x += k) {
                sum_stride += D[x];
            }
            int cnt = 0;

            if (r <= n && S[r] > 0) ++cnt;

            cnt += sum_stride;

            long long L = r + 1LL * ((n - r) >= 0 ? ((n - r) / k) : 0) * k;
            if (L < n) {
                if (S[n] - S[(int)L] > 0) ++cnt;
            }

            k_min = min(k_min, cnt);
            k_max = max(k_max, cnt);
        }
        global_min = min(global_min, k_min);
        global_max = max(global_max, k_max);
    }

    cout << global_min << ' ' << global_max << "\n";
    return 0;
}