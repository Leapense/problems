#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll a, b;
    cin >> a >> b;

    ll delta = abs(b - a);
    ll n = (2 * delta) / b;

    cout << n << "\n";

    return 0;
}