#include <bits/stdc++.h>

using namespace std;

static constexpr int kNoApple = -1;

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int rowCnt {};
    int colCnt {};
    if (!(cin >> rowCnt >> colCnt)) {
        return 0;
    }

    vector<int> left(rowCnt, colCnt);         // L[r]
    vector<int> right(rowCnt, kNoApple);      // R[r]

    string line;
    for (int r = 0; r < rowCnt; ++r) {
        cin >> line;
        for (int c = 0; c < colCnt; ++c) {
            if (line[c] == 'J') {
                left[r]  = min(left[r], c);
                right[r] = max(right[r], c);
            }
        }
    }

    int topRow {rowCnt};                      // yet unknown
    for (int r = 0; r < rowCnt; ++r) {
        if (right[r] != kNoApple) {
            topRow = r;
            break;
        }
    }
    if (topRow == rowCnt) {
        cout << 0 << '\n';
        return 0;                             // no apples
    }

    long long ans   {0};
    int        cur  {0};                      // column
    int        dir  {+1};                     // +1: →, -1: ←

    for (int r = rowCnt - 1; ; --r, dir = -dir) {
        // 1) collect apples on current row
        if (right[r] != kNoApple) {
            if (dir == +1) {
                if (cur < left[r]) {
                    ans += left[r] - cur;
                    cur  = left[r];
                }
                ans += right[r] - cur;
                cur  = right[r];
            } else {                          // dir == -1
                if (cur > right[r]) {
                    ans += cur - right[r];
                    cur  = right[r];
                }
                ans += cur - left[r];
                cur  = left[r];
            }
        }

        // 2) finished?
        if (r == topRow) {
            break;
        }

        // 3) meet constraint of the next row with apples (if any)
        const int next = r - 1;
        if (right[next] != kNoApple) {
            if (dir == +1) {                  // next faces ←
                const int need = right[next];
                if (cur < need) {
                    ans += need - cur;
                    cur  = need;
                }
            } else {                          // dir == -1, next faces →
                const int need = left[next];
                if (cur > need) {
                    ans += cur - need;
                    cur  = need;
                }
            }
        }

        // 4) climb up
        ++ans;                                // one B press
    }

    cout << ans << '\n';
    return 0;
}