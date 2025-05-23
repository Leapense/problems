#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<pair<int, int>> elements(n, {0, 0});
    for (int i = 0; i < n; i++) cin >> elements[i].first >> elements[i].second;

    if (n == 0) {
        if (m == 0) {
            cout << 0;
        } else {
            cout << -1;
        }

        return 0;
    }

    vector<int> previous(m + 1, INF);

    previous[0] = 0;

    for (int i = 0; i < n; i++) {
        vector<int> current(m + 1, INF);
        int b = elements[i].first;
        int a = elements[i].second;

        for (int s = 0; s <= m; s++) {
            if (previous[s] == INF) continue;

            int lower = max(b, 0);
            int upper = min(a, m - s);
            for (int c = lower; c <= upper; c++) {
                int cost = 0;
                if (c == 0) {
                    cost = 0;
                } else if (1 <= c && c <= 9) {
                    cost = x;
                } else {
                    cost = y;
                }

                if (s + c <= m) {
                    current[s + c] = min(current[s + c], previous[s] + cost);
                }
            }
        }
        previous = current;
    }

    if (previous[m] != INF) {
        cout << previous[m];
    } else {
        cout << -1;
    }

    return 0;
}