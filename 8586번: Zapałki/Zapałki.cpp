#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    vector<int> x(n);
    for (auto &xi : x) cin >> xi;
    long long prev0 = (x[0] != 0) ? 1 : 0;
    long long prev1 = (x[0] != 1) ? 1 : 0;

    for (int i = 1; i < n; i++) {
        long long current0 = min(prev0, prev1) + ((x[i] != 0) ? 1 : 0);
        long long current1 = prev1 + ((x[i] != 1) ? 1 : 0);
        prev0 = current0;
        prev1 = current1;
    }

    cout << min(prev0, prev1);

    return 0;
}