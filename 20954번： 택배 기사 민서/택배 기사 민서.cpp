#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>
using namespace std;

struct Segment
{
    int64_t start;
    int64_t end;
    int64_t startTime;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    const int maxSegments = 62;
    vector<Segment> segments;
    segments.reserve(maxSegments);

    int64_t currentPos = 0;
    int64_t currentTime = 0;

    for (int i = 0; i < maxSegments; i++)
    {
        int64_t k = i / 2;
        int64_t dest = ((i % 2 == 0) ? 1 : -1) * (1LL << k);

        Segment seg;
        seg.start = currentPos;
        seg.end = dest;
        seg.startTime = currentTime;

        segments.push_back(seg);

        currentTime += abs(dest - currentPos);
        currentPos = dest;
    }

    while (T--)
    {
        int64_t x;
        cin >> x;

        if (x == 0)
        {
            cout << 0 << "\n";
            continue;
        }

        int64_t ans = -1;
        for (const auto &seg : segments)
        {
            int64_t s = seg.start;
            int64_t e = seg.end;
            int64_t lo = min(s, e), hi = max(s, e);
            if (x >= lo && x <= hi)
            {
                ans = seg.startTime + abs(x - s);
                break;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}