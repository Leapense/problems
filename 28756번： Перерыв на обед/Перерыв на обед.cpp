#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios::badbit | ios::failbit);

    int xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;

    int n;
    cin >> n;

    double ans = 1e18;

    for (int i = 0; i < n; ++i) {
        int xi, yi, ti;
        cin >> xi >> yi >> ti;

        double dist_s_i = sqrt((xi - xs)*(xi - xs) + (yi - ys)*(yi - ys));
        double dist_i_t = sqrt((xi - xt)*(xi - xt) + (yi - yt)*(yi - yt));

        double total_time = dist_s_i + ti + dist_i_t;

        if (total_time < ans) {
            ans = total_time;
        }
    }

    cout << fixed << setprecision(15) << ans << endl;

    return 0;
}