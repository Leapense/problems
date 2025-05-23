#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll M, L, S;
    cin >> M >> L >> S;

    vector<ll> P(M+1, 0);
    for (ll i = 1; i <= M; i++) cin >> P[i];
    ll answer = LLONG_MAX;

    for (ll k = 0; k <= M; k++) {
        ll time_A, time_B;
        if (k == 0) {
            time_A = 0;
            if (M >= 1) {
                time_B = L - P[1] + M * S;
            } else {
                time_B = 0;
            }
        }
        else if (k == M) {
            time_A = P[M] + M * S;
            time_B = 0;
        } else {
            time_A = P[k] + k * S;
            time_B = L - P[k+1] + (M - k) * S;
        }

        ll T;

        if (k == 0 && M >= 1) {
            T = max(time_A, time_B);
        } else if (k == M) {
            T = max(time_A, time_B);
        } else {
            T = max(time_A, time_B);
        }

        if (T < answer) {
            answer = T;
        }
    }

    cout << answer << "\n";

    return 0;
}