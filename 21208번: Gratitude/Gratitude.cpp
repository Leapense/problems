#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;

    cin.ignore();
    unordered_map<string, pair<int, int>> mp;

    for (int i = 0; i < 3 * N; i++)
    {
        string line;
        getline(cin, line);
        if (mp.find(line) == mp.end())
        {
            mp[line] = {1, i};
        }
        else
        {
            mp[line].first++;
            mp[line].second = i;
        }
    }

    vector<pair<string, pair<int, int>>> items;
    items.reserve(mp.size());

    for (auto &p : mp)
    {
        items.push_back({p.first, p.second});
    }

    sort(items.begin(), items.end(), [](auto &a, auto &b)
         {
        if (a.second.first == b.second.first) return a.second.second > b.second.second;
        return a.second.first > b.second.first; });

    int outputCount = min(K, (int)items.size());
    for (int i = 0; i < outputCount; i++)
    {
        cout << items[i].first << "\n";
    }

    return 0;
}