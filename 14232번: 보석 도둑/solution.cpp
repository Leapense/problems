#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <print>

void solve() {
    long long k;
    if (!(std::cin >> k)) {
        return;
    }

    std::vector<long long> factors;
    long long temp_k = k;

    while (temp_k % 2 == 0) {
        factors.push_back(2);
        temp_k /= 2;
    }

    for (long long i = 3; i * i <= temp_k; i += 2) {
        while (temp_k % i == 0) {
            factors.push_back(i);
            temp_k /= i;
        }
    }

    if (temp_k > 1) {
        factors.push_back(temp_k);
    }

    std::print("{}\n", factors.size());
    for (size_t i = 0; i < factors.size(); ++i) {
        std::print("{} ", factors[i]);
    }

    std::println("");
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}