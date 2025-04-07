#include <bits/stdc++.h>
using namespace std;

static const int INF = 5000001;

int N, M;
vector<vector<int>> cost;

int bestCost = INF;
vector<int> bestPath;
vector<bool> visited;

vector<int> currentPath;

void dfs(int count, int currentNode, int maxEdgeSoFar, int startNode) {
    if (count == N) {
        if (cost[currentNode][startNode] == -1) return;
        int finalMaxEdge = max(maxEdgeSoFar, cost[currentNode][startNode]);
        if (finalMaxEdge < bestCost) {
            bestCost = finalMaxEdge;
            bestPath = currentPath;
        }

        return;
    }

    for (int next = 1; next <= N; next++) {
        if (visited[next]) continue;
        if (cost[currentNode][next] == -1) continue;

        int nextMax = max(maxEdgeSoFar, cost[currentNode][next]);

        if (nextMax >= bestCost) continue;

        visited[next] = true;
        currentPath.push_back(next);
        dfs(count + 1, next, nextMax, startNode);
        visited[next] = false;
        currentPath.pop_back();
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    cost.assign(N + 1, vector<int>(N + 1, -1));
    for (int i = 0; i < M; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        cost[u][v] = c;
    }

    for (int startNode = 1; startNode <= 1; startNode++) {
        visited.assign(N + 1, false);
        visited[startNode] = true;

        currentPath.clear();
        currentPath.push_back(startNode);

        dfs(1, startNode, 0, startNode);
    }

    if (bestCost == INF) {
        cout << -1 << "\n";
    } else {
        cout << bestCost << "\n";

        for (int i = 0; i < (int)bestPath.size(); i++) {
            cout << bestPath[i];
            if (i < (int)bestPath.size() - 1) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}
