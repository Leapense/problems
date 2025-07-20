#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int MAX_N = atoi(argv[1]);
    int MAX_H = atoi(argv[2]);
    int MAX_T = atoi(argv[3]);

    int N = rnd.next(1, MAX_N);
    int64_t Hc = rnd.next(1, MAX_H);
    int T = rnd.next(0, MAX_T);

    cout << N << " " << Hc << " " << T << "\n";

    for (int i = 0; i < N; i++) {
        int64_t a = rnd.next(1, MAX_H);
        cout << a << (i + 1 == N ? "\n" : " ");
    }

    return 0;
}