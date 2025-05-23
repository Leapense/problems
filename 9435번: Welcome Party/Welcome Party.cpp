/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9435                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: cjhool <boj.kr/u/cjhool>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9435                           #+#        #+#      #+#    */
/*   Solved: 2025/02/28 18:25:40 by cjhool        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct BipGraph
{
    int nLeft, nRight;
    vector<vector<int>> adj;
    vector<int> matchL, matchR, dist;

    BipGraph(int nLeft, int nRight) : nLeft(nLeft), nRight(nRight)
    {
        adj.resize(nLeft);
        matchL.assign(nLeft, -1);
        matchR.assign(nRight, -1);
        dist.assign(nLeft, 0);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    bool bfs()
    {
        queue<int> q;
        for (int u = 0; u < nLeft; u++)
        {
            if (matchL[u] == -1)
            {
                dist[u] = 0;
                q.push(u);
            }
            else
            {
                dist[u] = INF;
            }
        }

        int distance = INF;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            if (dist[u] < distance)
            {
                for (int v : adj[u])
                {
                    if (matchR[v] == -1)
                    {
                        distance = dist[u] + 1;
                    }
                    else if (dist[matchR[v]] == INF)
                    {
                        dist[matchR[v]] = dist[u] + 1;
                        q.push(matchR[v]);
                    }
                }
            }
        }

        return distance != INF;
    }

    bool dfs(int u, int distance)
    {
        if (dist[u] == distance)
        {
            dist[u] = INF;
            for (int v : adj[u])
            {
                int nxt = matchR[v];
                if (nxt == -1 || (dist[nxt] == distance + 1 && dfs(nxt, distance + 1)))
                {
                    matchL[u] = v;
                    matchR[v] = u;
                    return true;
                }
            }
        }

        return false;
    }

    int hopcroftKarp()
    {
        int matching = 0;
        while (bfs())
        {
            for (int u = 0; u < nLeft; u++)
            {
                if (matchL[u] == -1 && dfs(u, 0))
                {
                    matching++;
                }
            }
        }
        return matching;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true)
    {
        int N;
        cin >> N;
        if (N == 0)
            break;
        BipGraph graph(26, 18);
        for (int i = 0; i < N; i++)
        {
            string first, last;
            cin >> first >> last;
            int u = first[0] - 'A';
            int v = last[0] - 'A';
            graph.addEdge(u, v);
        }

        cout << graph.hopcroftKarp() << "\n";
    }

    return 0;
}