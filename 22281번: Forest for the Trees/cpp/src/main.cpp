#include "main.h"
#include <iostream>
#include <sstream>
#include <numeric>
#include <string>
#include <algorithm>

using ll = long long;

ll ceil_div(ll a, ll b) {
    return (a + b - 1) / b;
}

std::string solve_problem(const std::string &input) {
    std::istringstream iss(input);
    
    ll xb, yb;
    iss >> xb >> yb;
    
    ll x1, y1, x2, y2;
    iss >> x1 >> y1 >> x2 >> y2;

    ll g = std::gcd(xb, yb);
    ll step_x = xb / g;
    ll step_y = yb / g;

    if (g == 1) {
        return "Yes";
    }

    ll Lx = ceil_div(x1, step_x);
    ll Rx = x2 / step_x;
    ll Ly = ceil_div(y1, step_y);
    ll Ry = y2 / step_y;

    ll L = std::max(Lx, Ly);
    ll R = std::min(Rx, Ry);

    ll blocking_i = -1;
    if (L > 1) {
        blocking_i = 1;
    } else {
        if (R < g - 1) {
            blocking_i = R + 1;
        }
    }

    std::ostringstream oss;

    if (blocking_i == -1) {
        oss << "Yes";
    } else {
        oss << "No\n" << (step_x * blocking_i) << " " << (step_y * blocking_i);
    }

    return oss.str();
}

#ifndef UNIT_TESTS
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string input;
    std::string line;

    while (getline(std::cin, line)) {
        input += line + "\n";
    }

    std::cout << solve_problem(input);

    return 0;
}
#endif
