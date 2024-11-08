#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    ll total_cells = 1 + 3 * n * (n - 1);

    cout << total_cells << "\n";

    return 0;
}