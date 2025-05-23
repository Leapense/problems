#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int M;
    cin >> M;
    vector<int> Ps(M);

    for (auto &p : Ps) cin >> p;
    int N = 1;

    while (true) {
        bool ok = true;
        for (auto P : Ps) {
            double lower = (P - 0.5) / 100.0 * N;
            double upper = (P + 0.5) / 100.0 * N;
            int kl = ceil(lower);
            int ku = floor(upper - 1e-9);

            if (kl > ku) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << N;
            return 0;
        }
        N++;
    }
}