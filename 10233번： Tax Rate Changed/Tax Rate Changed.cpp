#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y, s;
    while (cin >> x >> y >> s) {
        if (x == 0 && y == 0 && s == 0) break;
        int max_total = 0;
        for (int s1 = 1; s1 < s; s1++) {
            int s2 = s - s1;
            long long a_min = (1LL * s1 * 100 + 100 + x - 1) / (100 + x);
            long long a_max = ((1LL * (s1 + 1) * 100 - 1)) / (100 + x);
            if (a_min > a_max) continue;

            long long b_min = (1LL * s2 * 100 + 100 + x - 1) / (100 + x);
            long long b_max = ((1LL * (s2 + 1) * 100 - 1)) / (100 + x);
            if (b_min > b_max) continue;

            long long a = a_max;
            long long b = b_max;

            if (a < 1 || b < 1) continue;

            long long after_y = (a * (100 + y)) / 100 + (b * (100 + y)) / 100;
            if (after_y > max_total) {
                max_total = after_y;
            }
        }

        cout << max_total << "\n";
    }

    return 0;
}