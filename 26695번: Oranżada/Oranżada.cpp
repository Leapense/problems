#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    unordered_map<int, int> leftmost;

    for (int i = 0; i < n; i++)
    {
        if (!leftmost.count(a[i]))
        {
            leftmost[a[i]] = i + 1;
        }
    }

    if ((int)leftmost.size() < k)
    {
        cout << -1 << "\n";
        return 0;
    }

    vector<int> positions;
    positions.reserve(leftmost.size());
    for (auto &p : leftmost)
    {
        positions.push_back(p.second);
    }

    sort(positions.begin(), positions.end());
    long long sumPos = 0;

    for (int i = 0; i < k; i++)
    {
        sumPos += positions[i];
    }

    long long ans = sumPos - (long long)k * (k + 1) / 2;
    cout << ans << "\n";

    return 0;
}