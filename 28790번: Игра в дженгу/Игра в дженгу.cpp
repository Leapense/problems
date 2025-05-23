#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios::badbit | ios::failbit);

    int n;
    cin >> n;

    if (n % 2 == 1) cout << "Johnny\n";
    else cout << "Lorna\n";

    return 0;
}