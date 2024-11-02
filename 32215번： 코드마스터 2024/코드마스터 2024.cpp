#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);

    int n, m, k;
    cin >> n >> m >> k;

    int ans = (m * k) + m;

    cout << ans << "\n";

    return 0;
}