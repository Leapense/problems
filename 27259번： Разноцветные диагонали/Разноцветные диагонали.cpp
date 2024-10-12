#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int d1 = abs(i - j);
            int d2 = abs(i + j - (n - 1));
            int min_d = min(d1, d2);
            char letter = 'a' + (min_d % 26);
            cout << letter;
        }

        cout << "\n";
    }

    return 0;
}