#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (auto &x : a) cin >> x;

        long long ans = 0;
        unordered_map<long long, int> freq;
        for (int j = 0; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                long long want = 2 * a[j] - a[k];
                ans += freq[want];
            }

            ++freq[a[j]];
        }
        cout << ans << '\n';
    }

    return 0;
}