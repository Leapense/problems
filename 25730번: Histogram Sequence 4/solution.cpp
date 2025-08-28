#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned long long N, A, L, R;
    if (!(std::cin >> N >> A >> L >> R)) return 0;

    if (A == 0) {
        if (L == 0) {
            std::cout << "YES\n";
            for (unsigned long long i = 0; i < N; ++i) {
                std::cout << 0 << (i + 1 == N ? '\n' : ' ');
            }
        } else {
            std::cout << "NO\n";
        }
        return 0;
    }

    __uint128_t n128 = (__uint128_t)N;
    __uint128_t a128 = (__uint128_t)A;
    __uint128_t l128 = (__uint128_t)L;
    __uint128_t r128 = (__uint128_t)R;

    if (a128 < l128 * n128) {
        std::cout << "NO\n";
        return 0;
    }
    if (a128 > r128 * n128) {
        std::cout << "NO\n";
        return 0;
    }
    if (R == 0) {
        std::cout << "NO\n";
        return 0;
    }

    auto ceil_div = [](unsigned long long a, unsigned long long b) -> unsigned long long {
        return (a + b - 1) / b;
    };
    auto floor_div = [](unsigned long long a, unsigned long long b) -> unsigned long long {
        return a / b;
    };

    unsigned long long w_lo = std::max(1ULL, ceil_div(A, R));
    unsigned long long w_hi = N;
    if (L > 0) {
        unsigned long long t = floor_div(A, L);
        if (t < w_hi) w_hi = t;
    }

    if (w_lo > w_hi) {
        std::cout << "NO\n";
        return 0;
    }

    unsigned long long w = 0, h = 0;
    for (unsigned long long x = w_lo; x <= w_hi; ++x) {
        if (A % x == 0) {
            unsigned long long hh = A / x;
            if (hh >= L && hh <= R) {
                w = x;
                h = hh;
                break;
            }
        }
    }

    if (w == 0) {
        std::cout << "NO\n";
        return 0;
    }

    std::cout << "YES\n";
    for (unsigned long long i = 0; i < N; ++i) {
        unsigned long long val = (i < w) ? h : L;
        std::cout << val << (i + 1 == N ? '\n' : ' ');
    }
    return 0;
}