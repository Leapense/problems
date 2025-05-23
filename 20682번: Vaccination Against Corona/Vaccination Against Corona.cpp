#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    long long L;
    cin >> n >> L;

    vector<long long> pos(n);

    for (auto &x : pos) cin >> x;
    sort(pos.begin(), pos.end());

    int count = 0;

    long long last = -1e10;

    for (auto x : pos) {
        if (x >= last + L) {
            count++;
            last = x;
        }
    }

    cout << n - count << endl;

    return 0;
}