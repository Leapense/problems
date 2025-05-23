#include <bits/stdc++.h>
using namespace std;

int simulate(int n, const vector<int> &bars, int p) {
    int pos = p;
    for (auto x : bars) {
        if (x == pos) {
            pos += 1;
        } else if (x == pos - 1) {
            pos -= 1;
        }
    }

    return pos;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, p, q;
    while (cin >> n >> m >> p >> q) {
        if (n == 0 && m == 0 && p == 0 && q == 0) {
            break;
        }

        vector<int> bars(m);
        for (int &x : bars) {
            cin >> x;
        }

        int end_pos = simulate(n, bars, p);

        if (end_pos == q) {
            cout << "OK\n";

            continue;
        }

        bool found = false;
        int res_x = -1, res_y = -1;
        for (int y = 0; y <= m && !found; y++) {
            for (int x = 1; x <= n - 1 && !found; x++) {
                vector<int> new_bars = bars;

                new_bars.insert(new_bars.begin() + y, x);

                int new_end = simulate(n, new_bars, p);

                if (new_end == q) {
                    res_x = x;
                    res_y = y;
                    found = true;
                }
            }
        }

        if (found) {
            cout << res_x << " " << res_y << "\n";
        } else {
            cout << "NG\n";
        }
    }

    return 0;
}