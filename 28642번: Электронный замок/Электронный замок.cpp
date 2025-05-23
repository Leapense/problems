#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios::badbit | ios::failbit);

    int n;
    cin >> n;

    if (n % 2 == 0) {
        for (int i = 0; i < n / 2; ++i) {
            cout << '1';
        }
    } else {
        cout << '7';
        for (int i = 0; i < (n - 3) / 2; ++i) {
            cout << '1';
        }
    }

    cout << '\n';

    return 0;
}