#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, r;
    int caseNum = 1;

    while (cin >> n >> m >> r)
    {
        if (n == 0 && m == 0 && r == 0)
            break;
        vector<vector<bool>> rock(m + 1, vector<bool>(n + 1, false));
        for (int i = 0; i < r; i++)
        {
            int c, rr;
            cin >> c >> rr;
            rock[rr][c] = true;
        }

        int startC, startR;
        cin >> startC >> startR;
        int dx = 0, dy = 0;
        if (startC == 1)
        {
            dx = 1;
            dy = 0;
        }
        else if (startC == n)
        {
            dx = -1;
            dy = 0;
        }
        else if (startR == 1)
        {
            dx = 0;
            dy = 1;
        }
        else if (startR == m)
        {
            dx = 0;
            dy = -1;
        }
        int x = startC, y = startR;
        long long cnt = 1;

        auto inBounds = [&](int xx, int yy) -> bool
        {
            return xx >= 1 && xx <= n && yy >= 1 && yy <= m;
        };

        auto canMove = [&](int ddx, int ddy) -> bool
        {
            int nx = x + ddx, ny = y + ddy;
            if (!inBounds(nx, ny))
                return true;
            return !rock[ny][nx];
        };
        while (true)
        {
            int fx = x + dx, fy = y + dy;
            if (!inBounds(fx, fy))
                break;
            if (inBounds(fx, fy) && !rock[fy][fx])
            {
                x = fx;
                y = fy;
                cnt++;
                continue;
            }

            int rdx = dy, rdy = -dx;
            if (canMove(rdx, rdy))
            {
                dx = rdx;
                dy = rdy;
                int nx = x + dx, ny = y + dy;
                if (!inBounds(nx, ny))
                    break;
                x = nx;
                y = ny;
                cnt++;
                continue;
            }

            int ldx = -dy, ldy = dx;
            if (canMove(ldx, ldy))
            {
                dx = ldx;
                dy = ldy;
                int nx = x + dx, ny = y + dy;
                if (!inBounds(nx, ny))
                    break;

                x = nx;
                y = ny;
                cnt++;
                continue;
            }

            dx = -dx;
            dy = -dy;
            int nx = x + dx, ny = y + dy;
            if (!inBounds(nx, ny))
                break;
            x = nx;
            y = ny;
            cnt++;
        }

        cout << "Case " << caseNum++ << ": " << x << " " << y << " " << cnt;
        if (!cin.eof())
            cout << "\n";
    }

    return 0;
}