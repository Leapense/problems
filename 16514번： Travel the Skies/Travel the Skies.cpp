#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

using ll = long long;
const ll INF = numeric_limits<ll>::max();

struct Edge
{
    int to, rev;
    ll cap;
};

struct Dinic
{
    int N;
    vector<vector<Edge>> adj;
    vector<int> level, it;

    Dinic(int N) : N(N), adj(N), level(N), it(N) {}

    void add_edge(int s, int t, ll cap)
    {
        Edge a = {t, (int)adj[t].size(), cap};
        Edge b = {s, (int)adj[s].size(), 0};
        adj[s].push_back(a);
        adj[t].push_back(b);
    }

    bool bfs(int s, int t)
    {
        fill(level.begin(), level.end(), -1);
        level[s] = 0;
        queue<int> q;
        q.push(s);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto &e : adj[u])
            {
                if (level[e.to] < 0 && e.cap > 0)
                {
                    level[e.to] = level[u] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[t] >= 0;
    }

    ll dfs(int u, int t, ll flow)
    {
        if (!flow)
            return 0;
        if (u == t)
            return flow;
        for (int &i = it[u]; i < (int)adj[u].size(); i++)
        {
            Edge &e = adj[u][i];
            if (e.cap > 0 && level[e.to] == level[u] + 1)
            {
                ll pushed = dfs(e.to, t, min(flow, e.cap));
                if (pushed)
                {
                    e.cap -= pushed;
                    adj[e.to][e.rev].cap += pushed;
                    return pushed;
                }
            }
        }

        return 0;
    }

    ll max_flow(int s, int t)
    {
        ll flow = 0;
        while (bfs(s, t))
        {
            fill(it.begin(), it.end(), 0);
            while (ll pushed = dfs(s, t, INF))
            {
                flow += pushed;
            }
        }

        return flow;
    }
};

struct FlightEdge
{
    int from, to;
    ll cap;
    int dinic_index;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, n, m;
    cin >> k >> n >> m;

    auto nodeID = [&](int airport, int day) -> int
    {
        return (airport - 1) * (n + 1) + (day - 1);
    };

    int nodes = k * (n + 1);
    int source = nodes;
    int sink = nodes + 1;
    int totalNodes = nodes + 2;

    Dinic dinic(totalNodes);
    vector<FlightEdge> flights;

    for (int i = 0; i < m; i++)
    {
        int u, v, d;
        ll z;
        cin >> u >> v >> d >> z;
        int from = nodeID(u, d);
        int to = nodeID(v, d + 1);

        int idx = dinic.adj[from].size();
        dinic.add_edge(from, to, z);
        flights.push_back({from, to, z, idx});
    }

    for (int airport = 1; airport <= k; airport++)
    {
        for (int day = 1; day <= n; day++)
        {
            int u = nodeID(airport, day);
            int v = nodeID(airport, day + 1);
            dinic.add_edge(u, v, INF);
        }
    }

    for (int i = 0; i < k * n; i++)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;

        int node = nodeID(a, b);
        dinic.add_edge(source, node, c);
    }

    for (int airport = 1; airport <= k; airport++)
    {
        int node = nodeID(airport, n + 1);
        dinic.add_edge(node, sink, INF);
    }

    ll flow = dinic.max_flow(source, sink);

    bool optimal = true;

    for (auto &fEdge : flights)
    {
        if (dinic.adj[fEdge.from][fEdge.dinic_index].cap != 0)
        {
            optimal = false;
            break;
        }
    }
    cout << (optimal ? "optimal" : "suboptimal") << "\n";

    return 0;
}