#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    int S, E;
    cin >> S >> E;

    vector<vector<int>> tele(N + 1);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        tele[u].push_back(v);
        tele[v].push_back(u);
    }

    vector<int> dist(N + 1, -1);
    queue<int> q;

    dist[S] = 0;
    q.push(S);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (cur == E)
        {
            cout << dist[cur];
            return 0;
        }

        if (cur > 1 && dist[cur - 1] == -1)
        {
            dist[cur - 1] = dist[cur] + 1;
            q.push(cur - 1);
        }
        if (cur < N && dist[cur + 1] == -1)
        {
            dist[cur + 1] = dist[cur] + 1;
            q.push(cur + 1);
        }

        for (auto nxt : tele[cur])
        {
            if (dist[nxt] == -1)
            {
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
    }

    return 0;
}