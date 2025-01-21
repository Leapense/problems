#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> x(n);

    for (auto &e : x) cin >> e;

    sort(x.begin(), x.end());
    vector<long long> prefix_sum(n);
    prefix_sum[0] = x[0];

    for (int i = 1; i < n; i++) prefix_sum[i] = prefix_sum[i-1] + x[i];
    long long total = 0;
    for (int i = 1; i < n; i++) total += x[i] * i - prefix_sum[i-1];
    cout << total * 2 << endl;

    return 0;
}