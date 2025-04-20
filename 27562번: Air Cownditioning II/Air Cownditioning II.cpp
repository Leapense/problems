#include <bits/stdc++.h>
using namespace std;
struct Cow
{
    int s, t, c;
};
struct Ac
{
    int a, b, p, m;
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    if (!(cin >> N >> M))
        return 0;
    vector<Cow> cows(N);
    for (auto &x : cows)
        cin >> x.s >> x.t >> x.c;
    vector<Ac> acs(M);
    for (auto &x : acs)
        cin >> x.a >> x.b >> x.p >> x.m;
    const int INF = 1e9;
    int ans = INF;
    for (int mask = 0; mask < (1 << M); ++mask)
    {
        int cost = 0;
        for (int i = 0; i < M; ++i)
            if (mask >> i & 1)
                cost += acs[i].m;
        if (cost >= ans)
            continue;
        int cool[101] = {0};
        for (int i = 0; i < M; ++i)
            if (mask >> i & 1)
            {
                for (int j = acs[i].a; j <= acs[i].b; ++j)
                    cool[j] += acs[i].p;
            }
        bool ok = true;
        for (const auto &cw : cows)
        {
            for (int j = cw.s; j <= cw.t; ++j)
            {
                if (cool[j] < cw.c)
                {
                    ok = false;
                    break;
                }
            }
            if (!ok)
                break;
        }
        if (ok)
            ans = cost;
    }
    cout << ans << "\n";
    return 0;
}
