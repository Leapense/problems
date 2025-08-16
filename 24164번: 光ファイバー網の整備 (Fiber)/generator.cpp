#include "testlib.h"

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = rnd.next(1, 10000);
    int m = rnd.next(1, 30000);

    printf("%d %d\n", n, m);

    for (int i = 0; i < m; ++i) {
        int u = rnd.next(1, n);
        int v = rnd.next(1, n);
        while (u == v) {
            v = rnd.next(1, n);
        }
        printf("%d %d\n", u, v);
    }

    return 0;
}