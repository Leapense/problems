#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> a(N);

    for (auto &x : a) cin >> x;

    vector<int> ans(N, 0);

    for (int k = 0; k <= 30; k++) {
        int cnt = 0;
        for(int i = 0; i < N; i++) if ((a[i] >> k) & 1) cnt++;
        for(int i = 0; i < cnt; i++) ans[i] += (1 << k);
    }

    for (int i = 0; i < N; i++) cout << ans[i] << (i < N - 1 ? " " : "\n");

    return 0;
}