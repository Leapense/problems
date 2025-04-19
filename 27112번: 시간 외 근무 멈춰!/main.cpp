#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll reg_days(ll d)
{
    ll w = d / 7;
    ll r = d % 7;
    return w * 5 + min(r, 5LL);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N))
        return 0;

    vector<pair<int, int>> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());
    ll req = 0, ans = 0;
    for (auto &[d, t] : a)
    {
        req += t;
        ll reg = reg_days(d);
        if (req > reg + d)
        {
            cout << -1;
            return 0;
        }
        ans = max(ans, max(0LL, req - reg));
    }

    cout << ans;
    return 0;
}