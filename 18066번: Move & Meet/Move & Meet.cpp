#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long x1, y1, d1, x2, y2, d2;
    cin >> x1 >> y1 >> d1 >> x2 >> y2 >> d2;

    long long dx = llabs(x1 - x2), dy = llabs(y1 - y2), dist = dx + dy;
    if (dist > d1 + d2 || (d1 + d2 - dist) % 2 != 0) {
        cout << "impossible\n";
        return 0;
    }

    long long L = max(0LL, dist - d2), U = min(d1, dist);
    if (L > U) {
        cout << "impossible\n";
        return 0;
    }

    long long t = L;
    long long px = x1, py = y1;
    long long mx = min((long long) llabs(x2 - x1), t);

    if (x2 < x1) px -= mx; else px += mx;
    t -= mx;
    long long my = min((long long) llabs(y2 - y1), t);
    if (y2 < y1) py -= my; else py += my;
    cout << px << " " << py << "\n";

    return 0;
}