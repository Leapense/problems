#include <iostream>
#include <cstdlib>
#include "main.h"

using namespace std;

int minimumJumps(long long K) {
    if (K == 0) return 0;

    if (K % 2 == 0) return -1;

    K = (K < 0 ? -K : K);

    int jumps = 0;
    long long sum = 0;

    while (sum < K) {
        jumps++;
        sum = (1LL << jumps) - 1;
    }

    return jumps;
}

#ifndef UNIT_TESTS
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long K;
    cin >> K;

    cout << minimumJumps(K);

    return 0;
}
#endif
