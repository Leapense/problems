#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<long long> a;

bool feasible(long long x)
{
    int l = 0, r = N - 1;
    int bins = 0;
    while (l <= r)
    {
        if (a[r] > x)
            return false;
        if (l == r)
        {
            bins++;
            break;
        }
        if (a[l] + a[r] <= x)
        {
            l++;
            r--;
            bins++;
        }
        else
        {
            r--;
            bins++;
        }
    }

    return bins <= M;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    a.resize(N);

    for (auto &v : a)
        cin >> v;
    sort(a.begin(), a.end());

    long long lo = a.back();
    long long hi = (N >= 2 ? a[N - 1] + a[N - 2] : a.back());
    long long ans = hi;

    while (lo <= hi)
    {
        long long mid = lo + ((hi - lo) >> 1);
        if (feasible(mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout << ans;
    return 0;
}