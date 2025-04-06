#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, R;
    cin >> N >> M >> R;

    vector<vector<int>> graph(N + 1);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    vector<int> order(N + 1, 0);
    vector<int> depth(N + 1, -1);

    queue<int> q;
    order[R] = 1;
    depth[R] = 0;
    q.push(R);

    int visitCounter = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (order[v] == 0) {
                order[v] = ++visitCounter;
                depth[v] = depth[u] + 1;
                q.push(v);
            }
        }
    }

    long long answer = 0;
    for (int i = 1; i <= N; i++) {
        answer += (long long)depth[i] * order[i];
    }

    cout << answer << "\n";
    return 0;
}
