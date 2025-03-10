#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct Edge
{
    int to;
    int timeB;
    int timeE;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<Edge>> graph(N + 1);
    for (int i = 0; i < M; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        graph[a].push_back({b, c, d});
    }

    vector<set<int>> dpB(N + 1), dpE(N + 1);
    dpB[1].insert(0);
    dpE[1].insert(0);

    for (int i = 1; i <= N; i++)
    {
        for (auto &edge : graph[i])
        {
            for (auto t : dpB[i])
            {
                dpB[edge.to].insert(t + edge.timeB);
            }
            for (auto t : dpE[i])
            {
                dpE[edge.to].insert(t + edge.timeE);
            }
        }
    }

    int ans = -1;
    for (auto t : dpB[N])
    {
        if (dpE[N].find(t) != dpE[N].end())
        {
            if (ans == -1 || t < ans)
            {
                ans = t;
            }
        }
    }

    if (ans == -1)
        cout << "IMPOSSIBLE\n";
    else
        cout << ans << "\n";

    return 0;
}