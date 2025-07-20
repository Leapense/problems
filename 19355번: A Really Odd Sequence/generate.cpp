#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int T = atoi(argv[1]);
    int MAX_N = atoi(argv[2]);
    int MAX_A = atoi(argv[3]);

    cout << T << "\n";
    for (int tc = 0; tc < T; tc++) {
        int n = rnd.next(1, MAX_N);
        cout << n << "\n";

        for (int i = 0; i < n; i++) {
            int x = rnd.next(-MAX_A, MAX_A);
            cout << x << (i + 1 == n ? "\n" : " ");
        }
    }

    return 0;
}