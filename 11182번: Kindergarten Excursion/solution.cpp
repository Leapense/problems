#include <iostream>
#include <string>
#include <cstdint>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string line;
    if (!(std::cin >> line)) {
        return EXIT_FAILURE;
    }

    uint64_t countOnes = 0ULL;
    uint64_t countTwos = 0ULL;
    uint64_t inversionCount = 0ULL;

    for (char ch : line) {
        switch (ch) {
            case '0':
            inversionCount += countOnes;
            inversionCount += countTwos;
            break;
            case '1':
            inversionCount += countTwos;
            ++countOnes;
            break;
            case '2':
            ++countTwos;
            break;
            default:
            break;
        }
    }

    std::cout << inversionCount << "\n";
    return EXIT_SUCCESS;
}