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

    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }

    vector<int> dp(N + 1, 0);
    if (N >= 1)
        dp[1] = A[1];
    if (N >= 2)
        dp[2] = max(A[1], A[2]);
    for (int i = 3; i <= N; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + A[i]);
    }

    cout << dp[N] << "\n";
    return 0;
}