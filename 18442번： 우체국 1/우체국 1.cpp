#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int V, P;
    ll L;
    cin >> V >> P >> L;
    vector<ll> pos(V);
    for (int i = 0; i < V; i++)
    {
        cin >> pos[i];
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
    cout << best << "\n";
    for (auto x : bestRes)
        cout << x << " ";
    cout << "\n";
    return 0;
}