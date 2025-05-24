#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int nTests = 0;
    std::cin >> nTests;
    for (int tc = 0; tc < nTests; ++tc)
    {
        int width = 0;
        int height = 0;
        std::cin >> width >> height;

        // deliveries[y][x]
        std::vector<std::vector<int>> deliveries(height, std::vector<int>(width));
        for (int y = 0; y < height; ++y)
        {
            for (int x = 0; x < width; ++x)
            {
                std::cin >> deliveries[y][x];
            }
        }

        std::vector<int64_t> weightCol(width, 0);
        std::vector<int64_t> weightRow(height, 0);
        int64_t totalWeight = 0;
        for (int y = 0; y < height; ++y)
        {
            for (int x = 0; x < width; ++x)
            {
                int w = deliveries[y][x];
                weightCol[x] += w;
                weightRow[y] += w;
                totalWeight += w;
            }
        }

        // 배달이 전혀 없으면 비용은 0
        if (totalWeight == 0)
        {
            std::cout << "0 blocks\n";
            continue;
        }

        // 가중 중앙값 구하기: 누적합이 전체 무게의 절반 이상이 되는 첫 위치
        auto findWeightMedian = [&](const std::vector<int64_t> &weights)
        {
            int64_t acc = 0;
            int64_t half = (totalWeight + 1) / 2;
            for (size_t i = 0; i < weights.size(); ++i)
            {
                acc += weights[i];
                if (acc >= half)
                {
                    return static_cast<int>(i);
                }
            }

            return static_cast<int>(weights.size() - 1);
        };

        int bestX = findWeightMedian(weightCol);
        int bestY = findWeightMedian(weightRow);

        int64_t cost = 0;
        for (int y = 0; y < height; ++y)
        {
            for (int x = 0; x < width; ++x)
            {
                int w = deliveries[y][x];
                cost += static_cast<int64_t>(w) * (std::abs(x - bestX) + std::abs(y - bestY));
            }
        }

        std::cout << cost << " blocks\n";
    }

    return 0;
}