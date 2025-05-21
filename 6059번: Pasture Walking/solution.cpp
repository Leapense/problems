#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 1000;
static const int LOGN = 10;

int N, Q;
vector<pair<int, int>> adj[MAXN + 1];
int up[LOGN + 1][MAXN + 1], depthArr[MAXN + 1];
long long distToRoot[MAXN + 1];

void dfs(int u, int p)
{
    up[0][u] = p;
    for (auto [v, w] : adj[u])
    {
        if (v == p)
            continue;
        depthArr[v] = depthArr[u] + 1;
        distToRoot[v] = distToRoot[u] + w;
        dfs(v, u);
    }
}

int lca(int u, int v)
{
    if (depthArr[u] < depthArr[v])
        swap(u, v);
    int diff = depthArr[u] - depthArr[v];
    for (int k = 0; k <= LOGN; ++k)
    {
        if (diff & (1 << k))
        {
            u = up[k][u];
        }
    }
    if (u == v)
        return u;
    for (int k = LOGN; k >= 0; --k)
    {
        if (up[k][u] != up[k][v])
        {
            u = up[k][u];
            v = up[k][v];
        }
    }

    return up[0][u];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;
    for (int i = 1; i <= N - 1; i++)
    {
        int A, B, L;
        cin >> A >> B >> L;
        adj[A].emplace_back(B, L);
        adj[B].emplace_back(A, L);
    }

    depthArr[1] = 0;
    distToRoot[1] = 0;
    dfs(1, 1);

    for (int k = 1; k <= LOGN; k++)
    {
        for (int v = 1; v <= N; v++)
        {
            up[k][v] = up[k - 1][up[k - 1][v]];
        }
    }

    while (Q--)
    {
        int u, v;
        cin >> u >> v;
        int w = lca(u, v);
        long long answer = distToRoot[u] + distToRoot[v] - 2LL * distToRoot[w];
        cout << answer << "\n";
    }

    return 0;
}