#include <iostream>
#include <vector>
#include <queue>

void solve() {
    int n, s, d, f, b, k;
    std::cin >> n >> s >> d >> f >> b >> k;
    std::vector<bool> is_police(n + 1, false);
    if (k > 0) {
        for (int i = 0; i < k; ++i) {
            int police_loc;
            std::cin >> police_loc;
            is_police[police_loc] = true;
        }
    }

    if (is_police[s]) {
        std::cout << "BUG FOUND\n";
        return;
    }

    std::vector<int> dist(n + 1, -1);
    std::queue<int> q;

    dist[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int current_building = q.front();
        q.pop();

        if (current_building == d) {
            std::cout << dist[d] << "\n";
            return;
        }

        int next_moves[2] = {current_building + f, current_building - b};

        for (int next_building : next_moves) {
            if (next_building >= 1 && next_building <= n && !is_police[next_building] && dist[next_building] == -1) {
                dist[next_building] = dist[current_building] + 1;
                q.push(next_building);
            }
        }
    }

    std::cout << "BUG FOUND\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}