#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
        long long n;
        cin >> n;

        if (n == 1)
        {
            cout << "0\n";
            return;
        }

        vector<long long> d(n);
        for (auto &x : d)
            cin >> x;
        long long d_min = *min_element(d.begin(), d.end());
        long long sum = accumulate(d.begin(), d.end(), 0LL);
        long long total = sum + (n - 2) * d_min;
        cout << total << endl;
    }
};

int main()
{
    Solution s;
    s.solve();

    return 0;
}