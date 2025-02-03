#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    void solve()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        long long d, h, w, k;
        cin >> d >> h >> w >> k;

        double dd = d, hh = h, ww = w, kk = k;
        double ans = 1e18;
        bool possible = false;
        double thetaDirect = atan(ww / dd);
        if (2 * ww <= hh)
        {
            double distHouse = 2 * dd / cos(thetaDirect);
            if (distHouse <= kk + 1e-9)
            {
                ans = thetaDirect;
                possible = true;
            }
        }

        if (kk >= 2 * dd)
        {
            double thetaVertical = acos(2 * dd / kk);
            if (dd * tan(thetaVertical) + 1e-9 >= ww)
            {
                if (!possible || thetaVertical < ans)
                {
                    ans = thetaVertical;
                    possible = true;
                }
            }
        }
        if (!possible)
            cout << -1;
        else
            cout << fixed << setprecision(4) << (ans * 180.0 / M_PI);
    }
};

int main()
{
    Solution sol;
    sol.solve();

    return 0;
}