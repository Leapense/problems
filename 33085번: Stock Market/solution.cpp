// C++26
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    long long P0, X;
    if (!(cin >> N >> P0 >> X)) return 0;
    vector<long long> D(N);
    long long S = 0;
    for (int i = 0; i < N; ++i) {
        cin >> D[i];
        S += D[i];
    }
    // 문제 보장: S < 0
    long long Sneg = -S; // > 0
    
    long long pref = 0;           // p_j
    long long ans = LLONG_MAX;    // 최솟값 후보
    
    for (int j = 0; j < N; ++j) {
        long long Bj = P0 + pref;
        if (Bj >= X) {
            long long r = (Bj - X) % Sneg; // Bj-X >=0 이므로 음수 mod 우려 없음
            long long cand = X + r;
            if (cand < ans) ans = cand;
        }
        pref += D[j];
    }
    
    if (ans == LLONG_MAX) cout << -1 << '\n';
    else cout << ans << '\n';
    return 0;
}