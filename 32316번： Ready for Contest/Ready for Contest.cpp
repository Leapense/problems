#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);

    int n, m;
    cin >> n >> m;

    vector<int> flags(n+1, 0);

    for (int i = 0; i < m; ++i) {
        int p, L;
        cin >> p >> L;

        if (L == 1) {
            flags[p] |= 1;
        } else if(L == 2) {
            flags[p] |= 2;
        }
    }

    for (int p = 1; p <= n; ++p) {
        if ((flags[p] & 1) && (flags[p] & 2)) {
            cout << p << "\n";
        }
    }

    return 0;
}