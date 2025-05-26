#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long centerX, centerY, radius;
    while (true)
    {
        cin >> centerX >> centerY >> radius;
        if (centerX == 0 && centerY == 0 && radius == 0) break;

        long long result = 0;
        for (long long dy = 0; dy < radius; ++dy) {
            long long sq = radius * radius - dy * dy;
            long long t = static_cast<long long>(floor(sqrt(static_cast<long double>(sq))));

            if (t * t < sq) {
                ++t;
            }
            result += 4 * t;
        }
        cout << result << "\n";
    }
    return 0;
}