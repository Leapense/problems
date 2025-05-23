#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll A, B, C, D, k;
    cin >> A >> B >> C >> D >> k;

    ll sum = B + D;
    ll total = sum - (sum % k);

    while(total >= A + C) {
        ll x = min(B, total - C);
        ll y = total - x;

        if (y >= C and y <= D and x >= A) {
            cout << x << " " << y;
            return 0;
        }

        total -= k;
    }

    cout << "-1\n";

    return 0;
}