#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct StackItem {
    int vertex;
    size_t nextIndex;
};

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
    vector<int> order(N + 1, 0);
    int cnt = 1;

    stack<StackItem> st;

    depth[R] = 0;
    order[R] = cnt;
    st.push({R, 0});

    while (!st.empty()) {
        auto &top = st.top();
        int cur = top.vertex;
        size_t &idx = top.nextIndex;

        if (idx < graph[cur].size()) {
            int next = graph[cur][idx];
            idx++;
            if (order[next] == 0) {
                cnt++;
                order[next] = cnt;
                depth[next] = depth[cur] + 1;
                st.push({next, 0});
            }
        } else {
            st.pop();
        }
    }

    long long result = 0;
    for (int i = 1; i <= N; i++) 
    {
        result += static_cast<long long>(depth[i]) * order[i];
    }

    cout << result << "\n";
    return 0;
}
