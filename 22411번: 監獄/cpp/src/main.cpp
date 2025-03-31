#include "main.h"
using ll = long long;

void solve(std::istream &in, std::ostream &out) {
    int N, k;
    in >> N >> k;
    ll ans = 0;

    for (int i = 0; i < N - 1; i++) {
        ans = ans + (ans / (k - 1)) + 1;
    }

    out << ans;
}

#ifndef UNIT_TESTS
#include <iostream>

int main() {
    solve(std::cin, std::cout);
    return 0;
}
#endif
