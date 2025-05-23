#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);

    int n;
    cin >> n;

    int score1 = 0, score2 = 0;

    while(n--) {
        int m, k;
        cin >> m >> k;

        vector<pair<int, int>> team1(m);
        vector<pair<int, int>> team2(k);

        for (auto &p : team1) {
            cin >> p.first >> p.second;
        }

        for (auto &p : team2) {
            cin >> p.first >> p.second;
        }

        ll min1 = LLONG_MAX, min2 = LLONG_MAX;

        for (auto &p : team1) {
            ll dist = (ll)p.first * p.first + (ll)p.second * p.second;
            if (dist < min1) min1 = dist;
        }

        for (auto &p : team2) {
            ll dist = (ll)p.first * p.first + (ll)p.second * p.second;
            if (dist < min2) min2 = dist;
        }

        if (min1 < min2) {
            int cnt = 0;
            for (auto &p : team1) {
                ll dist = (ll)p.first * p.first + (ll)p.second * p.second;
                if (dist < min2) cnt++;
            }
            score1 += cnt;
        }
        else if (min2 < min1) {
            int cnt = 0;
            for (auto &p : team2) {
                ll dist = (ll)p.first * p.first + (ll)p.second * p.second;
                if (dist < min1) cnt++;
            }
            score2 += cnt;
        }
    }

    cout << score1 << ":" << score2 << "\n";

    return 0;
}