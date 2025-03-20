#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;

        graph[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
            graph[i][j]--;
        }
    }

    vector<bool> visited(n, false);
    vector<int> dist(n, numeric_limits<int>::max());
    queue<int> q;

    visited[0] = true;
    dist[0] = 1;
    q.push(0);

    int shortest = numeric_limits<int>::max();

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (graph[cur].empty())
        {
            if (dist[cur] < shortest)
                shortest = dist[cur];
        }

        for (auto nxt : graph[cur])
        {
            if (!visited[nxt])
            {
                visited[nxt] = true;
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
    }

    bool allReachable = true;
    for (auto v : visited)
        if (!v)
        {
            allReachable = false;
            break;
        }
    cout << (allReachable ? "Y" : "N") << "\n";
    cout << shortest << "\n";
    return 0;
}