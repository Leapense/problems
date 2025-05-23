#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

class Solution
{
public:
    void solve()
    {
        ll N;
        cin >> N;
        ll temp = N;

        int cnt2 = 0, cnt5 = 0;
        while (temp % 2 == 0)
        {
            cnt2++;
            temp /= 2;
        }

        temp = N;
        while (temp % 5 == 0)
        {
            cnt5++;
            temp /= 5;
        }

        vector<ll> ans;
        for (int i = 0; i <= cnt2; i++)
        {
            for (int j = 0; j <= cnt5; j++)
            {
                ll x = 1;
                for (int k = 0; k < i; k++)
                {
                    x *= 2;
                }
                for (int k = 0; k < j; k++)
                {
                    x *= 5;
                }
                if (N % x == 0)
                    ans.push_back(x);
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        cout << ans.size() << "\n";
        for (auto &x : ans)
        {
            cout << x << "\n";
        }
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