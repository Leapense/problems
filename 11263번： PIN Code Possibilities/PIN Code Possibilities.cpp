#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long counts[8][64];
    memset(counts, 0, sizeof(counts));

    counts[0][0] = 1;

    for (int n = 1; n <= 7; n++) {
        for (int s = 0; s <= 63; s++) {
            for (int d = 0; d <= 9; d++) {
                if (s >= d) {
                    counts[n][s] += counts[n - 1][s - d];
                }
            }
        }
    }

    int n, s;
    while (cin >> n >> s) {
        if (n < 0 || n > 7) {
            cout << "0\n";
            continue;
        }
        if (s < 0 || s > 9 * n) {
            cout << "0\n";
            continue;
        }
        cout << counts[n][s] << "\n";
    }

    return 0;
}