#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> coins(n);
    long long total = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> coins[i];
        total += coins[i];
    }

    if (total % 2 != 0)
    {
        cout << "no\n";
        return 0;
    }

    int maxCoins = *max_element(coins.begin(), coins.end());
    if (maxCoins > total / 2)
    {
        cout << "no\n";
        return 0;
    }

    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; ++i)
    {
        if (coins[i] > 0)
        {
            pq.push({coins[i], i});
        }
    }

    vector<pair<int, int>> moves;

    while (pq.size() >= 2)
    {
        auto [c1, i1] = pq.top();
        pq.pop();
        auto [c2, i2] = pq.top();
        pq.pop();

        moves.push_back({i1 + 1, i2 + 1});
        --c1;
        --c2;

        if (c1 > 0)
        {
            pq.push({c1, i1});
        }
        if (c2 > 0)
        {
            pq.push({c2, i2});
        }
    }

    if (!pq.empty())
    {
        cout << "no\n";
        return 0;
    }

    cout << "yes\n";

    for (auto &move : moves)
    {
        cout << move.first << " " << move.second << "\n";
    }

    return 0;
}