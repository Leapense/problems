#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100005;
int lastSkip[MAX_N];

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios::badbit | ios::failbit);

    int t;
    cin >> t;
    string blank;
    getline(cin, blank);

    while (t--) {
        getline(cin, blank);

        int n, e;
        cin >> n >> e;

        memset(lastSkip,  0, (n + 1) * sizeof(int));

        for (int time = 1; time <= e; ++time) {
            int p;
            cin >> p;
            lastSkip[p] = time;
        }

        getline(cin, blank);

        bool found_zero = false;

        for (int p = n; p >= 1; --p) {
            if (lastSkip[p] == 0) {
                cout << p << "\n";
                found_zero = true;
                break;
            }
        }

        if (!found_zero) {
            int min_time = numeric_limits<int>::max();
            int min_p = -1;

            for (int p = 1; p <= n; ++p) {
                if (lastSkip[p] > 0 && lastSkip[p] < min_time) {
                    min_time = lastSkip[p];
                    min_p = p;
                }
            }

            cout << min_p << "\n";
        }
    }

    return 0;
}