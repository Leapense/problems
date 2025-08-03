#include "testlib.h"
#include <iostream>

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    std::string type = "random";
    if (argc > 1) {
        type = argv[1];
    }

    int n;
    long long k;

    if (type == "min") {
        n = 3;
        k = 1;
    } else if (type == "max") {
        n = 10;
        k = 100000000LL;
    } else if (type == "max_n_min_k") {
        n = 10;
        k = 1;
    } else if (type == "min_n_max_k") {
        n = 3;
        k = 100000000LL;
    } else {
        n = rnd.next(3, 10);
        k = rnd.next(1LL, 100000000LL);
    }

    printf("%d %lld\n", n, k);

    return 0;
}