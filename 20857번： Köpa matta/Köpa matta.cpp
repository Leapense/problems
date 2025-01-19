#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll M, N;
    cin >> M >> N;

    ll B_max = floor(sqrt((double)N));
    ll best_diff = LLONG_MAX;
    ll best_B = 0, best_L = 0;

    for (ll B = B_max; B >= 1; B--) {
        ll L_min = (M + B - 1) / B;
        ll L_max = N / B;
        if (L_min > L_max) continue;

        ll L;
        if (B >= L_min && B <= L_max) {
            L = B;
        } else if (B < L_min) {
            L = L_min;
        } else {
            L = L_max;
        }

        ll diff = abs(B - L);
        if (diff < best_diff) {
            best_diff = diff;
            best_B = B;
            best_L = L;
        }
    }

    if (best_B > best_L) swap(best_B, best_L);
    cout << best_B << " " << best_L << endl;

    return 0;
}