#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> dp(N + 1, 0);
    for (int i = 0; i < M; i++)
    {
        int days, pages;
        cin >> days >> pages;
        for (int j = N; j >= days; j--)
        {
            dp[j] = max(dp[j], dp[j - days] + pages);
        }
    }

    cout << dp[N] << '\n';

    return 0;
}