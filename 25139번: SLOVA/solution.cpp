#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <cmath>

class PermutationDistance {
    private:
    std::vector<uint64_t> factorial;
    void computeFactorials(int n) {
        factorial.resize(n + 1);
        factorial[0] = 1;
        for (int i = 1; i <= n; ++i) {
            factorial[i] = factorial[i - 1] * i;
        }
    }

    uint64_t getLexicographicRank(const std::string& word) {
        uint64_t rank = 0;
        int n = word.length();
        std::vector<bool> used(26, false);
        for (int i = 0; i < n; ++i) {
            int currentChar = word[i] - 'a';
            int smallerCount = 0;
            for (int j = 0; j < currentChar; ++j) {
                if (!used[j]) {
                    ++smallerCount;
                }
            }

            rank += smallerCount * factorial[n - i - 1];
            used[currentChar] = true;
        }
        return rank;
    }
    public:
    uint64_t calculateDistance(int n, const std::string& wordA, const std::string& wordB) {
        computeFactorials(n);
        uint64_t rankA = getLexicographicRank(wordA);
        uint64_t rankB = getLexicographicRank(wordB);

        return std::abs(static_cast<int64_t>(rankA) - static_cast<int64_t>(rankB));
    }
};

int main()
{
    int n;
    std::string wordA, wordB;

    std::cin >> n >> wordA >> wordB;

    PermutationDistance solver;
    uint64_t distance = solver.calculateDistance(n, wordA, wordB);

    std::cout << distance << std::endl;

    return 0;
}