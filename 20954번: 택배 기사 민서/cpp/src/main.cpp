#include <iostream>
#include "main.h"

DeliveryRoute::DeliveryRoute()
{
    const int maxSegments = 62;
    int64_t currentPos = 0;
    int64_t currentTime = 0;
    segments.reserve(maxSegments);

    for (int i = 0; i < maxSegments; i++)
    {
        int64_t k = i / 2;
        int64_t dest = ((i % 2 == 0) ? 1 : -1) * (1LL << k);

        Segment seg;
        seg.start = currentPos;
        seg.end = dest;
        seg.startTime = currentTime;
        segments.push_back(seg);
        currentTime += std::abs(dest - currentPos);
        currentPos = dest;
    }
}

int64_t DeliveryRoute::solveQuery(int64_t x) const
{
    if (x == 0)
    {
        return 0;
    }

    for (const auto &seg : segments)
    {
        int64_t s = seg.start, e = seg.end;
        int64_t lo = std::min(s, e), hi = std::max(s, e);
        if (x >= lo && x <= hi)
        {
            return seg.startTime + std::abs(x - s);
        }
    }

    return -1;
}

#ifndef UNIT_TESTS
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    DeliveryRoute route;
    while (T--)
    {
        int64_t x;
        std::cin >> x;
        std::cout << route.solveQuery(x) << "\n";
    }

    return 0;
}
#endif