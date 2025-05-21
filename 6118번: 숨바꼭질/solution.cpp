#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> graph(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    std::vector<int> dist(n + 1, -1);
    std::queue<int> q;
    dist[1] = 0;
    q.push(1);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int neighbor : graph[curr])
        {
            if (dist[neighbor] == -1)
            {
                dist[neighbor] = dist[curr] + 1;
                q.push(neighbor);
            }
        }
    }

    int maxDist = *std::max_element(dist.begin() + 1, dist.end());
    int minBarn = 0, count = 0;

    for (int i = 1; i <= n; ++i)
    {
        if (dist[i] == maxDist)
        {
            if (minBarn == 0)
                minBarn = i;
            ++count;
        }
    }

    std::cout << minBarn << ' ' << maxDist << ' ' << count << '\n';

    return 0;
}