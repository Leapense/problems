#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    struct Cls { unsigned long long mask; int cred; };
    vector<Cls> a;
    a.reserve(n);
    
    for (int i = 0; i < n; ++i) {
        int w, s, e;
        cin >> w >> s >> e;
        if (w == 5) continue;
        unsigned long long m = 0ULL;
        for (int t = s; t <= e; ++t) {
            int slot = (w - 1) * 10 + (t - 1);
            m |= (1ULL << slot);
        }
        int cred = e - s + 1;
        a.push_back({m, cred});
    }

    long long ans = 0;
    function<void(size_t, unsigned long long, int)> dfs = [&](size_t i, unsigned long long used, int sum) {
        if (sum == k) { ++ans; return; }
        if (sum > k || i == a.size()) return;

        dfs(i + 1, used, sum);
        if ((used & a[i].mask) == 0ULL) {
            dfs(i + 1, used | a[i].mask, sum + a[i].cred);
        }
    };

    dfs(0, 0ULL, 0);
    cout << ans << '\n';
    return 0;
}