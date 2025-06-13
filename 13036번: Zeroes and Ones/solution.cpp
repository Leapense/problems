#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) {
        return EXIT_FAILURE;
    }

    while (t--) {
        int n;
        cin >> n;
        string s, u;
        cin >> s >> u;

        vector<int> d(n);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            d[i] = (s[i] != u[i]);
            sum += d[i];
        }

        if (sum % 2 != 0) {
            cout << "-1\n";
            continue;
        }

        int ops = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (d[i]) {
                d[i] = 0;
                d[i + 1] ^= 1;
                ++ops;
            }
        }

        cout << ops << "\n";
    }

    return EXIT_SUCCESS;
}