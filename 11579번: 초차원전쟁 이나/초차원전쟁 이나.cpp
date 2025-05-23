#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        vector<vector<ll>> basis(n, vector<ll>(n));
        vector<ll> target(n);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> basis[i][j];

        for (int i = 0; i < n; i++)
            cin >> target[i];

        bool possible = true;
        ll moves = 0;

        for (int i = 0; i < n; i++)
        {
            if (basis[i][i] != 1)
            {
                possible = false;
                break;
            }

            ll coeff = target[i];

            if (coeff < 0)
            { // Negative coefficient is impossible
                possible = false;
                break;
            }

            moves += coeff;

            for (int j = 0; j < n; j++)
                target[j] -= coeff * basis[i][j];
        }

        for (ll val : target)
            if (val != 0)
                possible = false;

        if (possible && moves <= 2000000000LL)
            cout << "1 " << moves << '\n';
        else
            cout << "0\n";
    }
}
