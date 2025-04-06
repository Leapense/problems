#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M, R;
    std::cin >> N >> M >> R;

    std::vector<std::vector<int>> graph(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v;
        std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        std::sort(graph[i].begin(), graph[i].end());
    }

    std::vector<int> order(N + 1, 0);
    int cnt = 1;

    std::stack<int> s;
    s.push(R);

    while (!s.empty()) {
        int cur = s.top();
        s.pop();

        if (order[cur] != 0) continue;
        order[cur] = cnt++;

        for (auto it = graph[cur].rbegin(); it != graph[cur].rend(); it++) {
            if (order[*it] == 0) {
                s.push(*it);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        std::cout << order[i] << "\n";
    }

    return 0;
}
