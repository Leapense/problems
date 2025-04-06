#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

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
        sort(graph[i].rbegin(), graph[i].rend());
    }

    vector<int> order(N + 1, 0);
    queue<int> q;

    order[R] = 1;
    q.push(R);
    int visitOrder = 2;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur]) {
            if (order[next] == 0) {
                order[next] = visitOrder++;
                q.push(next);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << order[i] << "\n";
    }

    return 0;
}
