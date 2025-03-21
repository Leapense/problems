#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Meeting
{
    long long start, end;
    int participants;
};

bool cmp(const Meeting &a, const Meeting &b)
{
    return a.end < b.end;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<Meeting> meetings(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> meetings[i].start >> meetings[i].end >> meetings[i].participants;
    }

    sort(meetings.begin(), meetings.end(), cmp);

    vector<long long> dp(N, 0);

    auto findLastNonOverlapping = [&](int i) -> int
    {
        int lo = 0, hi = i - 1;
        int idx = -1;

        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (meetings[mid].end <= meetings[i].start)
            {
                idx = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }

        return idx;
    };

    dp[0] = meetings[0].participants;
    for (int i = 1; i < N; ++i)
    {
        int idx = findLastNonOverlapping(i);
        long long includeCurrent = meetings[i].participants;
        if (idx != -1)
        {
            includeCurrent += dp[idx];
        }
        dp[i] = max(dp[i - 1], includeCurrent);
    }

    cout << dp[N - 1] << "\n";

    return 0;
}