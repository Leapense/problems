#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> difficulties(n);
    for (auto &d : difficulties) {
        cin >> d;
    }

    auto is_valid = [&](int k) -> bool {
        if (n % k != 0 || k <= 1) {
            return false;
        }

        int section_size = n / k;

        vector<vector<int>> sections(k, vector<int>());

        for (int p = 1; p <= n; p++) {
            int section = ceil(1.0 * k * p / n) - 1;

            if (section >= k) {
                section = k - 1;
            }
            sections[section].push_back(difficulties[p - 1]);
        }

        vector<pair<int, int>> min_max(k, {INT32_MAX, INT32_MIN});

        for (int i = 0; i < k; i++) {
            for (auto d : sections[i]) {
                min_max[i].first = min(min_max[i].first, d);
                min_max[i].second = max(min_max[i].second, d);
            }
        }

        for (int i = 0; i < k - 1; i++) {
            if (min_max[i].second >= min_max[i + 1].first) {
                return false;
            }
        }

        return true;
    };

    vector<int> valid_ks;
    for (int k = 2; k <= n; k++) {
        if (is_valid(k)) {
            valid_ks.push_back(k);
        }
    }

    if (valid_ks.empty()) {
        cout << "-1";
    }
    else {
        for (auto k : valid_ks) {
            cout << k << "\n";
        }
    }

    return 0;
}