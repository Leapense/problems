#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solver
{
public:
    void solve()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n, k;
        cin >> n >> k;
        vector<long long> w(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> w[i];
        vector<long long> P(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            P[i] = P[i - 1] + w[i];
        }
        long long total = P[n];
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int leftBound = max(1, i - k);
            int rightBound = min(n, i + k);
            long long leftSum = P[i - 1] - P[leftBound - 1];
            long long rightSum = P[rightBound] - P[i];
            int d = (i - leftBound) + (rightBound - i);
            long long current = total - (leftSum + rightSum) + (long long)d * w[i];
            ans = max(ans, current);
        }
        cout << ans;
    }
};

int main()
{
    Solver solver;
    solver.solve();
    return 0;
}