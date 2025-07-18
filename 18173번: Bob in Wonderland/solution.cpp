#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> deg(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (deg[i] > 2) ans += deg[i] - 2;
    }

    cout << ans << "\n";
    return 0;
}