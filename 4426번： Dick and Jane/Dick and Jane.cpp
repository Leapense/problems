#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int s, p, y, j;
    while (cin >> s >> p >> y >> j) {
        int d = 12;
        long long sum_total = d + j;

        long long Y = (sum_total - p - y) / 3;

        if (Y < 0) {
            Y = 0;
        }

        long long P = Y + p;
        long long S = Y + y;

        long long current_sum = 3 * Y + p + y;

        long long delta = sum_total - current_sum;

        S += delta;

        cout << S << " " << P << " " << Y << "\n";
    }

    return 0;
}