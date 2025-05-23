#include "main.h"
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

#ifndef UNIT_TESTS
int main()
{
    std::string input, line;
    while (std::getline(std::cin, line))
    {
        input += line + "\n";
    }

    std::cout << solve(input);
    return 0;
}
#endif

std::string solve(const std::string &input)
{
    std::istringstream iss(input);
    int N, K;
    iss >> N >> K;
    iss.ignore();

    std::unordered_map<std::string, std::pair<int, int>> mp;

    for (int i = 0; i < 3 * N; i++)
    {
        std::string item;
        std::getline(iss, item);
        if (mp.find(item) == mp.end())
        {
            mp[item] = {1, i};
        }
        else
        {
            mp[item].first++;
            mp[item].second = i;
        }
    }

    std::vector<std::pair<std::string, std::pair<int, int>>> items;
    items.reserve(mp.size());

    for (auto &p : mp)
    {
        items.push_back({p.first, p.second});
    }

    std::sort(items.begin(), items.end(), [](auto &a, auto &b)
              {
        if (a.second.first == b.second.first) return a.second.second > b.second.second;
        return a.second.first > b.second.first; });

    std::ostringstream oss;
    int outputCount = std::min(K, static_cast<int>(items.size()));

    for (int i = 0; i < outputCount; i++)
    {
        oss << items[i].first;
        if (i < outputCount - 1)
            oss << "\n";
    }

    return oss.str();
}