#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <cstdint>
#include <cmath>
#include <bitset>

struct Zombie {
    int x, y, appear_time;
};

constexpr int MAX_Z = 8;

int chebyshev(int x1, int y1, int x2, int y2) {
    return std::max(std::abs(x1 - x2), std::abs(y1 - y2));
}

int dfs(int z, const std::vector<Zombie>& zombies, std::bitset<MAX_Z> used, int cur_x, int cur_y, int64_t cur_time, int64_t cooldown_end, int depth) {
    int max_cnt = 0;
    for (int i = 0; i < z; ++i) {
        if (used[i]) continue;
        const Zombie& zb = zombies[i];
        int move_time = chebyshev(cur_x, cur_y, zb.x, zb.y) * 100;
        int64_t arrival_time = cur_time + move_time;
        arrival_time = std::max(arrival_time, static_cast<int64_t>(zb.appear_time));
        arrival_time = std::max(arrival_time, cooldown_end);
        if (arrival_time > zb.appear_time + 1000) continue;
        auto next_used = used;

        next_used[i] = true;
        int cnt = 1 + dfs(z, zombies, next_used, zb.x, zb.y, arrival_time, arrival_time + 750, depth + 1);
        if (cnt > max_cnt) max_cnt = cnt;
    }

    return max_cnt;
}

int main()
{
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; ++t) {
        int z;
        std::cin >> z;
        std::vector<Zombie> zombies(z);
        for (int i = 0; i < z; ++i) {
            std::cin >> zombies[i].x >> zombies[i].y >> zombies[i].appear_time;
        }

        std::bitset<MAX_Z> used;
        int answer = dfs(z, zombies, used, 0, 0, 0, 0, 0);
        std::cout << "Case #" << t << ": " << answer << "\n";
    }

    return 0;
}