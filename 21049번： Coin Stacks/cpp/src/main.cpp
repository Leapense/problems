#include "main.h"

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

std::pair<bool, std::vector<std::pair<int, int>>> solveCoinStacks(const std::vector<int> &coins)
{
    int n = coins.size();
    long long total = 0;
    for (int coin : coins)
    {
        total += coin;
    }

    if (total % 2 != 0)
        return {false, {}};

    int maxCoins = *max_element(coins.begin(), coins.end());
    if (maxCoins > total / 2)
        return {false, {}};

    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; ++i)
    {
        if (coins[i] > 0)
            pq.push({coins[i], i});
    }

    vector<pair<int, int>> moves;
    while (pq.size() >= 2)
    {
        auto top1 = pq.top();
        pq.pop();
        auto top2 = pq.top();
        pq.pop();

        moves.push_back({top1.second + 1, top2.second + 1});
        top1.first--;
        top2.first--;

        if (top1.first > 0)
        {
            pq.push(top1);
        }
        if (top2.first > 0)
        {
            pq.push(top2);
        }
    }

    if (!pq.empty())
        return {false, {}};

    return {true, moves};
}

#ifndef UNIT_TESTS
int main()
{
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> coins[i];
    }

    auto result = solveCoinStacks(coins);
    if (!result.first)
    {
        cout << "no\n";
    }
    else
    {
        cout << "yes\n";
        for (auto &move : result.second)
        {
            cout << move.first << " " << move.second << "\n";
        }
    }

    return 0;
}
#endif