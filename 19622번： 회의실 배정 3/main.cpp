#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Meeting
{
    long long start, end, people;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<Meeting> meetings(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> meetings[i].start >> meetings[i].end >> meetings[i].people;
    }

    sort(meetings.begin(), meetings.end(), [](const Meeting &a, const Meeting &b)
         { return a.start < b.start; });

    if (N == 0)
    {
        cout << 0;
        return 0;
    }

    if (N == 1)
    {
        cout << meetings[0].people;
        return 0;
    }

    vector<long long> dp(N, 0);
    dp[0] = meetings[0].people;
    dp[1] = max(meetings[0].people, meetings[1].people);

    for (int i = 2; i < N; ++i)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + meetings[i].people);
    }

    cout << dp[N - 1];

    return 0;
}