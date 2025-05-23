#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while (n--) {
        ll b, d;
        cin >> b >> d;

        ll g = gcd(b, d);
        ll t = b * g - 1;
        ll res = t / d;
        
        cout << res << "\n";
    }

    return 0;
}