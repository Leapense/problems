#pragma GCC optimize("O3")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);

    ll n, k, x;
    cin >> n >> k >> x;

    ll m = n - k;

    ll y = (x + m - 1) / m;
    ll S = x + k * y;
    cout << S << "\n";

    return 0;
}