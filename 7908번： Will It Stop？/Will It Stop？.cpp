#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;
    unordered_set<ll> seen;

    while(n > 1) {
        if (seen.find(n) != seen.end()) {
            cout << "NIE";
            return 0;
        }

        seen.insert(n);
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 3;
        }
    }

    cout << "TAK";

    return 0;
}