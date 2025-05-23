#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    int N;
    std::cin >> N;

    std::map<std::string, int> groupCount;
    for (int i = 0; i < N; ++i) {
        std::vector<std::string> cows(3);
        std::cin >> cows[0] >> cows[1] >> cows[2];

        std::sort(cows.begin(), cows.end());

        std::string key = cows[0] + " " + cows[1] + " " + cows[2];

        groupCount[key]++;
    }

    int maxCount = 0;
    for (const auto &entry : groupCount) {
        if (entry.second > maxCount) {
            maxCount = entry.second;
        }
    }

    std::cout << maxCount;

    return 0;
}