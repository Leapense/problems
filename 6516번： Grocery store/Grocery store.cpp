#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> solutions;

    for (int a = 1; a <= 500; ++a) {
        for (int b = a; b <= (2000 - a) / 3; ++b) {
            for (int c = b; c <= (2000 - a - b) / 2; ++c) {
                long long numerator = 1000000LL * (a + b + c);
                long long denominator = (long long)a * b * c - 1000000LL;

                if (denominator <= 0) continue;
                if (numerator % denominator != 0) continue;

                long long d = numerator / denominator;

                if (d < c) continue;
                if (d > 2000) continue;
                if (a + b + c + d > 2000) continue;

                if (d != (long long) d) continue;

                solutions.push_back({a, (int)b, (int)c, (int)d});
            }
        }
    }

    sort(solutions.begin(), solutions.end());
    solutions.erase(unique(solutions.begin(), solutions.end()), solutions.end());

    for (auto &quad : solutions) {
        double price1 = quad[0] / 100.0;
        double price2 = quad[1] / 100.0;
        double price3 = quad[2] / 100.0;
        double price4 = quad[3] / 100.0;

        printf("%.2lf %.2lf %.2lf %.2lf\n", price1, price2, price3, price4);
    }

    return 0;
}