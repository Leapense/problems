#include <iostream>
#include <cstdint>
#include <cstdlib>

// 전역 상수 정의
static constexpr int GRID_CENTER = 1024;
static constexpr int GRID_MIN    = 0;
static constexpr int GRID_MAX    = 2048;

[[nodiscard]] static int countSquares(const int s, const int cx, const int cy, const int px, const int py)
{
    if (s < 1) {
        return 0;
    }

    int count = 0;
    if ((cx - s) <= px && px <= (cx + s)
     && (cy - s) <= py && py <= (cy + s)) {
        count = 1;
    }

    const int s2 = (s >> 1);

    if (s2 >= 1) {
        int DX[4] = {-s, -s, +s, +s};
        int DY[4] = {-s, +s, -s, +s};

        for (int idx = 0; idx < 4; ++idx) {
            const int childCx = cx + DX[idx];
            const int childCy = cy + DY[idx];
            count += countSquares(s2, childCx, childCy, px, py);
        }
    }
    return count;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (true)
    {
        int k{}, px{}, py{};
        if (!(std::cin >> k >> px >> py)) {
            break;
        }

        if (k == 0 && px == 0 && py == 0) break;

        if (k < 1 || k > 512 || px < GRID_MIN || px > GRID_MAX || py < GRID_MIN || py > GRID_MAX) {
            std::cout << 0 << "\n";
            continue;
        }

        const int result = countSquares(k, GRID_CENTER, GRID_CENTER, px, py);
        std::cout << result << "\n";
    }

    return EXIT_SUCCESS;
}