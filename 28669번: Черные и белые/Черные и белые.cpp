#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    
    ll p = n + 2;
    ll q = 2 * (n + 1);

    if (p % 2 == 0) {
        p /= 2;
        q /= 2;
    }

    cout << p << " " << q;

    return 0;
}