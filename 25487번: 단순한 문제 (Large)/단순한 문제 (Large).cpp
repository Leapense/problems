#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int T;
        cin >> T;

        while (T--)
        {
            long long a, b, c;
            cin >> a >> b >> c;
            cout << min({a, b, c}) << "\n";
        }
    }
};

int main()
{
    Solution().solve();
    return 0;
}