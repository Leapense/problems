#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    int maxN = 0;
    vector<int> queries(T);

    for (int i = 0; i < T; i++)
    {
        cin >> queries[i];
        if (queries[i] > maxN)
            maxN = queries[i];
    }

    vector<bool> isPrime(maxN + 1, true);
    if (maxN >= 0)
        isPrime[0] = false;
    if (maxN >= 1)
        isPrime[1] = false;
    for (int i = 2; i * i <= maxN; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= maxN; j += i)
                isPrime[j] = false;
        }
    }

    vector<int> dp(maxN + 1, 0);
    dp[0] = 0;
    if (maxN >= 1)
        dp[1] = 1;
    for (int n = 2; n <= maxN; n++)
    {
        if (isPrime[n])
        {
            dp[n] = (n - 2 >= 1 ? dp[n - 2] : 0) + 1;
        }
        else
        {
            dp[n] = dp[n - 1] + 1;
        }
    }

    for (auto n : queries)
    {
        cout << dp[n] << "\n";
    }

    return 0;
}