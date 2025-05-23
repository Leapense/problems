#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, d;
    cin >> n >> d;
    int t1, t2, t3;
    cin >> t1 >> t2 >> t3;

    vector<bool> ripe(n + 2, false);
    ripe[t1] = ripe[t2] = ripe[t3] = true;

    for (int day = 1; day <= d; ++day) {
        vector<bool> next_ripe = ripe;
        for (int i = 1; i <= n; ++i) {
            if (!ripe[i] && (ripe[i - 1] || ripe[i + 1])) {
                next_ripe[i] = true;
            }
        }
        ripe = next_ripe;
    }

    int count = 0;

    for (int i = 1; i <= n; ++i) {
        if (ripe[i]) {
            ++count;
        }
    }

    cout << count << endl;

    return 0;
}