#include <testlib.h>
#include <iostream>

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int N = rnd.next(1, 2000);
    int A = rnd.next(1, 2000);
    int B = rnd.next(1, 2000);

    if (2LL * B + A < N) {
        int need = N - (2 * B + A);
        A += need;
        if (A > 2000) {
            A = 2000;
        }
    }

    std::cout << N << ' ' << A << ' ' << B << '\n';
    for (int i = 0; i < A; ++i) {
        std::cout << rnd.next(1, 1000000) << (i + 1 < A ? ' ' : '\n');
    }

    for (int i = 0; i < B; ++i) {
        std::cout << rnd.next(1, 1000000) << (i + 1 < B ? ' ' : '\n');
    }

    return 0;
}