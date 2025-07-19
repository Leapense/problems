#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int maxT = (argc >= 2 ? atoi(argv[1]) : 1000);
    int maxN = (argc >= 3 ? atoi(argv[2]) : 1000000);

    int T = rnd.next(1, maxT);
    cout << T << "\n";
    for (int i = 0; i < T; i++) {
        int N = rnd.next(1, maxN);
        cout << N << "\n";
    }

    return 0;
}