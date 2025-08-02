#include "testlib.h"
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int t = rnd.next(1, 10);
    std::cout << t << std::endl;

    while (t--) {
        int n_max = 1000;
        int n = rnd.next(1, n_max);
        std::cout << n << std::endl;

        std::vector<int> a(n);

        int val_max = 250000;
        for (int i = 0; i < n; ++i) {
            a[i] = rnd.next(1, val_max);
        }

        for (int i = 0; i < n; ++i) {
            std::cout << a[i] << (i == n - 1 ? "" : " ");
        }

        std::cout << std::endl;
    }

    return 0;
}