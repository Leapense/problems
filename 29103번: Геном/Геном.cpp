#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll x, y, z, k;
    cin >> x >> y >> z >> k;
    ll diff = x - y;

    if (k % 2) diff = -diff;
    cout << diff << "\n";

    return 0;
}