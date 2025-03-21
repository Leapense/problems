#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cassert>

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

void solve(istream &in, ostream &out)
{
    int N;
    in >> N;
    vector<Meeting> meetings(N);
    for (int i = 0; i < N; ++i)
    {
        in >> meetings[i].start >> meetings[i].end >> meetings[i].participants;
    }

    // Sort meetings by end time
    sort(meetings.begin(), meetings.end(), cmp);

    // dp[i] stores maximum participants up to the i-th meeting (0-indexed)
    vector<long long> dp(N, 0);

    // Binary search to find the last meeting that doesn't conflict with meeting i.
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

    out << dp[N - 1] << "\n";
}

#ifdef DEBUG
// Test harness for unit testing
void runTests()
{
    {
        // Sample test case
        stringstream input("6\n10 40 80\n30 60 60\n50 80 70\n70 100 100\n90 120 40\n110 140 50\n");
        stringstream output;
        solve(input, output);
        string result = output.str();
        // Expected output: 230
        assert(result == "230\n");
    }

    {
        // Single meeting test
        stringstream input("1\n5 10 100\n");
        stringstream output;
        solve(input, output);
        string result = output.str();
        // Expected output: 100
        assert(result == "100\n");
    }

    {
        // Non-overlapping meetings test
        stringstream input("3\n0 1 10\n1 2 20\n2 3 30\n");
        stringstream output;
        solve(input, output);
        string result = output.str();
        // Expected output: 60 (10+20+30)
        assert(result == "60\n");
    }

    {
        // Overlapping meetings test
        // Meetings: (0,10,10), (5,15,20), (10,20,30)
        // Best is to choose meetings 1 and 3 -> 10 + 30 = 40
        stringstream input("3\n0 10 10\n5 15 20\n10 20 30\n");
        stringstream output;
        solve(input, output);
        string result = output.str();
        // Expected output: 40
        assert(result == "40\n");
    }

    {
        // Additional test: Two overlapping meetings, best is to choose the one with higher participants.
        stringstream input("2\n0 5 50\n3 10 70\n");
        stringstream output;
        solve(input, output);
        string result = output.str();
        // Expected output: 70 (choose the second meeting)
        assert(result == "70\n");
    }

    cout << "All tests passed.\n";
}
#endif

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef DEBUG
    runTests();
#else
    solve(cin, cout);
#endif

    return 0;
}