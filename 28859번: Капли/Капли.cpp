#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios::badbit | ios::failbit); 

    long long n, k, t;
    cin >> n >> k >> t;

    vector<long long> p(n);

    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    long long num_full_intervals = t / k;
    long long partial_duration = t % k;

    long long total_drops = 0;

    for (int i = 0; i < n; ++i) {
        long long drops_per_full_interval = k / p[i];
        long long drops_in_partial_interval = partial_duration / p[i];

        total_drops += num_full_intervals * drops_per_full_interval + drops_in_partial_interval;
    }

    cout << total_drops << '\n';
    return 0;
}