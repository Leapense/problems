#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    int limit = 2 * n;
    vector<unsigned char> is_prime(limit + 1, 1);
    if (limit >= 0) is_prime[0] = 0;
    if (limit >= 1) is_prime[1] = 0;
    for (int p = 2; 1LL * p * p <= limit; ++p) {
        if (is_prime[p]) {
            for (long long q = 1LL * p * p; q <= limit; q += p) {
                is_prime[(int)q] = 0;
            }
        }
    }

    int L = n + 1, R = 2 * n - 1;
    int best_l = -1, best_r = -1, best_len = -1;

    int cur_l = -1, cur_len = 0;
    for (int x = L; x <= R; ++x) {
        bool composite = (x > 1) && !is_prime[x];
        if (composite) {
            if (cur_len == 0) cur_l = x;
            ++cur_len;
        } else {
            if (cur_len > 0) {
                int cur_r = x - 1;
                if (cur_len > best_len || (cur_len == best_len && cur_l < best_l)) {
                    best_len = cur_len;
                    best_l = cur_l;
                    best_r = cur_r;
                }
                cur_len = 0;
            }
        }
    }
    if (cur_len > 0) {
        int cur_r = R;
        if (cur_len > best_len || (cur_len == best_len && cur_l < best_l)) {
            best_len = cur_len;
            best_l = cur_l;
            best_r = cur_r;
        }
    }

    cout << best_l << ' ' << best_r << '\n';
    return 0;
}