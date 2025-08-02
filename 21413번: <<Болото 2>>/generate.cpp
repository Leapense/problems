#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n, a, b;
    int mode = rnd.next(0, 99);
    if (mode < 15) {
        n = rnd.next(4, 1000);
        int x = rnd.next(2, n-1);
        if (rnd.next(0, 1)) a = x, b = x + 1;
        else a = x, b = x - 1;
    } else if (mode < 35) {
        n = rnd.next(2, 1000);
        vector<int> ends = {1, 2, n - 1, n};
        a = ends[rnd.next((int)ends.size())];
        do { b = rnd.next(1, n); } while (b == a);
    } else {
        n = rnd.next(2, 1000);
        a = rnd.next(1, n);
        do { b = rnd.next(1, n); } while (b == a);
    }

    cout << n << ' ' << a << ' ' << b << '\n';
    return 0;
}