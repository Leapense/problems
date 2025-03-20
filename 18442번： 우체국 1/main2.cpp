#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
string solveCase(istream &in)
{
    ostringstream out;
    int V, P;
    ll L;
    in >> V >> P >> L;
    vector<ll> pos(V);
    for (int i = 0; i < V; i++)
    {
        in >> pos[i];
    }
    ll best = INF;
    vector<ll> bestRes;
    for (int start = 0; start < V; start++)
    {
        vector<ll> A(V);
        for (int i = 0; i < V; i++)
        {
            int idx = (start + i) % V;
            A[i] = pos[idx];
            if (idx < start)
                A[i] += L;
        }
        vector<vector<ll>> cost(V, vector<ll>(V, 0));
        vector<vector<int>> choice(V, vector<int>(V, 0));
        for (int i = 0; i < V; i++)
        {
            for (int j = i; j < V; j++)
            {
                int m = (i + j) / 2;
                ll sum = 0;
                for (int k = i; k <= j; k++)
                {
                    sum += abs(A[k] - A[m]);
                }
                cost[i][j] = sum;
                choice[i][j] = m;
            }
        }
        vector<vector<ll>> dp(V + 1, vector<ll>(P + 1, INF));
        vector<vector<int>> rec(V + 1, vector<int>(P + 1, -1));
        dp[V][0] = 0;
        for (int i = V; i >= 0; i--)
        {
            for (int p = 1; p <= P; p++)
            {
                for (int j = i; j < V; j++)
                {
                    if (dp[j + 1][p - 1] == INF)
                        continue;
                    ll cur = cost[i][j] + dp[j + 1][p - 1];
                    if (cur < dp[i][p])
                    {
                        dp[i][p] = cur;
                        rec[i][p] = j;
                    }
                }
            }
        }
        if (dp[0][P] < best)
        {
            best = dp[0][P];
            vector<ll> curRes;
            int i = 0, p = P;
            while (p > 0)
            {
                int j = rec[i][p];
                int med = choice[i][j];
                curRes.push_back(A[med] % L);
                i = j + 1;
                p--;
            }
            sort(curRes.begin(), curRes.end());
            bestRes = curRes;
        }
    }
    out << best << "\n";
    for (auto x : bestRes)
        out << x << " ";
    out << "\n";
    return out.str();
}
#ifdef RUN_TESTS
void runTests()
{
    vector<pair<string, string>> tests = {
        {"10 5 200\n1 2 3 6 7 9 11 22 44 50\n", "9\n2 7 22 44 50 \n"},
        {"10 5 51\n1 2 3 6 7 9 11 22 44 50\n", "8\n1 6 9 22 44 \n"},
        {"1 1 10\n5\n", "0\n5 \n"},
        {"4 4 100\n0 20 40 80\n", "0\n0 20 40 80 \n"},
        {"6 3 100\n2 3 4 95 96 97\n", "3\n2 4 96 \n"},
        {"5 2 100\n10 10 20 30 90\n", "30\n10 90 \n"}};
    for (auto &test : tests)
    {
        istringstream iss(test.first);
        string result = solveCase(iss);
        if (result == test.second)
        {
            cout << "Test passed\n";
        }
        else
        {
            cout << "Test failed\nInput:\n"
                 << test.first << "Expected:\n"
                 << test.second << "Got:\n"
                 << result << "\n";
        }
    }
}
#endif
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef RUN_TESTS
    runTests();
#else
    cout << solveCase(cin);
#endif
    return 0;
}
