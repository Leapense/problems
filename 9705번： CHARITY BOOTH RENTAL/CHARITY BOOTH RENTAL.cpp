#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll T;
    int case_num = 1;

    while (cin >> T && T != 0) {
        ll term1 = (T - 1) * (T - 2) / 2;
        ll term2 = 3 * ((T - 1) / 2);
        ll term3 = (T % 3 == 0) ? 2 : 0;
        ll M = (term1 - term2 + term3) / 6;
        cout << "Case #" << case_num++ << ": " << T << ":" << M << "\n";
    }

    return 0;
}