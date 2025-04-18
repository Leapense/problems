#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> H(N);
    for(int i = 0; i < N; i++){
        cin >> H[i];
    }

    // 첫/마지막 산은 H^2 * 2, 나머지는 H^2 * 4
    ll ans = 0;
    ans += 2LL * H[0] * H[0];
    ans += 2LL * H[N-1] * H[N-1];
    for(int i = 1; i < N-1; i++){
        ans += 4LL * H[i] * H[i];
    }

    cout << ans << "\n";
    return 0;
}
