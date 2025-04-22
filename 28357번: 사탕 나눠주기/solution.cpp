#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll findMinX(const vector<ll>& A, ll K) {
    ll lo = 0, hi = *max_element(A.begin(), A.end());
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        __int128 sum = 0;
        for (auto v : A) if (v > mid) {
            sum += v - mid;
            if (sum > K) break;
        }

        if (sum <= K) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; ll K;
    cin >> N >> K;

    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    cout << findMinX(A, K);
    return 0;
}
