#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    const int A_max = opt<int>("maxA", 30);
    const int B_max = opt<int>("maxB", 30);
    const int C_max = opt<int>("maxC", 30);
    const int T     = opt<int>("cases", 100);

    println(T);

    for (int tc = 0; tc < T; ++tc) {
        int a, b, c;
        int bucket = rnd.next(100);

        if (bucket < 5) {
            a = b = c = 1;
        } else if (bucket < 20) {
            a = 1;
            b = rnd.next(1, B_max);
            c = rnd.next(1, C_max);
        } else if (bucket < 35) {
            c = C_max;
            a = rnd.next(1, A_max);
            b = rnd.next(1, B_max);
        } else if (bucket < 50) {
            b = B_max;
            a = rnd.next(1, A_max);
            c = rnd.next(1, C_max);
        } else if (bucket < 55) {
            a = A_max; b = B_max; c = C_max;
        } else {
            a = rnd.next(1, A_max);
            b = rnd.next(1, B_max);
            c = rnd.next(1, C_max);
        }
        println(a, b, c);
    }

    return 0;
}