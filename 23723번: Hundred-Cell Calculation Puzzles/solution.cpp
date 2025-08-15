#include <iostream>
#include <vector>
#include <queue>
#include <cstdint>

struct Edge {
    int to;
    std::int64_t sum;
};

static bool judgeUnique(int w, int h, std::istream& in) {
    int n = w + h;
    int k = n - 1;

    std::vector<std::vector<Edge>> graph(n);
    for (int i = 0; i < k; ++i) {
        int x, y, s;
        in >> x >> y >> s;
        int u = x - 1;
        int v = w + (y - 1);
        graph[u].push_back({v, s});
        graph[v].push_back({u, s});
    }

    std::vector<char> visited(n, 0);
    std::vector<std::int64_t> value(n, 0);
    std::queue<int> q;
    visited[0] = 1;
    value[0] = 0;
    q.push(0);
    int countVisit = 1;
    bool inconsistent = false;
    while (!q.empty() && !inconsistent) {
        int u = q.front();
        q.pop();
        for (const auto& e : graph[u]) {
            int v = e.to;
            std::int64_t s = e.sum;
            if (!visited[v]) {
                value[v] = s - value[u];
                visited[v] = 1;
                q.push(v);
                ++countVisit;
            } else {
                if (value[u] + value[v] != s) {
                    inconsistent = true;
                    break;
                }
            }
        }
    }
    if (inconsistent) return false;
    return countVisit == n;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    while (true) {
        int w, h;
        if (!(std::cin >> w >> h)) return 0;
        if (w == 0 && h == 0) break;
        bool ok = judgeUnique(w, h, std::cin);
        std::cout << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}