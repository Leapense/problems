#include <iostream>
#include <cassert>

using namespace std;

auto solve(unsigned long long k) -> int
{
    unsigned long long n = k - 1;
    int cnt = 0;

    while (n)
    {
        cnt += n & 1;
        n >>= 1;
    }

    return (cnt & 1) ? 1 : 0;
}

#ifndef UNIT_TEST
int main()
{
    unsigned long long k;
    cin >> k;
    cout << solve(k);
    return 0;
}
#else
int main()
{
    assert(solve(1) == 0);
    assert(solve(2) == 1);
    assert(solve(10) == 0);
    return 0;
}
#endif