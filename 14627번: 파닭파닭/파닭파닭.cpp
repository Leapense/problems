#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int S, C;
    cin >> S >> C;
    vector<ll> lengths(S);
    ll maxL = 0, total = 0;
    for (int i = 0; i < S; i++)
    {
        cin >> lengths[i];
        maxL = max(maxL, lengths[i]);
        total += lengths[i];
    }
    ll lo = 1, hi = maxL, ans = 0;
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        ll cnt = 0;
        for (auto l : lengths)
            cnt += l / mid;
        if (cnt >= C)
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    cout << total - C * ans;
    return 0;
}
