#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n) || n <= 0) {
        return 0;
    }

    vector<long long> a(n + 1);
    for (int i = 0; i <= n; ++i) {
        cin >> a[i];
    }

    long long max_minus = LLONG_MIN;
    long long max_plus = LLONG_MIN;

    for (int i = 0; i <= n; ++i) {
        long long v = a[i];
        max_minus = max(max_minus, v - i);
        max_plus = max(max_plus, v + i);
    }

    cout << (max_minus + max_plus) << "\n";
    return 0;
}