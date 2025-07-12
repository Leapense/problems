#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    if (!(cin >> k)) return 0;
    for (int tc = 1; tc <= k; ++tc) {
        int n;
        cin >> n;
        vector<vector<double>> a(n, vector<double>(n));
        for (auto& row : a) {
            for (auto& v : row) {
                cin >> v;
            }
        }

        double best = -numeric_limits<double>::infinity();
        uint32_t limit = 1u << n;

        for (uint32_t m = 1u; m < limit; ++m) {
            double sum = 0.0;
            for (int i = 0; i < n; ++i) {
                if (m & (1u << i)) {
                    sum += a[i][i];
                }
            }

            for (int i = 0; i < n; ++i) {
                if (m & (1u << i)) {
                    for (int j = i + 1; j < n; ++j) {
                        if (m & (1u << j)) {
                            sum += a[i][j];
                        }
                    }
                }
            }

            best = max(best, sum);
        }

        if (abs(best) < 0.005) best = 0.0;

        cout << "Data Set " << tc << ":\n";
        cout << fixed << setprecision(2) << nearbyint(best * 100.0) / 100.0 << '\n';
    }

    return 0;
}