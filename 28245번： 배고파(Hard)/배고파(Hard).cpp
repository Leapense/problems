#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

class MenuSelector
{
public:
    struct Entry
    {
        ull sum;
        int x, y;
    };

    vector<Entry> entries;
    MenuSelector()
    {
        for (int x = 0; x <= 61; x++)
        {
            for (int y = x; y <= 61; y++)
            {
                ull sum = (1ULL << x) + (1ULL << y);
                entries.push_back({sum, x, y});
            }
        }

        sort(entries.begin(), entries.end(), [](const Entry &a, const Entry &b)
             { return a.sum < b.sum; });
    }

    pair<int, int> getMenu(ull m)
    {
        int lo = 0, hi = entries.size();
        while (lo < hi)
        {
            int mid = (lo + hi) / 2;
            if (entries[mid].sum < m)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid;
            }
        }

        pair<ull, pair<int, int>> candidate = {~0ULL, {0, 0}};
        if (lo < entries.size())
        {
            ull diff = entries[lo].sum - m;
            candidate = {diff, {entries[lo].x, entries[lo].y}};
        }

        if (lo > 0)
        {
            ull diff = m - entries[lo - 1].sum;
            if (diff < candidate.first)
            {
                candidate = {diff, {entries[lo - 1].x, entries[lo - 1].y}};
            }
            else if (diff == candidate.first && entries[lo - 1].sum < (unsigned long long)((1ULL << candidate.second.first) + (1ULL << candidate.second.second)))
            {
                candidate = {diff, {entries[lo - 1].x, entries[lo - 1].y}};
            }
        }

        return candidate.second;
    }
};

class Solution
{
public:
    void solve()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n;
        cin >> n;

        MenuSelector selector;

        while (n--)
        {
            unsigned long long m;
            cin >> m;

            pair<int, int> res = selector.getMenu(m);
            cout << res.first << " " << res.second << "\n";
        }
    }
};

int main()
{
    Solution sol;
    sol.solve();

    return 0;
}