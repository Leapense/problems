#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int N;
    cin >> N;

    if (N == 0) {
        cout << "YES\n";
        return 0;
    }

    int total = (1 << N);

    int dudu, mn = 1e9;
    cin >> dudu;

    for (int i = 1; i < total; i++) {
        int x;
        cin >> x;
        mn = min(mn, x);
    }

    if (mn <= dudu) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}