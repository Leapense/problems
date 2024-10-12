#include <bits/stdc++.h>

int main() {
    int n; // Number of test cases
    std::cin >> n;

    for (int testCase = 1; testCase <= n; ++testCase) {
        int m; // Number of rounds
        std::cin >> m;

        int tessaScore = 0;
        int dannyScore = 0;

        for (int round = 0; round < m; ++round) {
            int tessaCard, dannyCard;
            std::cin >> tessaCard >> dannyCard;

            if (std::abs(tessaCard - dannyCard) == 1) {
                if (tessaCard > dannyCard) {
                    if (tessaCard == 2)
                        dannyScore += 6;
                    else
                        dannyScore += tessaCard + dannyCard;
                } else {
                    if (dannyCard == 2)
                        tessaScore += 6;
                    else
                        tessaScore += tessaCard + dannyCard;
                }
            } else if (tessaCard > dannyCard) {
                tessaScore += tessaCard;
            } else if (dannyCard > tessaCard) {
                dannyScore += dannyCard;
            }
        }

        std::cout << "Game " << testCase << ": Tessa " << tessaScore << " Danny " << dannyScore << std::endl;
    }

    return 0;
}