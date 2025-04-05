#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> height(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    vector<int> dp(n, 1);
    int max_length = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (height[j] < height[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_length = max(max_length, dp[i]);
    }

    cout << max_length << "\n";
    return 0;
}
