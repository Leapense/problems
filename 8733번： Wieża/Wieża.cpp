#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> p(n);
    p[0] = a[0];

    for (int i = 1; i < n; i++) {
        p[i] = max(p[i - 1], a[i]);
    }

    for(int i = 0; i < m; i++) {
        long long h;
        cin >> h;

        int idx = (int)(upper_bound(p.begin(), p.end(), h - 1) - p.begin());
        cout << idx << (i == m - 1 ? "\n" : " ");
    }

    return 0;
}