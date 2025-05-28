#include <bits/stdc++.h>
using namespace std;
static const int INF = 0x3f3f3f3f;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string S, T;
    cin >> S >> T;

    vector<int> D(n), C(n - 1);
    for (int i = 0; i < n; ++i) {
        D[i] = (S[i] - '0') ^ (T[i] - '0');
    }
    for (int i = 0; i < n - 1; ++i) {
        C[i] = D[i] ^ D[i + 1];
    }

    array<array<int, 2>, 2> dp_cur, dp_nxt;
    for (auto &row : dp_cur) row.fill(INF);

    dp_cur[0][0] = 0;
    dp_cur[1][1] = 1;

    for (int j = 1; j < n; ++j) {
        for (auto &row : dp_nxt) row.fill(INF);
        for (int b1 = 0; b1 < 2; ++b1) {
            for (int p = 0; p < 2; ++p) {
                int base = dp_cur[b1][p];
                if (base >= INF) continue;
                for (int b2 = 0; b2 < 2; ++b2) {
                    int p2 = p ^ b2;
                    int cost = base + b2 + abs(b2 - C[j - 1]);
                    dp_nxt[b2][p2] = min(dp_nxt[b2][p2], cost);
                }
            }
        }

        dp_cur.swap(dp_nxt);
    }

    int answer = INF;
    for (int b = 0; b < 2; ++b) {
        for (int p = 0; p < 2; ++p) {
            int val = dp_cur[b][p];
            if (val < INF) {
                val += (p != D[n - 1]) ? 1 : 0;
                answer = min(answer, val);
            }
        }
    }

    cout << answer << "\n";
    return EXIT_SUCCESS;
}