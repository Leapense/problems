#include <bits/stdc++.h>
using namespace std;

static const int MAX_STEPS = 60;

struct Point {
    int x, y;
};

static bool samePoint(const Point& a, const Point& b) {
    return a.x == b.x && a.y == b.y;
}

static int getOrCreateNode(vector<Point>& nodes, int x, int y) {
    for (size_t i = 0; i < nodes.size(); ++i) {
        if (nodes[i].x == x && nodes[i].y == y) {
            return static_cast<int>(i);
        }
    }

    nodes.push_back({x, y});
    return static_cast<int>(nodes.size()) - 1;
}

static int bfsShortest(const vector<vector<int>>& adj, int startIdx, int endIdx) {
    int n = static_cast<int>(adj.size());
    vector<int> dist(n, -1);
    queue<int> q;

    dist[startIdx] = 0;
    q.push(startIdx);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == endIdx) {
            return dist[u];
        }
        for (int v : adj[u])
        {
            if (dist[v] < 0) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return (startIdx == endIdx ? 0 : -1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    string line;
    getline(cin, line);

    for (int pathIdx = 0; pathIdx < n; ++pathIdx) {
        while (true) {
            if (!std::getline(cin, line)) {
                break;
            }
            if (!line.empty()) {
                break;
            }
        }

        if (line.empty()) {
            break;
        }
        int s = stoi(line);

        vector<Point> nodes;
        nodes.reserve(MAX_STEPS + 1);

        vector<vector<int>> adj;
        adj.reserve(MAX_STEPS + 1);

        nodes.push_back({0, 0});
        adj.push_back({});
        int curX = 0, curY = 0;
        int curIdx = 0;

        if (s == 0) {
            cout << 0 << "\n";
            continue;
        }

        for (int i = 0; i < s; ++i) {
            getline(cin, line);
            if (line.empty()) {
                --i;
                continue;
            }

            char dir = line[0];
            int nextX = curX;
            int nextY = curY;
            switch(dir) {
                case 'N': nextY = curY + 1; break;
                case 'E': nextX = curX + 1; break;
                case 'S': nextY = curY - 1; break;
                case 'W': nextX = curX - 1; break;
                default: break;
            }

            int nextIdx = getOrCreateNode(nodes, nextX, nextY);
            if (nextIdx >= static_cast<int>(adj.size())) {
                adj.emplace_back();
            }

            bool connected = false;
            for (int w : adj[curIdx]) {
                if (w == nextIdx) {
                    connected = true;
                    break;
                }
            }

            if (!connected) {
                adj[curIdx].push_back(nextIdx);
            }

            connected = false;
            for (int w : adj[nextIdx]) {
                if (w == curIdx) {
                    connected = true;
                    break;
                }
            }
            
            if (!connected) {
                adj[nextIdx].push_back(curIdx);
            }

            curX = nextX;
            curY = nextY;
            curIdx = nextIdx;
        }

        int endIdx = curIdx;
        int answer = bfsShortest(adj, 0, endIdx);
        cout << answer << "\n";
    }

    return 0;
}