#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int z;
    cin >> z;

    while (z--) {
        int n, k;
        cin >> n >> k;
        vector<ll> t(n);
        for (auto &x : t) cin >> x;

        sort(t.begin(), t.end(), [&](const ll &a, const ll &b) -> bool {
            return a > b;
        });

        ll max_silver = 0;
        if (k > 0) {
            max_silver = t[0];
            for (int i = 1; i < k; ++i) {
                max_silver = max(max_silver, t[i]);
            }
        }

        ll sum_gold = 0;
        for (int i = k; i < n; ++i) {
            sum_gold += t[i];
        }

        ll total_time = max(sum_gold, max_silver);
        cout << total_time << "\n";
    }

    return 0;
}