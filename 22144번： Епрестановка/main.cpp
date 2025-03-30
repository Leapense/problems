#include <iostream>
#include <vector>

using namespace std;

struct UnionFind {
    vector<int> parent;

    UnionFind(int n) : parent(n + 1) {
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int a) {
        if (parent[a] != a) {
            parent[a] = find(parent[a]);
        }

        return parent[a];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a != b) {
            parent[b] = a;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    UnionFind uf(n);

    for (int i = 1; i <= n; ++i) {
        uf.unite(i, p[i]);
    }

    uf.unite(1, 2);

    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << (uf.find(a) == uf.find(b) ? "Yes" : "No") << "\n";
    }

    return 0;
}
