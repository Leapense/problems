#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 확장 유클리드: ax + by = g의 특해 (x,y)와 최대공약수 g 반환
ll extgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    ll x1, y1;
    ll g = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

// b > 0일 때, 정수 a/b를 내림(floor)한 값
ll div_floor(ll a, ll b) {
    if (a >= 0) return a / b;
    return -((-a + b - 1) / b);
}

// b > 0일 때, 정수 a/b를 올림(ceil)한 값
ll div_ceil(ll a, ll b) {
    if (a >= 0) return (a + b - 1) / b;
    return -((-a) / b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        ll a, b, S;
        cin >> a >> b >> S;

        ll x0, y0;
        ll g = extgcd(a, b, x0, y0);
        if (S % g != 0) {
            cout << "Impossible\n";
            continue;
        }

        ll mult = S / g;
        x0 *= mult;
        y0 *= mult;

        ll bg = b / g;
        ll ag = a / g;

        ll k_min = div_ceil(-x0, bg);
        ll k_max = div_floor(y0, ag);

        if (k_min > k_max) {
            cout << "Impossible\n";
            continue;
        }

        ll delta = bg - ag;
        ll k_best = (delta > 0 ? k_min : delta < 0 ? k_max : k_min);

        ll x = x0 + bg * k_best;
        ll y = y0 - ag * k_best;
        cout << x << ' ' << y << "\n";
    }

    return 0;
}

