#include <iostream>
#include <vector>
#include <string>
#include <ranges>
#include <algorithm>

class UnionFind
{
private:
    std::vector<int> parent, rank;

public:
    explicit UnionFind(int n) : parent(n + 1), rank(n + 1, 0)
    {
        for (int i = 1; i <= n; ++i)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    void unite(int x, int y)
    {
        int xr = find(x);
        int yr = find(y);
        if (xr == yr)
        {
            return;
        }

        if (rank[xr] < rank[yr])
        {
            parent[xr] = yr;
        }
        else
        {
            parent[yr] = xr;
            if (rank[xr] == rank[yr])
            {
                ++rank[xr];
            }
        }
    }

    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }
};

auto fast_io()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
}

int main()
{
    fast_io();

    int n, m, q;
    std::cin >> n >> m >> q;

    UnionFind uf(n);

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        uf.unite(a, b);
    }

    for (int i = 0; i < q; ++i)
    {
        int x, y;
        std::cin >> x >> y;
        std::cout << (uf.connected(x, y) ? 'Y' : 'N') << "\n";
    }

    return 0;
}