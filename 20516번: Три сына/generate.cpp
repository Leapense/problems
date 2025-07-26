#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    long long N_MAX = atoll(argv[2]);
    const long long N_MIN = 3;

    ensure(N_MAX >= N_MIN);

    long long n = rnd.next(N_MIN, N_MAX);
    println(n);
    return 0;
}