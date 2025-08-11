#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    if (!(cin >> n >> k)) {
        return 0;
    }

    vector<int> c(k);
    vector<vector<int>> freq(k, vector<int>(n + 1, 0));
    vector<vector<int>> res(k);
    vector<int> assigned(k, 0);

    for (int g = 0; g < k; ++g) {
        int ci;
        cin >> ci;
        c[g] = ci;
        res[g].reserve(static_cast<size_t>(ci));
        for (int j = 0; j < ci; ++j) {
            int s;
            cin >> s;
            if (s < 0 || s > n) {
                return 0;
            }
            ++freq[g][s];
        }
    }

    for (int t = 0; t < n; ++t) {
        int chosen = -1;
        for (int g = 0; g < k; ++g) {
            int expected = t - assigned[g];
            if (expected >= 0 && expected <= n && freq[g][expected] > 0) {
                chosen = g;
                break;
            }
        }
        if (chosen < 0) {
            return 0;
        }
        int expected = t - assigned[chosen];
        --freq[chosen][expected];
        res[chosen].push_back(t + 1);
        ++assigned[chosen];
    }

    for (int g = 0; g < k; ++g) {
        for (int j = 0; j < c[g]; ++j) {
            if (j) cout << ' ';
            cout << res[g][j];
        }
        if (g < k - 1) cout << '\n';
    }

    return 0;
}