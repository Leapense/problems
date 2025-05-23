#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <cassert>

using namespace std;

void solve()
{
    int N;
    cin >> N;

    vector<string> bundles(N);
    vector<int> internalTrans(N, 0);
    vector<char> first(N), last(N);

    // Read the bundles and compute internal transitions.
    for (int i = 0; i < N; ++i)
    {
        cin >> bundles[i];
        first[i] = bundles[i].front();
        last[i] = bundles[i].back();
        for (size_t j = 1; j < bundles[i].size(); ++j)
        {
            if (bundles[i][j] != bundles[i][j - 1])
                internalTrans[i]++;
        }
    }

    // Precompute boundary cost between bundles.
    vector<vector<int>> cost(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (i == j)
                continue;
            cost[i][j] = (last[i] != first[j]) ? 1 : 0;
        }
    }

    // DP over bitmask: dp[mask][i] = minimal boundary transitions cost.
    const int INF = numeric_limits<int>::max() / 2;
    vector<vector<int>> dp(1 << N, vector<int>(N, INF));

    // Base case: one bundle is used.
    for (int i = 0; i < N; ++i)
    {
        dp[1 << i][i] = 0;
    }

    // Fill dp table.
    for (int mask = 0; mask < (1 << N); ++mask)
    {
        for (int i = 0; i < N; ++i)
        {
            if (!(mask & (1 << i)))
                continue;
            for (int j = 0; j < N; ++j)
            {
                if (mask & (1 << j))
                    continue;
                int nextMask = mask | (1 << j);
                dp[nextMask][j] = min(dp[nextMask][j], dp[mask][i] + cost[i][j]);
            }
        }
    }

    // Answer is minimum over dp[(1<<N)-1][i] + sum of internal transitions for all bundles.
    int minBoundaryCost = INF;
    for (int i = 0; i < N; ++i)
    {
        minBoundaryCost = min(minBoundaryCost, dp[(1 << N) - 1][i]);
    }

    int totalInternal = 0;
    for (int i = 0; i < N; ++i)
    {
        totalInternal += internalTrans[i];
    }

    cout << totalInternal + minBoundaryCost << "\n";
}

#ifdef DEBUG
void runTest(const string &testInput, const string &expectedOutput)
{
    istringstream iss(testInput);
    streambuf *cinbuf = cin.rdbuf();
    cin.rdbuf(iss.rdbuf());

    ostringstream oss;
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(oss.rdbuf());

    solve();

    cin.rdbuf(cinbuf);
    cout.rdbuf(coutbuf);

    string output = oss.str();
    if (output == expectedOutput)
    {
        cout << "Test passed.\n";
    }
    else
    {
        cout << "Test failed.\n";
        cout << "Input:\n"
             << testInput << "\n";
        cout << "Expected output:\n"
             << expectedOutput;
        cout << "Your Output:\n"
             << output << "\n";
    }
}

int main()
{
    vector<pair<string, string>> tests = {
        {"1\n0\n", "0\n"},
        {"1\n111\n", "0\n"},
        {"2\n1010\n0101\n", "6\n"},
        {"3\n000\n00\n0000\n", "0\n"},
        {"4\n1011\n1000\n011100\n010\n", "7\n"}};

    for (auto &[input, expected] : tests)
    {
        runTest(input, expected);
    }

    return 0;
}

#else

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

#endif