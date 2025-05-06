#include <bits/stdc++.h>
using namespace std;

vector<array<int, 4>> processCommands(const vector<string> &cmds)
{
    int xp = 0, yp = 0;
    int dx = 0, dy = -1;
    vector<array<int, 4>> result;
    result.reserve(cmds.size());

    for (auto &cmd : cmds)
    {
        if (cmd == "W")
        {
            xp += -dx;
            yp += -dy;
        }
        else if (cmd == "S")
        {
            xp += dx;
            yp += dy;
        }
        else if (cmd == "A")
        {
            xp += dy;
            yp += -dx;
        }
        else if (cmd == "D")
        {
            xp += -dy;
            yp += dx;
        }
        else if (cmd == "MR")
        {
            int ndx = dy, ndy = -dx;
            dx = ndx;
            dy = ndy;
        }
        else if (cmd == "ML")
        {
            int ndx = -dy, ndy = dx;
            dx = ndx;
            dy = ndy;
        }

        int xc = xp + dx, yc = yp + dy;
        result.push_back({xp, yp, xc, yc});
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N))
        return 0;
    vector<string> cmds(N);

    for (int i = 0; i < N; i++)
    {
        cin >> cmds[i];
    }

    auto answers = processCommands(cmds);
    for (auto &a : answers)
    {
        cout << a[0] << ' ' << a[1] << ' '
             << a[2] << ' ' << a[3] << '\n';
    }

    return 0;
}