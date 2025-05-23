#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        int R, C;
        cin >> R >> C;

        int total = R * C;
        int ans = 0;

        for (int mask = 0; mask < (1 << total); mask++)
        {
            int cnt = __builtin_popcount(mask);
            if (cnt <= ans)
                continue;

            bool valid = true;

            for (int i = 0; i < R && valid; i++)
            {
                for (int j = 0; j < C && valid; j++)
                {
                    int pos = i * C + j;
                    if (mask & (1 << pos))
                    {
                        bool left = (j > 0) && (mask & (1 << (i * C + j - 1)));
                        bool right = (j < C - 1) && (mask & (1 << (i * C + j + 1)));
                        bool up = (i > 0) && (mask & (1 << ((i - 1) * C + j)));
                        bool down = (i < R - 1) && (mask & (1 << ((i + 1) * C + j)));

                        if (left && right)
                            valid = false;
                        if (up && down)
                            valid = false;
                    }
                }
            }

            if (valid)
                ans = max(ans, cnt);
        }

        cout << "Case #" << t << ": " << ans << "\n";
    }

    return 0;
}