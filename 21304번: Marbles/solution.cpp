#include <iostream>
#include <cmath>
#include <cstdint>

int main()
{
    std::int64_t p, q;
    int N, M;
    if (!(std::cin >> p >> q >> N >> M)) {
        return 1;
    }

    for (int S = N; S <= M; ++S) {
        std::int64_t numerator = p * S * (S - 1);
        std::int64_t denom = 2 * q;
        if (numerator % denom != 0) {
            continue;
        }

        std::int64_t X = numerator / denom;
        std::int64_t D = static_cast<std::int64_t>(S) * S - 4 * X;
        if (D < 0) {
            continue;
        }

        std::int64_t sqrtD = static_cast<std::int64_t>(std::lround(std::sqrt(static_cast<long double>(D))));
        if (sqrtD * sqrtD != D || ((S - sqrtD) % 2) != 0) {
            continue;
        }

        std::int64_t r = (S - sqrtD) / 2;
        std::int64_t g = S - r;
        if (r >= 1 && r <= g) {
            std::cout << r << ' ' << g << '\n';
            return 0;
        }
    }

    std::cout << "NO SOLUTION\n";
    return 0;
}