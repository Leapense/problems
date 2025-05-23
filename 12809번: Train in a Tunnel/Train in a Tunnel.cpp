#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        ll h;
        cin >> n >> h;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<int> light(n);
        for (int i = 0; i < n; i++)
        {
            cin >> light[i];
        }
        vector<ll> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            prefix[i] = prefix[i - 1] + a[i - 1];
        }
        ll L_total = prefix[n];
        vector<int> onIndices;
        for (int i = 0; i < n; i++)
        {
            if (light[i] == 1)
                onIndices.push_back(i + 1);
        }
        ll ans = 0;
        auto solve_gap = [&](int startIdx, int endIdx, ll gapL, ll gapR)
        {
            int j = startIdx;
            ll cur = gapL;
            while (cur + h <= gapR)
            {
                ll best = cur;
                while (j <= endIdx && prefix[j - 1] <= cur + h)
                {
                    best = max(best, prefix[j]);
                    j++;
                }
                cur = best;
                ans++;
            }
        };
        if (onIndices.empty())
        {
            solve_gap(1, n, 0, L_total);
        }
        else
        {
            if (prefix[onIndices[0] - 1] > 0)
            {
                solve_gap(1, onIndices[0] - 1, 0, prefix[onIndices[0] - 1]);
            }
            for (size_t i = 0; i + 1 < onIndices.size(); i++)
            {
                if (onIndices[i + 1] > onIndices[i] + 1)
                {
                    ll gapL = prefix[onIndices[i]];
                    ll gapR = prefix[onIndices[i + 1] - 1];
                    solve_gap(onIndices[i] + 1, onIndices[i + 1] - 1, gapL, gapR);
                }
            }
            if (onIndices.back() < n)
            {
                solve_gap(onIndices.back() + 1, n, prefix[onIndices.back()], L_total);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
