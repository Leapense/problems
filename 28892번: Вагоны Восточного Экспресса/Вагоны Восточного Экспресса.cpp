#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());

    long long min_time = n;
    for (int i = 0; i < n; i++) {
        if (i > 0 && a[i] == a[i - 1]) continue;
        long long k = a[i];
        int pos = upper_bound(a.begin(), a.end(), k) - a.begin();
        long long cnt = n - pos;
        long long t = k + cnt;
        min_time = min(min_time, t);
    }
    min_time = min(min_time, (long long)n);
    cout << min_time << "\n";

    return 0;
}