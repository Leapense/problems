#include "main.h"
#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>
using ull = unsigned long long;
bool convert(const std::string &s, int base, ull &value)
{
    __int128 res = 0;
    for (char c : s)
    {
        int d = (c >= '0' && c <= '9') ? c - '0' : c - 'a' + 10;
        if (d >= base)
            return false;
        res = res * base + d;
        if (res >= ((__int128)1 << 63))
            return false;
    }
    value = (ull)res;
    return true;
}
std::string solveCase(const std::string &input)
{
    std::istringstream iss(input);
    std::string s, t;
    iss >> s >> t;
    auto minBase = [&](const std::string &s) -> int
    {
        int m = 0;
        for (char c : s)
        {
            int d = (c >= '0' && c <= '9') ? c - '0' : c - 'a' + 10;
            m = std::max(m, d);
        }
        return std::max(2, m + 1);
    };
    int minA = minBase(s), minB = minBase(t);
    std::vector<std::tuple<ull, int, int>> sol;
    for (int a = minA; a <= 36; a++)
    {
        ull valA;
        if (!convert(s, a, valA))
            continue;
        for (int b = minB; b <= 36; b++)
        {
            if (a == b)
                continue;
            ull valB;
            if (!convert(t, b, valB))
                continue;
            if (valA == valB)
                sol.push_back({valA, a, b});
        }
    }
    if (sol.empty())
        return "Impossible";
    else if (sol.size() == 1)
    {
        auto [x, a, b] = sol[0];
        return std::to_string(x) + " " + std::to_string(a) + " " + std::to_string(b);
    }
    else
        return "Multiple";
}
#ifndef UNIT_TESTS
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s, t;
    std::cin >> s >> t;
    std::string input = s + " " + t;
    std::cout << solveCase(input);
    return 0;
}
#endif