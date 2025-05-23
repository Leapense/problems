#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
struct Segment
{
    ll l, r;
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    int k;
    cin >> n >> k;
    int m;
    cin >> m;
    vector<Segment> seg(m);
    ll total = 0;
    for (auto &s : seg)
    {
        cin >> s.l >> s.r;
        total += s.r - s.l + 1;
    }
    sort(seg.begin(), seg.end(), [](const Segment &a, const Segment &b)
         { return a.r > b.r; });
    int groups = total / k + (total % k ? 1 : 0);
    ll ans = 0;
    ll cum = 0;
    int segIdx = 0;
    for (int g = 0; g < groups; g++)
    {
        ll target = 1LL + g * k;
        while (segIdx < m && cum + (seg[segIdx].r - seg[segIdx].l + 1) < target)
        {
            cum += seg[segIdx].r - seg[segIdx].l + 1;
            segIdx++;
        }
        if (segIdx >= m)
            break;
        ll pos = seg[segIdx].r - (target - cum - 1);
        ans += 2 * pos;
    }
    cout << ans;
    return 0;
}
