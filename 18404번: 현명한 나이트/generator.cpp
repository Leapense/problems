#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int maxN = (argc >= 2 ? atoi(argv[1]) : 500);
    int maxM = (argc >= 3 ? atoi(argv[2]) : maxN * maxN);

    int n = rnd.next(1, maxN);
    int m = rnd.next(1, min(maxM, n * n));

    int startRow = rnd.next(1, n);
    int startCol = rnd.next(1, n);

    cout << n << " " << m << "\n";
    cout << startRow << " " << startCol << "\n";

    set<pair<int, int>> used;

    for (int i = 0; i < m; i++) {
        int r, c;
        do {
            r = rnd.next(1, n);
            c = rnd.next(1, n);
        } while (used.count({r, c}));
        used.insert({r, c});
        cout << r << " " << c << "\n";
    }

    return 0;
}