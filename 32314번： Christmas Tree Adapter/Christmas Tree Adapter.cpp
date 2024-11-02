#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);

    int a;
    cin >> a;

    int w, v;
    cin >> w >> v;

    if (a <= w / v) cout << "1\n";
    else cout << "0\n";

    return 0;
}