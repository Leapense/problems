#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

struct DSU
{
    vector<int> parent, size;
    DSU(int n) : parent(n), size(n, 1)
    {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y)
    {
        int fx = find(x), fy = find(y);
        if (fx == fy)
            return;
        if (size[fx] < size[fy])
            swap(fx, fy);
        parent[fy] = fx;
        size[fx] += size[fy];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> owes(n);
    for (int i = 0; i < n; ++i)
        cin >> owes[i];

    DSU dsu(n);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        dsu.unite(x, y);
    }

    vector<long long> component_sum(n, 0);
    for (int i = 0; i < n; ++i)
    {
        component_sum[dsu.find(i)] += owes[i];
    }

    for (int i = 0; i < n; ++i)
    {
        if (dsu.find(i) == i && component_sum[i] != 0)
        {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    cout << "POSSIBLE\n";
    return 0;
}