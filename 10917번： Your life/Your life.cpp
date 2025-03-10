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

    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
    }
    vector<int> dist(N + 1, -1);
    queue<int> q;
    dist[1] = 0;
    q.push(1);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto next : graph[cur])
        {
            if (dist[next] == -1)
            {
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
    cout << dist[N];
    return 0;
}