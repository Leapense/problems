#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> T(K);
    for (int i = 0; i < K; i++) {
        cin >> T[i];
    }

    int minT = *min_element(T.begin(), T.end());
    ll lo = 1, hi = static_cast<ll>(minT) * N, ans = hi;

    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        ll total = 0;

        for (int i = 0; i < K; i++) {
            total += mid / T[i];
            if (total >= N) break;
        }

        if (total >= N) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}
