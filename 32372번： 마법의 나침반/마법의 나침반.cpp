#include <bits/stdc++.h>

int main()
{
    int N, M;
    std::cin >> N >> M;
    std::vector<std::tuple<int, int, int>> readings(M);
    std::vector<std::pair<int, int>> compass_positions;

    for (int i = 0; i < M; ++i) {
        int X, Y, K;
        std::cin >> X >> Y >> K;
        readings[i] = std::make_tuple(X, Y, K);
        compass_positions.emplace_back(X, Y);
    }

    auto get_direction = [&](int x1, int y1, int x2, int y2) -> int {
        if (x2 < x1 && y2 == y1) return 1;
        if (x2 < x1 && y2 > y1) return 2;
        if (x2 == x1 && y2 > y1) return 3;
        if (x2 > x1 && y2 > y1) return 4;
        if (x2 > x1 && y2 == y1) return 5;
        if (x2 > x1 && y2 < y1) return 6;
        if (x2 == x1 && y2 < y1) return 7;
        if (x2 < x1 && y2 < y1) return 8;
        return -1;
    };

    for (int tx = 1; tx <= N; ++tx) {
        for (int ty = 1; ty <= N; ++ty) {
            bool valid = true;
            for (const auto& pos : compass_positions) {
                if (tx == pos.first && ty == pos.second) {
                    valid = false;
                    break;
                }
            }
            if (!valid) continue;

            for (const auto& reading : readings) {
                int X = std::get<0>(reading);
                int Y = std::get<1>(reading);
                int K = std::get<2>(reading);

                int direction = get_direction(X, Y, tx, ty);

                if (direction != K) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                std::cout << tx << " " << ty << std::endl;
                return 0;
            }
        }
    }

    return 0;
}