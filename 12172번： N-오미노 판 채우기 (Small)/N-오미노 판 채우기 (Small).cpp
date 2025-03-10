#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        int X, R, C;
        cin >> X >> R >> C;

        int m = min(R, C), M = max(R, C);

        string ans = "GABRIEL";
        if ((R * C) % X != 0)
        {
            ans = "RICHARD";
        }
        else if (X >= 7)
        {
            ans = "RICHARD";
        }
        else if (X > M)
        {
            ans = "RICHARD";
        }
        else if ((X + 1) / 2 > m)
        {
            ans = "RICHARD";
        }
        else
        {
            if (X == 1 || X == 2)
            {
                ans = "GABRIEL";
            }
            else if (X == 3)
            {
                if (m <= 1)
                {
                    ans = "RICHARD";
                }
            }
            else if (X == 4)
            {
                if (m <= 2)
                {
                    ans = "RICHARD";
                }
            }
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }

    return 0;
}