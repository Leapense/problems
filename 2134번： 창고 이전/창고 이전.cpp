#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> c(n + 1, 0);
    for (int a = 1; a <= n; a++) {
        cin >> c[a];
    }

    vector<int> d(m + 1, 0);

    for (int b = 1; b <= m; b++) {
        cin >> d[b];
    }

    ll sum_old =0;
    for(int a=1; a<=n; a++) {
        sum_old += (ll)c[a];
    }
    ll sum_new =0;
    for(int b=1; b<=m; b++) {
        sum_new += (ll)d[b];
    }

    ll x = min(sum_old, sum_new);

    ll sum_a =0;
    ll x_left = x;
    for(int a=1; a<=n && x_left >0; a++) {
        if(c[a] ==0) continue;
        ll take = min((ll)c[a], x_left);
        sum_a += a * take;
        x_left -= take;
    }

    ll sum_b =0;
    x_left = x;
    for(int b=1; b<=m && x_left >0; b++) {
        if(d[b] ==0) continue;
        ll take = min((ll)d[b], x_left);
        sum_b += b * take;
        x_left -= take;
    }

    ll y = sum_a + sum_b;

    cout << x << " " << y << endl;

    return 0;
}