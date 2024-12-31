#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    while (cin >> N) {
        vector<int> trainees(N);
        for (auto &x : trainees) cin >> x;
        bool mask_present[512];
        memset(mask_present, 0, sizeof(mask_present));
        for (auto x : trainees) {
            int mask = 0;
            if (x == 0) {

            } else {
                while (x > 0) {
                    int d = x % 10;
                    if (d >= 1 && d <= 9) mask |= (1 << (d - 1));
                    x /= 10;
                }
            }

            mask_present[mask] = 1;
        }

        int count = 0;
        for (int i = 0; i < 512; i++) {
            if (mask_present[i]) count++;
        }

        cout << count << "\n";
    }

    return 0;
}