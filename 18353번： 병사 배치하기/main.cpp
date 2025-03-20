#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<long long> arr(N), dp(N, 1);

    for (int i = 0; i < N; i++)
        cin >> arr[i];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    long long mx = 0;
    for (int i = 0; i < N; i++)
    {
        if (dp[i] > mx)
            mx = dp[i];
    }

    cout << N - mx << "\n";
    return 0;
}