#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> snack(N);

    for (int i = 0; i < N; i++)
    {
        cin >> snack[i];
    }

    vector<long long> dp(N, 0);
    long long answer = 0;

    for (int i = 0; i < N; i++)
    {
        dp[i] = snack[i];

        for (int j = 0; j < i; j++)
        {
            if (snack[j] < snack[i])
            {
                dp[i] = max(dp[i], dp[j] + (long long)snack[i]);
            }
        }

        answer = max(answer, dp[i]);
    }

    cout << answer << endl;

    return 0;
}