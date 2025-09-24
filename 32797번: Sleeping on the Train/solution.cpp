#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

static i64 solve_one(i64 n, i64 t, i64 a, i64 b, const vector<i64>& s, int init_dir) {
    i64 turns = 0;
    int dir = init_dir;

    if (dir == +1) {
        if (s[0] >= a) {

        } else {
            ++turns;
            dir = -1;
        }
    } else {
        if (s[0] <= a - 1) {

        } else {
            ++turns;
            dir = +1;
        }
    }

    i64 cur = s[0];

    for (i64 i = 1; i < t; ++i) {
        if (dir == +1) {
            if (s[i] >= cur) {

            } else {
                ++turns;
                dir = -1;
            }
        } else {
            if (s[i] <= cur) {

            } else {
                ++turns;
                dir = +1;
            }
        }
        cur = s[i];
    }

    if (dir == +1) {
        if (b >= cur + 1) {

        } else {
            ++turns;
        }
    } else {
        if (b <= cur) {

        } else {
            ++turns;
        }
    }
    return turns;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n, t, a, b;
    if (!(cin >> n >> t >> a >> b)) return 0;

    vector<i64> s(t);
    for (auto &x : s) cin >> x;

    const i64 INF = (i64)4e18;
    i64 ans = INF;

    if (a == 1) {
        ans = min(ans, solve_one(n, t, a, b, s, +1));
    } else if (a == n) {
        ans = min(ans, solve_one(n, t, a, b, s, -1));
    } else {
        ans = min(solve_one(n, t, a, b, s, +1),
                  solve_one(n, t, a, b, s, -1));
    }

    cout << ans << '\n';

    return 0;
}