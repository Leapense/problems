#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int N;
    if (scanf("%d", &N) != 1)
        return;
    static long long cnt[1024];
    for (int i = 0; i < 1024; i++)
        cnt[i] = 0;
    for (int i = 0; i < N; i++)
    {
        int x;
        scanf("%d", &x);
        int m = (x == 0 ? 1 : 0);
        while (x > 0)
        {
            m |= 1 << (x % 10);
            x /= 10;
        }
        cnt[m]++;
    }
    static long long f[1024];
    for (int m = 0; m < 1024; m++)
        f[m] = cnt[m];
    for (int d = 0; d < 10; d++)
    {
        for (int mask = 0; mask < 1024; mask++)
        {
            if (mask & (1 << d))
                f[mask] += f[mask ^ (1 << d)];
        }
    }
    long long no_common2 = 0;
    for (int m = 0; m < 1024; m++)
    {
        long long c = cnt[m];
        if (c == 0)
            continue;
        int cmpl = (~m) & 1023;
        no_common2 += c * f[cmpl];
    }
    long long no_common = no_common2 / 2;
    long long total = (long long)N * (N - 1) / 2;
    long long ans = total - no_common;
    cout << ans;
}

#ifndef UNIT_TEST
int main()
{
    solve();
    return 0;
}
#endif