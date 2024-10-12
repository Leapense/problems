#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for(auto &x : a) cin >> x;

    long long S = 0;

    int min_xi = INT32_MAX;

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 1) {
            S += a[i];
            min_xi = min(min_xi, a[i]);
        } else {
            if (a[i] >= 1) {
                S += a[i] - 1;
                min_xi = min(min_xi, a[i] - 1);
            } else {

            }
        }
    }
    if (S % 2 == 1) {
        cout << S;
    } else {
        if (min_xi != INT32_MAX) {
            S -= min_xi;
            cout << S;
        } else {
            cout << 0;
        }
    }
}