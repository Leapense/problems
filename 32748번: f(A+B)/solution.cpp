#include <iostream>
#include <vector>
#include <cstdint>

int main() {
    std::vector<int> f(10);
    std::vector<int> f_inv(10);
    for (int i = 0; i < 10; ++i) {
        std::cin >> f[i];
        f_inv[f[i]] = i;
    }

    int64_t f_a, f_b;
    std::cin >> f_a >> f_b;

    std::vector<int> a_digits, b_digits;
    while (f_a > 0) {
        a_digits.push_back(f_inv[f_a % 10]);
        f_a /= 10;
    }
    while (f_b > 0) {
        b_digits.push_back(f_inv[f_b % 10]);
        f_b /= 10;
    }

    int64_t a = 0, b = 0;
    for (auto it = a_digits.rbegin(); it != a_digits.rend(); ++it) {
        a = a * 10 + *it;
    }
    for (auto it = b_digits.rbegin(); it != b_digits.rend(); ++it) {
        b = b * 10 + *it;
    }

    int64_t sum = a + b;
    std::vector<int> sum_digits;
    while (sum > 0) {
        sum_digits.push_back(f[sum % 10]);
        sum /= 10;
    }

    int64_t result = 0;
    for (auto it = sum_digits.rbegin(); it != sum_digits.rend(); ++it) {
        result = result * 10 + *it;
    }

    std::cout << result << "\n";
    return 0;
}