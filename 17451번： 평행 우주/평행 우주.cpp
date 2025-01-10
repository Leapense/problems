#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    long long speed = v[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        speed = ((speed + v[i] - 1) / v[i]) * v[i];
    }

    cout << speed << "\n";

    return 0;
}