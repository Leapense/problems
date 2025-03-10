#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(n + 2, -1));
    function<int(int, int)> partitions = [&](int remaining, int minPart) -> int
    {
        if (remaining == 0)
            return 1;
        if (remaining < minPart)
            return 0;
        if (dp[remaining][minPart] != -1)
            return dp[remaining][minPart];
        int count = partitions(remaining - minPart, minPart) + partitions(remaining, minPart + 1);
        dp[remaining][minPart] = count;
        return count;
    };
    cout << partitions(n, 5);
    return 0;
}