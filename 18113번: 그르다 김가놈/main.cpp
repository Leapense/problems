#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll K, M;

    cin >> N >> K >> M;

    vector<ll> rolls(N);

    for (auto &x : rolls)
        cin >> x;

    ll lo = 1, hi = 0;
    for (auto L : rolls)
    {
        if (L > K)
        {
            ll p = (L >= 2 * K ? L - 2 * K : L - K);
            hi = max(hi, p);
        }
    }

    if (hi == 0)
    {
        cout << -1;
        return 0;
    }

    ll ans = -1;
    while (lo <= hi)
    {
        ll mid = lo + (hi - lo) / 2;
        ll cnt = 0;

        for (auto L : rolls)
        {
            if (L <= K)
                continue;
            ll proc = (L >= 2 * K ? L - 2 * K : L - K);
            cnt += proc / mid;
            if (cnt >= M)
                break;
        }

        if (cnt >= M)
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    cout << ans << "\n";

    return 0;
}