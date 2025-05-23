#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class CatCafe
{
public:
    void solve()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n;
        long long k;

        cin >> n >> k;
        vector<long long> w(n);

        for (int i = 0; i < n; i++)
            cin >> w[i];
        sort(w.begin(), w.end());

        int left = 0, right = n - 1, ans = 0;

        while (left < right)
        {
            if (w[left] + w[right] <= k)
            {
                ans++;
                left++;
                right--;
            }
            else
            {
                right--;
            }
        }

        cout << ans;
    }
};

int main()
{
    CatCafe cc;
    cc.solve();

    return 0;
}