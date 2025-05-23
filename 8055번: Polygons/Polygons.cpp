#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int m = n - 2;
    vector<array<int, 3>> tris(m);
    for (int i = 0; i < m; i++)
    {
        cin >> tris[i][0] >> tris[i][1] >> tris[i][2];
    }
    auto isBoundary = [&](int a, int b) -> bool
    {
        if (a > b)
            swap(a, b);
        return (a == 0 && b == n - 1) || (b - a == 1);
    };
    unordered_map<long long, int> edgeOwner;
    auto encode = [&](int a, int b) -> long long
    {
        if (a > b)
            swap(a, b);
        return ((long long)a << 32) | b;
    };
    vector<vector<int>> graph(m);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int a = tris[i][j], b = tris[i][(j + 1) % 3];
            if (isBoundary(a, b))
                continue;
            long long key = encode(a, b);
            if (edgeOwner.find(key) == edgeOwner.end())
            {
                edgeOwner[key] = i;
            }
            else
            {
                int other = edgeOwner[key];
                graph[i].push_back(other);
                graph[other].push_back(i);
            }
        }
    }
    if (graph[0].size() <= 1)
    {
        cout << "TAK";
        return 0;
    }
    vector<int> parent(m, -1);
    vector<int> sizeSub(m, 0);
    function<void(int, int)> dfs = [&](int cur, int par)
    {
        parent[cur] = par;
        int cnt = 1;
        for (auto nxt : graph[cur])
        {
            if (nxt == par)
                continue;
            dfs(nxt, cur);
            cnt += sizeSub[nxt];
        }
        sizeSub[cur] = cnt;
    };
    for (auto child : graph[0])
    {
        dfs(child, 0);
    }
    int xorVal = 0;
    for (auto child : graph[0])
    {
        xorVal ^= (sizeSub[child] & 1);
    }
    cout << (xorVal ? "TAK" : "NIE");
    return 0;
}
