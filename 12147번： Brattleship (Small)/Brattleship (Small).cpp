#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; ++tc) {
        int R, C, W;
        cin >> R >> C >> W;

        int base = (C / W) * R;

        int answer =base;
        if (C % W == 0) {
            answer += (W - 1);
        } else {
            answer += W;
        }

        cout << "Case #" << tc << ": " << answer << "\n";
    }

    return 0;
}