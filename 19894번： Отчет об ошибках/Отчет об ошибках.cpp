#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <limits>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> f(m);

    for (int i = 0; i < m; i++)
    {
        cin >> f[i];
    }

    if (m <= 1)
    {
        cout << 0 << "\n";
        return 0;
    }

    auto getEdges = [&](const set<int> &allowed) -> set<pair<int, int>>
    {
        set<pair<int, int>> edges;
        for (int i = 0; i < m - 1; i++)
        {
            if (allowed.find(f[i + 1]) == allowed.end())
            {
                edges.insert({f[i + 1], f[i]});
            }
        }
        return edges;
    };

    set<int> allowed1 = {f[0]};
    auto edges1 = getEdges(allowed1);
    size_t bestCost = edges1.size();
    set<int> bestAllowed = allowed1;
    set<pair<int, int>> bestEdges = edges1;

    for (int Y = 1; Y <= n; Y++)
    {
        if (Y == f[0])
            continue;
        set<int> allowed = {f[0], Y};
        auto edges = getEdges(allowed);
        if (edges.size() < bestCost)
        {
            bestCost = edges.size();
            bestAllowed = allowed;
            bestEdges = edges;
        }
    }

    cout << bestEdges.size() << "\n";
    for (auto &edge : bestEdges)
    {
        cout << edge.first << " " << edge.second << "\n";
    }

    return 0;
}