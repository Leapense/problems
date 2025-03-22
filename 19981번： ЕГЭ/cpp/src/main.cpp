#include "main.h"
#include <iostream>
#include <cassert>
#include <sstream>

using namespace std;

std::vector<int> convertToNegativeBase2(long long x)
{
    std::vector<int> digits;

    if (x == 0)
    {
        digits.push_back(0);
        return digits;
    }

    while (x != 0)
    {
        long long r = x % -2;
        x /= -2;

        if (r < 0)
        {
            r += 2;
            x += 1;
        }

        digits.push_back(static_cast<int>(r));
    }

    return digits;
}

#ifndef UNIT_TESTS
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x;
    cin >> x;

    vector<int> digits = convertToNegativeBase2(x);

    cout << digits.size() << "\n";

    for (size_t i = 0; i < digits.size(); i++)
    {
        cout << digits[i] << (i + 1 < digits.size() ? " " : "\n");
    }

    return 0;
}
#endif