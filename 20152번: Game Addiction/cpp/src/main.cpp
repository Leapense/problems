#include <iostream>
#include <cstdint>
#include <cmath>
#include <gtest/gtest.h>

using namespace std;

unsigned long long binomialCoefficient(int n)
{
    unsigned long long result = 1;

    for (int i = 1; i <= n; ++i)
    {
        result = result * (n + i) / i;
    }

    return result;
}

unsigned long long countPaths(int H, int N)
{
    if (H == N)
        return 1;

    int n = abs(N - H);
    return binomialCoefficient(n) / (n + 1);
}

#ifndef UNIT_TESTS
int main()
{
    int H, N;
    cin >> H >> N;
    cout << countPaths(H, N) << endl;

    return 0;
}
#endif