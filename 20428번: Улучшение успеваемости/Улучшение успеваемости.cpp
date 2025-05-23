#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll a, b, c;
    cin >> a >> b >> c;

    ll numerator = 3 * a + b - c;

    if (numerator <= 0) {
        cout << 0;
        return 0;
    }

    ll k = (numerator + 2) / 3;
    cout << k << "\n";

    return 0;
}