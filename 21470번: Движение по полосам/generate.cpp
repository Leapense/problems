#include "testlib.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    std::string type = "random";
    if (argc > 1) {
        type = argv[1];
    }

    int m, n;
    if (type == "min") {
        m = 2;
        n = 1;
    } else if (type == "max") {
        m = 50;
        n = 15;
    } else if (type == "min_m_max_n") {
        m = 2;
        n = 15;
    } else if (type == "max_m_min_n") {
        m = 50;
        n = 1;
    } else {
        m = rnd.next(2, 50);
        n = rnd.next(1, 15);
    }
    printf("%d %d\n", m, n);

    return 0;
}