#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    int64_t D;
    cin >> N >> D;

    vector<int64_t> x(N), a(N), g(N), r(N);

    for (int i = 0; i < N; ++i) {
        cin >> x[i] >> a[i] >> g[i] >> r[i];
    }

    bool can_pass_all = true;

    for (int i = 0; i < N; ++i) {
        int64_t t_i = x[i];
        if (t_i < a[i]) {
            can_pass_all = false;
            break;
        } else {
            int64_t p_i = g[i] + r[i];
            int64_t t_prime = t_i - a[i];
            int64_t t_mod = t_prime % p_i;

            if (t_mod <= g[i]) {
                continue;
            } else {
                can_pass_all = false;
                break;
            }
        }
    }

    if (can_pass_all) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}