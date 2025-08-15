#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);
    int maxVal = atoi(argv[2]);
    int sameCase = atoi(argv[3]);

    vector<int> A(n);
    set<int> used;
    for (int i = 0; i < n; i++) {
        int val;
        do {
            val = rnd.next(1, maxVal);
        } while (used.count(val));
        used.insert(val);
        A[i] = val;
    }

    vector<int> B;
    if (sameCase == 1) {
        B = A;
    } else {
        B = A;
        shuffle(B.begin(), B.end());
        while (B == A) {
            shuffle(B.begin(), B.end());
        }
    }

    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        cout << A[i] << (i + 1 == n ? '\n' : ' ');
    }
    for (int i = 0; i < n; i++) {
        cout << B[i] << (i + 1 == n ? '\n' : ' ');
    }

    return 0;
}