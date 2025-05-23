#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int P, C;
        cin >> P >> C;
        vector<int> S(P);
        for (auto &x : S) cin >> x;

        int sumS = 0;
        for (auto x : S) sumS += x;

        int left = 0, right = sumS;
        int ans = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            long long total = 0;

            for (auto x : S) total += min((int)x, mid);
            if (total >= (long long)mid * C) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        cout << "Case #" << tc << ": " << ans << "\n";
    }

    return 0;
}