#include <iostream>
#include <vector>
#include <stack>
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

    vector<int> depth(N + 1, -1);

    stack<pair<int, int>> s;
    s.push({R, 0});

    while (!s.empty()) {
        auto [cur, d] = s.top();
        s.pop();

        if (depth[cur] != -1) continue;

        depth[cur] = d;

        for (auto it = graph[cur].rbegin(); it != graph[cur].rend(); ++it) {
            int next = *it;
            if (depth[next] == -1) 
            {
                s.push({next, d + 1});
            }
        }
    }

    for (int i = 1; i <= N; i++) 
    {
        cout << depth[i] << "\n";
    }

    return 0;
}
