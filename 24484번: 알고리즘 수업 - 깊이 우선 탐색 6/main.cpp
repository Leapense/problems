#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, R;
    cin >> N >> M >> R;

    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        sort(adj[i].rbegin(), adj[i].rend());
    }

    vector<int> depth(N + 1, -1);
    vector<int> order(N + 1, 0);

    vector<int> index(N + 1, 0);
    stack<int> s;

    int counter = 1;
    depth[R] = 0;
    order[R] = counter;
    s.push(R);

    while (!s.empty()) {
        int v = s.top();

        if (index[v] < adj[v].size()) {
            int w = adj[v][index[v]++];
            if (order[w] == 0) {
                depth[w] = depth[v] + 1;
                order[w] = ++counter;
                s.push(w);
            }
        } else {
            s.pop();
        }
    }

    long long result = 0;
    for (int i = 1; i <= N; i++) {
        result += (long long) depth[i] * order[i];
    }

    cout << result << "\n";
    return 0;
}
