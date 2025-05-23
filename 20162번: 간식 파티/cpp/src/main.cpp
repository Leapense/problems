#include <iostream>
#include <vector>
#include <algorithm>
#include "main.h"

using namespace std;

long long maxSatisfaction(const vector<int> &snacks)
{
    int N = snacks.size();
    vector<long long> dp(N, 0);
    long long answer = 0;
    for (int i = 0; i < N; i++)
    {
        dp[i] = snacks[i];
        for (int j = 0; j < i; j++)
        {
            if (snacks[j] < snacks[i])
            {
                dp[i] = max(dp[i], dp[j] + (long long)snacks[i]);
            }
        }

        answer = max(answer, dp[i]);
    }

    return answer;
}

#ifndef UNIT_TESTS
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> snacks(N);
    for (int i = 0; i < N; i++)
    {
        cin >> snacks[i];
    }

    cout << maxSatisfaction(snacks) << "\n";
    return 0;
}
#endif