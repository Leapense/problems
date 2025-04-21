#include <bits/stdc++.h>
using namespace std;

int countReachable(const string &s, const vector<pair<int, int>> &pts)
{
    long long cntR = 0, cntU = 0, cntX = 0;
    for (char c : s)
    {
        if (c == 'R')
            ++cntR;
        else if (c == 'U')
            ++cntU;
        else if (c == 'X')
            ++cntX;
    }

    int ans = 0;
    for (auto [x, y] : pts)
    {
        long long needX = x - 1, needY = y - 1;
        long long L = max({0LL, needX - cntR, needY - cntU});
        long long U = min({cntX, needX, needY});
        if (L <= U)
            ++ans;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    string s;
    cin >> s;

    int K;
    cin >> K;

    vector<pair<int, int>> pts(K);
    for (int i = 0; i < K; ++i)
    {
        cin >> pts[i].first >> pts[i].second;
    }

    cout << countReachable(s, pts) << "\n";

    return 0;
}