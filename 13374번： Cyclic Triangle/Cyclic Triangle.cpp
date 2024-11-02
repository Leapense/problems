#include <iostream>
using namespace std;

typedef long long ll;

ll getPositionIndex(ll N, ll R, ll C) {
    ll s = R + C;
    ll positionIndex;

    if (s < N) {
        positionIndex = s * (s + 1) / 2 + R;
    } else {
        ll t = 2 * N - s - 1;
        ll totalPositions = N * N;
        positionIndex = totalPositions - t *(t + 1) / 2 + (N - 1 - C);
    }
    return positionIndex;
}

int main()
{
    int T;
    cin >> T;

    while (T--) {
        ll N, Q;
        cin >> N >> Q;
        for (int i = 0; i < Q; i++) {
            ll R, C;
            cin >> R >> C;
            ll idx = getPositionIndex(N, R, C);
            cout << idx % 10 << endl;
        }
    }

    return 0;
}