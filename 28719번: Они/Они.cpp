#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution
{
public:
    void solve()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n;
        cin >> n;

        vector<long long> a(n + 1), prefix(n + 1, 0), suffix(n + 2, 0);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        prefix[1] = a[1];
        for (int i = 2; i <= n; i++)
            prefix[i] = prefix[i - 1] + a[i];
        suffix[n] = a[n];
        for (int i = n - 1; i >= 1; i--)
            suffix[i] = suffix[i + 1] + a[i];
        long long bestDiff = 1LL << 62;
        int bestL = 0, bestR = 0, j = n;
        for (int i = 1; i <= n - 1; i++)
        {
            while (j - 1 > i && abs(prefix[i] - suffix[j - 1]) <= abs(prefix[i] - suffix[j]))
            {
                j--;
            }

            long long diff = abs(prefix[i] - suffix[j]);
            if (diff < bestDiff)
            {
                bestDiff = diff;
                bestL = i;
                bestR = j;
            }
        }

        cout << bestDiff << " " << bestL << " " << bestR;
    }
};

int main()
{
    Solution sol;
    sol.solve();
    return 0;
}