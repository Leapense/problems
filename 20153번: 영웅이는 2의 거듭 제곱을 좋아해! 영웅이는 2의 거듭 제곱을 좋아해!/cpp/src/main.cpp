#include <iostream>
#include <vector>
#include "main.h"

std::string solve(const std::vector<int> &A)
{
    int xorAll = 0;
    for (int a : A)
    {
        xorAll ^= a;
    }
    int best = xorAll;
    for (int a : A)
    {
        best = std::max(best, xorAll ^ a);
    }

    std::string result = std::to_string(best);
    return result + result;
}

#ifndef UNIT_TESTS
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        std::cin >> A[i];
    }

    std::cout << solve(A);
    return 0;
}
#endif