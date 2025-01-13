#include <bits/stdc++.h>
using namespace std;

long long abs_val(long long x) {
    return x < 0 ? -x : x;
}

int sign_func(long long x) {
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long x1, y1, d1;
    long long x2, y2, d2;

    cin >> x1 >> y1 >> d1;
    cin >> x2 >> y2 >> d2;

    long long initial_distance = abs_val(x1 - x2) + abs_val(y1 - y2);

    if (initial_distance > d1 + d2) {
        cout << "impossible";
        return 0;
    }

    if ((d1 + d2 - initial_distance) % 2 != 0) {
        cout << "impossible";
        return 0;
    }

    long long t = (d1 + initial_distance - d2) / 2;

    long long dx = x2 - x1;
    long long dy = y2 - y1;

    long long step_x = min(t, abs_val(dx));
    int direction_x = sign_func(dx);
    long long xm = x1 + step_x * direction_x;

    long long remaining_steps = t - step_x;

    long long step_y = min(remaining_steps, abs_val(dy));
    int direction_y = sign_func(dy);
    long long ym = y1 + step_y * direction_y;

    long long distance1 = abs_val(xm - x1) + abs_val(ym - y1);
    long long distance2 = abs_val(xm - x2) + abs_val(ym - y2);

    if (distance1 > d1 || distance2 > d2) {
        cout << "impossible" << endl;
        return 0;
    }

    if ((d1 - distance1) % 2 != 0 || (d2 - distance2) % 2 != 0) {
        cout << "impossible" << endl;
        return 0;
    }

    cout << xm << " " << ym << endl;

    return 0;
}