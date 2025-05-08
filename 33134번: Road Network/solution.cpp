#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> p, sz;

public:
    explicit DSU(int n) : p(n), sz(n, 1)
    {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x)
    {
        while (x != p[x])
        {
            p[x] = p[p[x]];
            x = p[x];
        }
        return x;
    }
    void unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return;
        if (sz[a] < sz[b])
            swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long N;

    if (!(cin >> N))
        return 0;
    DSU d(N);

    for (long long i = 0; i < N; ++i)
    {
        long long j = (3 * i + 7) % N;
        d.unite(i, j);
    }

    int root = d.find(0);
    for (int i = 1; i < N; ++i)
    {
        if (d.find(i) != root)
        {
            cout << "NO\n0 " << i << "\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}