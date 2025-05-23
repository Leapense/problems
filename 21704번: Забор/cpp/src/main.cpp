#include "main.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

ll solve(ll n, int k, const vector<Segment> &segments)
{
    vector<Segment> seg = segments;
    sort(seg.begin(), seg.end(), [](const Segment &a, const Segment &b)
         { return a.r > b.r; });

    ll total = 0;
    for (auto &s : seg)
    {
        total += (s.r - s.l + 1);
    }

    int groups = (total + k - 1) / k;
    ll ans = 0;
    ll cum = 0;

    int segIdx = 0;
    for (int g = 0; g < groups; g++)
    {
        ll target = 1LL + g * k;
        while (segIdx < (int)seg.size() && cum + (seg[segIdx].r - seg[segIdx].l + 1) < target)
        {
            cum += (seg[segIdx].r - seg[segIdx].l + 1);
            segIdx++;
        }

        if (segIdx >= (int)seg.size())
            break;

        ll pos = seg[segIdx].r - (target - cum - 1);
        ans += 2 * pos;
    }

    return ans;
}

#ifndef UNIT_TESTS
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    int k;

    cin >> n >> k;

    int m;
    cin >> m;

    vector<Segment> segments(m);
    for (int i = 0; i < m; i++)
    {
        cin >> segments[i].l >> segments[i].r;
    }

    cout << solve(n, k, segments);
    return 0;
}
#endif