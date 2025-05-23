#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for(auto &x : a) cin >> x;

    long long S = 0;
    long long min_odd = INT32_MAX;
    long long max_even = INT32_MIN;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            S += a[i];
            min_odd = min((long long)min_odd, (long long)a[i]);
        } else {
            S -= a[i];
            max_even = max((long long)max_even, (long long)a[i]);
        }
    }
    long long delta = 2LL * (max_even - min_odd);
    if (delta > 0) {
        S += delta;
    }
    cout << S << "\n";

    return 0;
}