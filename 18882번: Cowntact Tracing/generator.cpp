#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    int TC = atoi(argv[1]);
    int MAX_N = atoi(argv[2]);
    int MAX_T = atoi(argv[3]);

    cout << TC << "\n";
    for (int tc = 0; tc < TC; tc++) {
        int n = rnd.next(1, MAX_N);
        int T = rnd.next(0, MAX_T);
        cout << n << " " << T << "\n";

        string finalState;
        finalState.reserve(n);
        for (int i = 0; i < n; i++) {
            finalState += char('0' + rnd.next(0, 1));
        }
        cout << finalState << "\n";

        vector<tuple<int, int, int>> ev;
        ev.reserve(T);
        for (int i = 0; i < T; i++) {
            int t = rnd.next(1, T);
            int x = rnd.next(1, n);
            int y = rnd.next(1, n);
            ev.emplace_back(t, x, y);
        }

        sort(ev.begin(), ev.end(), [](auto &a, auto &b) {
            return get<0>(a) < get<0>(b);
        });

        for (auto &e : ev) {
            int t, x, y;
            tie(t, x, y) = e;
            cout << t << " " << x << " " << y << "\n";
        }
    }

    return 0;
}