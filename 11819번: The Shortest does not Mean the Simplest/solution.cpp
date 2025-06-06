#include <cstdint>
#include <iostream>

static unsigned long long modularPower(unsigned long long base, unsigned long long exponent, unsigned long long modulus) {
    unsigned long long result = 1ULL;
    unsigned long long curBase = base % modulus;

    while (exponent > 0ULL) {
        if ((exponent & 1ULL) == 1ULL) {
            __int128 temp = static_cast<__int128>(result) * curBase;
            result = static_cast<unsigned long long>(temp % modulus);
        }

        __int128 square = static_cast<__int128>(curBase) * curBase;
        curBase = static_cast<unsigned long long>(square % modulus);

        exponent >>= 1;
    }

    return result;
}

int main()
{
    unsigned long long A = 0ULL;
    unsigned long long B = 0ULL;
    unsigned long long C = 0ULL;

    if (!(std::cin >> A >> B >> C)) {
        return 1;
    }

    unsigned long long answer = modularPower(A, B, C);
    std::cout << answer << "\n";

    return 0;
}