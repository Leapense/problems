#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double maxBits = 4 * pow(2, 20);
    vector<double> logSum;
    logSum.push_back(0.0);

    int n = 1;
    while (true)
    {
        double curr = logSum.back() + log2(n);
        if (curr > maxBits)
            break;
        logSum.push_back(curr);
        n++;
    }
    int y;

    while (cin >> y && y)
    {
        int k = (y - 1960) / 10;
        double bits = 4 * pow(2, k);
        int lo = 0, hi = logSum.size() - 1, ans = 0;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (logSum[mid] <= bits)
            {
                ans = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}