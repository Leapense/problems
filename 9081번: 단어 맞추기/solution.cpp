#include <algorithm>
#include <iostream>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int testCount = 0;
    if (!(std::cin >> testCount))
    {
        return 1;
    }

    while (testCount-- > 0) {
        std::string originalWord;
        std::cin >> originalWord;
        std::string candidate = originalWord;

        bool hasNext = std::next_permutation(candidate.begin(), candidate.end());
        const std::string &result = hasNext ? candidate : originalWord;
        std::cout << result << "\n";
    }

    return 0;
}