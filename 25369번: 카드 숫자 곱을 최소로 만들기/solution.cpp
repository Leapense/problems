#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    if (!(std::cin >> n)) {
        return 0;
    }

    const int MIN_DIGIT = 1;
    const int MAX_DIGIT = 9;

    long long target = 1;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        target *= x;
    }

    std::vector<long long> maxDigitPowers(static_cast<size_t>(n + 1), 1);
    for (int i = 1; i <= n; i++) {
        maxDigitPowers[static_cast<size_t>(i)] = maxDigitPowers[static_cast<size_t>(i - 1)] * MAX_DIGIT;
    }
    if (maxDigitPowers[static_cast<size_t>(n)] <= target) {
        std::cout << -1 << "\n";
        return 0;
    }

    std::vector<int> result(static_cast<size_t>(n));
    long long currentProduct = 1;
    int prevDigit = MIN_DIGIT;

    for (int pos = 0; pos < n; pos++) {
        int remaining = n - pos - 1;
        for (int d = prevDigit; d <= MAX_DIGIT; d++) {
            long long maxPossible = currentProduct * d * maxDigitPowers[static_cast<size_t>(remaining)];
            if (maxPossible > target) {
                result[static_cast<size_t>(pos)] = d;
                currentProduct *= d;
                prevDigit = d;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            std::cout << ' ';
        }
        std::cout << result[static_cast<size_t>(i)];
    }
    std::cout << '\n';
    return 0;
}