#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, R;
vector<vector<int>> graph;
vector<int> visitOrder;
int order = 1;

void dfs(int node) {
    visitOrder[node] = order++;

    for (int next : graph[node]) {
        if (visitOrder[next] == 0) {
            dfs(next);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> R;
    graph.resize(N + 1);
    visitOrder.resize(N + 1, 0);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        sort(graph[i].rbegin(), graph[i].rend());
    }

    dfs(R);

    for (int i = 1; i <= N; i++) {
        cout << visitOrder[i] << "\n";
    }

    return 0;
}
