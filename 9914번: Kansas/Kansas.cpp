#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    double x = 0.0, y = 0.0;
    int breaks = 0;
    double blockTime = 0.0;
    bool started = false;

    for (int i = 0; i < n; i++)
    {
        int d, h, s;
        cin >> d >> h >> s;
        double remaining = h;

        while (remaining > 1e-9)
        {
            double dt = min(remaining, 5.0 - blockTime);
            double sx = x, sy = y;
            if (d == 12)
                y += s * dt;
            else if (d == 6)
                y -= s * dt;
            else if (d == 3)
                x += s * dt;
            else if (d == 9)
                x -= s * dt;

            if (started == true && sx == 0.0 && sy == 0.0)
            {
                cout << breaks;
                return 0;
            }

            if (d == 12 or d == 6)
            {
                if (sx == 0)
                {
                    if ((sy <= 0.0 && y >= 0.0) || (sy >= 0.0 && y <= 0.0))
                    {
                        if (!(sx == 0.0 and sy == 0.0 and !started))
                        {
                            cout << breaks;

                            return 0;
                        }
                    }
                }
            }
            else
            {
                if (sy == 0.0)
                {
                    if ((sx <= 0.0 and x >= 0.0) or (sx >= 0.0 and x <= 0.0))
                    {
                        if (!(sx == 0.0 and sy == 0.0 and !started))
                        {
                            cout << breaks;
                            return 0;
                        }
                    }
                }
            }
            blockTime += dt;
            remaining -= dt;
            started = true;

            if (abs(blockTime - 5.0) < 1e-9)
            {
                blockTime = 0.0;
                breaks++;
            }
        }
    }

    cout << -1;

    return 0;
}