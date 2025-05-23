#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    unordered_map<long long, long long> mp;
    long long ans = 0;

    for (int i = 0; i < N; i++)
    {
        long long X, T, C;
        cin >> X >> T >> C;
        long long key = X - T;
        mp[key] += C;
    }

    for (auto &p : mp)
    {
        ans = max(ans, p.second);
    }

    cout << ans << "\n";

    return 0;
}