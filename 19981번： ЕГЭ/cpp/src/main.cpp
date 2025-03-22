#include "main.h"
#include <iostream>
#include <cassert>
#include <sstream>

#ifdef UNIT_TESTS
#include <gtest/gtest.h>
#endif

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