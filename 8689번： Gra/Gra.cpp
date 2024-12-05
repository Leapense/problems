#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    vector<ll> dp(n + 1, LLONG_MIN);
    dp[1] = w[1];
    deque<int> dq;
    dq.push_back(1);
    for (int i = 2; i <= n; i++)
    {
        while (!dq.empty() && dq.front() < i - 6)
            dq.pop_front();
        if (!dq.empty())
            dp[i] = w[i] + dp[dq.front()];
        while (!dq.empty() && dp[i] >= dp[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    cout << dp[n];
}