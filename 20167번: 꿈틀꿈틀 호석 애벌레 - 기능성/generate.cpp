#include "testlib.h"
#include <iostream>
#include <vector>
#include <numeric>

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 0);

    int n_max = 20;
    int k_max = 100;
    int values_max = 100;

    int n = rnd.next(1, n_max);
    int k = rnd.next(1, k_max);

    std::cout << n << " " << k << std::endl;
    std::vector<int> values;
    for (int i = 0; i < n; ++i) {
        values.push_back(rnd.next(1, values_max));
    }

    for (int i = 0; i < n; ++i) {
        std::cout << values[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << std::endl;

    return 0;
}