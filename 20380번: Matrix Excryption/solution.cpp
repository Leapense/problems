#include <iostream>
#include <vector>
#include <string>

namespace {
    constexpr int kAlphabet = 30;

    int toValue(char c) {
        if ('A' <= c && c <= 'Z') return c - 'A' + 1;
        if (c == ' ') return 27;
        if (c == ',') return 28;
        if (c == '.') return 29;
        return 30;
    }

    char toChar(int v) {
        if (v >= 1 && v <= 26) return static_cast<char>('A' + v - 1);
        return v == 27 ? ' ' : v == 28 ? ',' : v == 29 ? '.' : '?';
    }

    int mod30(int x) {
        int v = x % kAlphabet;
        if (v <= 0) v += kAlphabet;
        return v;
    }
} // namespace

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int d;
    while (std::cin >> d && d != 0) {
        std::vector<std::vector<int>> mat(d, std::vector<int>(d));
        for (auto& row : mat) {
            for (int& cell : row) {
                std::cin >> cell;
            }
        }

        std::string line;
        std::getline(std::cin, line);
        std::getline(std::cin, line);

        std::vector<int> vals;
        vals.reserve(line.size());
        for (char c : line) vals.push_back(toValue(c));
        while (vals.size() % static_cast<size_t>(d) != 0) vals.push_back(27);

        std::string results;
        results.reserve(vals.size());

        for (size_t idx = 0; idx < vals.size(); idx += d) {
            for (int r = 0; r < d; ++r) {
                long long sum = 0;
                for (int c = 0; c < d; ++c) {
                    sum += static_cast<long long>(mat[r][c]) * vals[idx + c];
                }
                results.push_back(toChar(mod30(static_cast<int>(sum))));
            }
        }

        std::cout << '\'' << results << '\'' << std::endl;
    }

    return 0;
}