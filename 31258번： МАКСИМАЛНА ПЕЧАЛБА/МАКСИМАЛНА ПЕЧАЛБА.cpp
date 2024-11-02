#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<int> b(m);
    for (auto &x : b) cin >> x;

    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    int k = min(n, m);
    long long total = 0;

    for (int i = 0; i < k; i++) {
        total += (long long)a[i] * b[i];
    }

    cout << k << " " << total << "\n";

    return 0;
}