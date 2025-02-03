#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

class Solution
{
public:
    void solve()
    {
        ll t, a, s;
        cin >> t >> a >> s;

        if (((a - t) & 1LL) || ((s - t) & 1LL))
        {
            cout << -1;
            return;
        }

        ll diff1 = (a - t) / 2;
        ll diff2 = (s - t) / 2;
        ll k0 = max({0LL, -diff1, -diff2});
        ll m = 3 * k0 + (diff1 + diff2);

        cout << m;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol;
    sol.solve();
    return 0;
}