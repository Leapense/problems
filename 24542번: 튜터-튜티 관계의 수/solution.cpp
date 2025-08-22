#include <bits/stdc++.h>
using namespace std;

static constexpr long long MOD = 1000000007LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0, m = 0;
    if (!(cin >> n >> m)) {
        return 0;
    }

    vector<vector<int>> adj(n + 1);
    adj.reserve(n + 1);

    for (int i = 0; i < m; i++) {
        int u = 0, v = 0;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<char> visited(n + 1, 0);
    vector<int> st;
    st.reserve(n);

    long long answer = 1;
    for (int s = 1; s <= n; s++) {
        if (visited[s]) {
            continue;
        }
        long long compSize = 0;
        st.clear();
        visited[s] = 1;
        st.push_back(s);
        while (!st.empty()) {
            int u = st.back();
            st.pop_back();
            compSize++;
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = 1;
                    st.push_back(v);
                }
            }
        }
        answer = (answer * (compSize % MOD)) % MOD;
    }

    cout << answer << '\n';
    return 0;
}