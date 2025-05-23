#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> timeAcc(n + 1, 0);
    for (int i = 2; i <= n; i++)
    {
        string type;
        cin >> type;
        if (type == "Patrik")
        {
            long long t;
            cin >> t;
            timeAcc[i] = t;
        }
        else
        {
            int y;
            long long t;
            cin >> y >> t;
            timeAcc[i] = timeAcc[y] + t;
        }
    }
    long long minDiff = 1e18;
    int idx = 1;
    for (int i = 1; i < n; i++)
    {
        long long diff = timeAcc[i + 1] - timeAcc[i];
        if (diff < minDiff)
        {
            minDiff = diff;
            idx = i;
        }
    }

    cout << minDiff << " " << idx << " " << idx + 1;
    return 0;
}