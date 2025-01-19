#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end(), greater<int>());

    long long sum = 0;
    for (int i = 0; i < n; i++) if ((i + 1) % k != 0) sum += a[i];

    cout << sum << "\n";
    return 0;
}