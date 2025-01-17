#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long S = 0;

    for (int i = 0; i < n; i++) {
        S += a[i];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i - 1] * i <= S) ans = i;
        else break;
    }

    cout << n - ans << "\n";

    return 0;
}