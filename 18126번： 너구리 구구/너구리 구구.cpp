#include <iostream>
#include <vector>
#include <stack>

using namespace std;

using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;

    vector<vector<pair<int, ll>>> graph(N + 1);
    for (int i = 1; i < N; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        graph[A].push_back({B, C});
        graph[B].push_back({A, C});
    }

    vector<bool> visited(N + 1, false);
    ll ans = 0;
    stack<pair<int, ll>> st;
    st.push({1, 0});
    while (!st.empty())
    {
        auto [cur, dist] = st.top();
        st.pop();
        if (visited[cur])
            continue;
        visited[cur] = true;
        ans = max(ans, dist);

        for (auto &edge : graph[cur])
        {
            if (!visited[edge.first])
            {
                st.push({edge.first, dist + edge.second});
            }
        }
    }

    cout << ans << "\n";

    return 0;
}