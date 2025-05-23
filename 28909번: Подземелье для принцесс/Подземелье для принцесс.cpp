#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for(auto &x : a) cin >> x;

    vector<int> b(m);
    for(auto &x : b) cin >> x;

    vector<pair<int, int>> cells;

    for (int i = 1; i <= n; i++) {
        int distance;

        if (i <= k) {
            distance = k - i;
        } else {
            distance = i - (k + 1);
        }
        cells.emplace_back(distance, i);
    }

    sort(cells.begin(), cells.end(), [&](const pair<int, int> &a, const pair<int, int> &b) -> bool {
        if (a.first != b.first) {
            return a.first < b.first;
        }
        return a.second < b.second;
    });

    vector<bool> used(n+1, false);
    vector<int> result;

    for (int j = 0; j < m; j++) {
        int bj = b[j];
        int assigned = -1;

        for (auto &[dist, idx] : cells) {
            if (!used[idx] && a[idx - 1] == bj) {
                assigned = idx;
                used[idx] = true;
                break;
            }
        }

        if (assigned == -1) {
            for (auto &[dist, idx] : cells) {
                if (!used[idx] && a[idx-1] > bj) {
                    assigned = idx;
                    used[idx] = true;
                    break;
                }
            }
        }

        result.push_back(assigned);
    }

    for (int i = 0; i < m; i++) {
        cout << result[i] << (i < m - 1 ? ' ' : '\n');
    }

    return 0;
}