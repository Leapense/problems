#include <iostream>
#include <numeric>
#include <cassert>
#include <cmath>

using namespace std;

using ll = long long;

ll ceil_div(ll a, ll b) {
    return (a + b - 1) / b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll xb, yb;
    cin >> xb >> yb;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    ll g = std::gcd(xb, yb);

    ll step_x = xb / g;
    ll step_y = yb / g;

    if (g == 1) {
        cout << "Yes\n";
        return 0;
    }

    ll Lx = ceil_div(x1, step_x);
    ll Rx = x2 / step_x;
    ll Ly = ceil_div(y1, step_y);
    ll Ry = y2 / step_y;

    ll L = max(Lx, Ly);
    ll R = min(Rx, Ry);

    ll blocking_i = -1;
    if (L > 1) {
        blocking_i = 1;
    } else {
        if (R < g - 1) {
            blocking_i = R + 1;
        }
    }

    if (blocking_i == -1) {
        cout << "Yes\n";
    } else {
        cout << "No\n" << (step_x * blocking_i) << " " << (step_y * blocking_i) << "\n";
    }

    return 0;
}
