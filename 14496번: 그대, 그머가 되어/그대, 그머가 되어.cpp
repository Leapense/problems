#include <iostream>
#include <vector>
#include <queue>
#include <climits>

int main()
{
    int start, end, n, m, a, b;
    std::cin >> start >> end >> n >> m;
    std::vector<std::vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i)
    {
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    std::vector<int> dist(n + 1, INT_MAX);
    std::queue<int> q;
    dist[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int next : graph[curr])
        {
            if (dist[next] == INT_MAX)
            {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }

    if (dist[end] == INT_MAX)
    {
        std::cout << -1 << std::endl;
    }
    else
    {
        std::cout << dist[end] << std::endl;
    }

    return 0;
}