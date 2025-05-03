#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool checkReturnToOrigin(int N, ll K, const string &S)
{
    vector<pair<ll, ll>> prefix;
    ll x = 0, y = 0;
    for (char c : S)
    {
        if (c == 'U')
            y++;
        else if (c == 'D')
            y--;
        else if (c == 'L')
            x--;
        else if (c == 'R')
            x++;
        prefix.emplace_back(x, y);
    }
    ll dx = x, dy = y; // net move after one S

    // Check within first repetition
    for (auto [px, py] : prefix)
    {
        if (px == 0 && py == 0)
            return true;
    }

    // If net movement is zero vector, no new positions will appear
    if (dx == 0 && dy == 0)
        return false;

    // For each prefix position, check if there exists t in [0, K) such that t*(dx,dy)+prefix = (0,0)
    for (auto [px, py] : prefix)
    {
        // Solve t*dx + px = 0 and t*dy + py = 0
        // Cases when dx or dy is zero
        if (dx == 0)
        {
            if (px != 0)
                continue;
            // py + t*dy = 0 -> t = -py/dy
            if (dy != 0 && (-py) % dy == 0)
            {
                ll t = -py / dy;
                if (0 <= t && t < K)
                    return true;
            }
        }
        else if (dy == 0)
        {
            if (py != 0)
                continue;
            if (dx != 0 && (-px) % dx == 0)
            {
                ll t = -px / dx;
                if (0 <= t && t < K)
                    return true;
            }
        }
        else
        {
            // Both non-zero: t = -px/dx = -py/dy
            if ((-px) % dx == 0 && (-py) % dy == 0)
            {
                ll t1 = -px / dx;
                ll t2 = -py / dy;
                if (t1 == t2 && 0 <= t1 && t1 < K)
                    return true;
            }
        }
    }
    return false;
}

#ifndef UNIT_TEST
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long K;
    string S;
    cin >> N >> K >> S;

    cout << (checkReturnToOrigin(N, K, S) ? "YES" : "NO");
    return 0;
}
#endif