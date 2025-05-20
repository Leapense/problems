#include <bits/stdc++.h>
using namespace std;

struct Pos
{
    long long x, y;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N))
        return 0;
    vector<string> cmd(N);
    for (auto &s : cmd)
        cin >> s;

    unordered_map<string, Pos> foot = {
        {"RL", {0, 0}}, {"RR", {1, 0}}, {"FL", {0, 1}}, {"FR", {1, 1}}};

    int heading = 0;

    long long minX = 0, maxX = 1, minY = 0, maxY = 1;

    auto update_bounds = [&](const Pos &p)
    {
        minX = min(minX, p.x);
        maxX = max(maxX, p.x);
        minY = min(minY, p.y);
        maxY = max(maxY, p.y);
    };

    auto overlapped = [&]()
    {
        set<pair<long long, long long>> seen;
        for (auto &kv : foot)
        {
            auto pr = make_pair(kv.second.x, kv.second.y);
            if (!seen.insert(pr).second)
                return true;
        }

        return false;
    };

    for (const string &s : cmd)
    {
        const string fid = s.substr(0, 2);
        const char op = s[2];

        if (op == 'P')
        {
            Pos pivot = foot[fid];
            for (auto &kv : foot)
                if (kv.first != fid)
                {
                    long long dx = kv.second.x - pivot.x;
                    long long dy = kv.second.y - pivot.y;
                    kv.second.x = pivot.x + dy;
                    kv.second.y = pivot.y + -dx;
                }

            heading = (heading + 1) & 3;
        }
        else
        {
            static const int relCode[128] = {};
            int rel = (op == 'F') ? 0 : (op == 'R') ? 1
                                    : (op == 'B')   ? 2
                                                    : 3;
            int absDir = (heading + rel) & 3;
            static const int DX[4] = {0, 1, 0, -1};
            static const int DY[4] = {1, 0, -1, 0};
            foot[fid].x += DX[absDir];
            foot[fid].y += DY[absDir];
        }

        if (overlapped())
        {
            cout << -1 << "\n";
            return 0;
        }

        for (auto &kv : foot)
            update_bounds(kv.second);
    }

    long long area = (maxX - minX + 1) * (maxY - minY + 1);
    cout << area << "\n";

    return 0;
}