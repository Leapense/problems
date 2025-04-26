#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    if (!(cin >> n >> k))
        return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    unordered_map<long long, int> cnt;
    int distinct = 0;
    for (int i = 0; i < k; ++i)
        if (cnt[a[i]]++ == 0)
            ++distinct;
    int bestPos = 0, bestVal = distinct;
    for (int r = k; r < n; ++r)
    {
        long long leftVal = a[r - k];
        if (--cnt[leftVal] == 0)
        {
            cnt.erase(leftVal);
            --distinct;
        }
        if (cnt[a[r]]++ == 0)
            ++distinct;
        if (distinct > bestVal)
        {
            bestVal = distinct;
            bestPos = r - k + 1;
        }
    }
    cout << bestPos + 1 << '\n';
    return 0;
}