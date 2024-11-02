#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n);

    for (auto &x : a) cin >> x;

    sort(a.begin(), a.end(), greater<long long>());

    long long max_val = a[0];
    long long second_max = a[1];
    cout << (max_val + second_max) / 2 << "\n";

    return 0;
}