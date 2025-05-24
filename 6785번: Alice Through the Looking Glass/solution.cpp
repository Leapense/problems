#include <bits/stdc++.h>
using std::cin;
using std::cout;

static constexpr int MAX_M = 13;

auto main() -> int
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    std::array<long long, MAX_M + 1> pow5{};
    pow5[0] = 1LL;
    for (int i = 1; i <= MAX_M; ++i)
    {
        pow5[i] = pow5[i - 1] * 5LL;
    }

    int T{};
    cin >> T;

    while (T-- > 0)
    {
        int m{};
        long long x{}, y{};
        cin >> m >> x >> y;

        bool isCrystal = false;
        int level = m;
        long long cx = x;
        long long cy = y;

        while (level > 0)
        {
            const long long block = pow5[level - 1];
            const int x0 = static_cast<int>(cx / block);
            const int y0 = static_cast<int>(cy / block);

            if (y0 == 0 && x0 >= 1 && x0 <= 3)
            {
                isCrystal = true;
                break;
            }

            if (y0 == 1 && x0 == 2)
            {
                isCrystal = true;
                break;
            }

            if ((y0 == 1 && (x0 == 1 || x0 == 3)) || (y0 == 2 && x0 == 2))
            {
                cx %= block;
                cy %= block;
                --level;
                continue;
            }

            isCrystal = false;
            break;
        }

        cout << (isCrystal ? "crystal\n" : "empty\n");
    }

    return 0;
}