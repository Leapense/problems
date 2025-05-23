#include <bits/stdc++.h>
using namespace std;

int soldiersToRemove(int N, const vector<long long> &arr)
{
    vector<long long> dp(N, 1);
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
        mx = max(mx, dp[i]);
    }
    return N - mx;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    struct TestUnit
    {
        int N;
        vector<long long> powers;
        int expected;
    };

    vector<TestUnit> tests = {
        {1, {10}, 0},
        {2, {10, 9}, 0},
        {2, {5, 5}, 1},
        {5, {5, 4, 3, 2, 1}, 0},
        {5, {1, 2, 3, 4, 5}, 4},
        {7, {15, 11, 4, 8, 5, 2, 4}, 2},
        {7, {10, 10, 10, 9, 9, 8, 8}, 4},
        {10, {8, 2, 2, 2, 9, 9, 9, 4, 4, 3}, 7},
        {10, {10, 8, 6, 6, 6, 6, 5, 5, 2, 1}, 4},
        {12, {100, 98, 98, 97, 96, 70, 70, 68, 20, 20, 19, 1}, 3}};

    for (int i = 0; i < (int)tests.size(); i++)
    {
        int result = soldiersToRemove(tests[i].N, tests[i].powers);
        cout << "Test #" << (i + 1)
             << " | Calculated: " << result
             << " | Expected: " << tests[i].expected
             << ((result == tests[i].expected) ? " | PASSED\n" : " | FAILED\n");
    }
    return 0;
}
