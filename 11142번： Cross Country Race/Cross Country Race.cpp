#include <bits/stdc++.h>
#define EPS 1e-8

using namespace std;

int n, s, v[1000];

int race() {
    static double t[1000];

    int i, j;

    for (i = 0; i < n; i++) t[i] = i + (double)s / v[i];
    for (i = 1, j = 0; i < n; i++) {
        if (t[i] - EPS < t[i - 1]) {
            v[j++] = v[i];
            if (t[i] < t[i - 1]) {
                t[i] = t[i - 1];
            }
        }
    }

    return n = j;
}

int main()
{
    int cases, i, ans;

    cin >> cases;

    while(cases--) {
        cin >> n >> s;
        for (i = 0; i < n; i++) cin >> v[i];

        ans = 1;

        while(race() > 0) ans++;
        cout << ans << "\n";
    }
    return 0;
}