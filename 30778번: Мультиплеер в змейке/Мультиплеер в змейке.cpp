#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);

    ll N, M;
    cin >> N >> M;

    ll a1, b1, a2, b2;
    cin >> a1 >> b1;
    cin >> a2 >> b2;

    ll delta_a = abs(a1 - a2);

    if (N > 1) {
        delta_a = min(delta_a, N - delta_a);
    } else {
        delta_a = 0;
    }

    ll delta_b = abs(b1 - b2);

    if (M > 1) {
        delta_b = min(delta_b, M - delta_b);
    } else {
        delta_b = 0;
    }

    ll distance = delta_a + delta_b;
    ll k = (distance + 1) / 2;
    cout << k << "\n";

    return 0;
}