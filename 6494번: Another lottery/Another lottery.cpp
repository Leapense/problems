#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd_func(ll a, ll b) {
    while (b) {
        ll temp = a % b;
        a = b;
        b = temp;
    }

    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(true) {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0) break;

        vector<vector<ll>> participants(n, vector<ll>(m, 0));

        ll Tm = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> participants[i][j];

                if (j == m - 1) {
                    Tm += participants[i][j];
                }
            }
        }

        for (int i = 0; i < n; i++) {
            ll cm = participants[i][m - 1];
            if (cm == 0) {
                cout << "0 / 1\n";
                continue;
            }

            ll g = gcd_func(cm, Tm);

            cout << (cm / g) << " / " << (Tm / g) << "\n";
        }
    }

    return 0;
}