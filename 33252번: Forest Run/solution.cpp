#include <bits/stdc++.h>
using namespace std;

long long compute_distance(int n, const vector<int> &entrances, const vector<vector<int>> &children)
{
    vector<char> visited(n + 1);
    long long ans = 0;
    vector<pair<int, int>> q;
    q.reserve(n);

    for (int r : entrances)
        q.emplace_back(r, 0);
    size_t head = 0;
    while (head < q.size())
    {
        auto [u, d] = q[head++];
        if (visited[u])
            continue;
        visited[u] = 1;
        const auto &ch = children[u];
        if (ch.empty())
            ans += 2LL * d;
        else
            for (int v : ch)
                if (!visited[v])
                    q.emplace_back(v, d + 1);
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, e;
    if (!(cin >> n >> e))
        return 0;

    vector<int> entrances(e);
    for (int i = 0; i < e; ++i)
        cin >> entrances[i];

    vector<vector<int>> children(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        int c;
        cin >> c;

        children[i].resize(c);
        for (int j = 0; j < c; ++j)
            cin >> children[i][j];
    }
    cout << compute_distance(n, entrances, children) << "\n";
    return 0;
}