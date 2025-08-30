#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<int, int> normalize_rect(int x, int y) {
    if (x < 0 || (x == 0 && y < 0)) {
        x = -x;
        y = -y;
    }
    return {x, y};
}

pair<int, int> normalize_square(int x, int y) {
    array<pair<int, int>, 4> arr = {
        pair<int, int> {x, y},
        pair<int, int> {-y, x},
        pair<int, int> {-x, -y},
        pair<int, int> {y, -x}
    };
    for (auto &p : arr) {
        if (p.first < 0 || (p.first == 0 && p.second < 0)) {
            p.first = -p.first;
            p.second = -p.second;
        }
    }
    sort(arr.begin(), arr.end());
    return arr[0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, b;

    if (!(cin >> a >> b)) return 0;
    ll A = a - 1;
    ll B = b - 1;
    bool isSquare = (a == b);
    set<pair<int, int>> S;
    for (ll x = -A; x <= A; ++x) {
        ll y2 = A * A - x * x;
        if (y2 < 0) continue;
        ll y = llround(sqrt((long double)y2));
        if (y * y != y2) continue;
        for (int sign: {1, -1}) {
            ll yy = y * sign;
            if (x == 0 && yy == 0) continue;
            ll g = std::gcd(std::llabs(x), std::llabs(yy));

            if (g == 0) continue;
            if ((B * g) % A != 0) continue;
            pair<int, int> rep;

            if (isSquare) rep = normalize_square((int)x, (int)yy);
            else rep = normalize_rect((int)x, (int)yy);
            S.insert(rep);
        }
    }

    cout << S.size() << "\n";

    return 0;
}