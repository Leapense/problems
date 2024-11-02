#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd_func(ll a, ll b) {
    while(b != 0) {
        ll temp = a % b;
        a = b;
        b = temp;
    }

    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<pair<ll, ll>> cat_totals(N, {0,1});

        for(int j = 0; j < M; ++j) {
            ll V_j;
            cin >> V_j;
            vector<ll> A_j(N);
            for (int i = 0; i < N; ++i) {
                cin >> A_j[i];
            }

            for (int i = 0; i < N; ++i) {
                ll a = cat_totals[i].first;
                ll b = cat_totals[i].second;
                ll c = A_j[i];
                ll d = V_j;

                ll new_num = a * d + b * c;
                ll new_den = b * d;

                ll g = gcd_func(new_num, new_den);
                new_num /= g;
                new_den /= g;

                cat_totals[i] = {new_num, new_den};
            }
        }

        ll max_num = cat_totals[0].first;
        ll max_den = cat_totals[0].second;
        ll min_num = cat_totals[0].first;
        ll min_den = cat_totals[0].second;

        for (int i = 1; i < N; ++i) {
            if (cat_totals[i].first * max_den > max_num * cat_totals[i].second) {
                max_num = cat_totals[i].first;
                max_den = cat_totals[i].second;
            }

            if (cat_totals[i].first * min_den < min_num * cat_totals[i].second) {
                min_num = cat_totals[i].first;
                min_den = cat_totals[i].second;
            }
        }

        ll diff_num = max_num * min_den - min_num * max_den;
        ll diff_den = max_den * min_den;

        if (diff_num == 0) {
            cout << "0\n";
            continue;
        }

        ll g = gcd_func(diff_num, diff_den);
        diff_num /= g;
        diff_den /= g;

        if (diff_den == 1) {
            cout << diff_num << "\n";
        } else {
            cout << diff_num << "/" << diff_den << "\n";
        }
    }

    return 0;
}