#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        int W, C, F;
        cin >> W >> C >> F;

        vector<int> w(N), c(N), f(N);
        for (int i = 0; i < N; i++) cin >> w[i] >> c[i] >> f[i];
        bool found = false;
        int minimal_k = N + 1;
        for (int k = 1; k <= N && !found; k++) {
            if (k > N) break;
            if (k > 0) {
                int bitmask = (1 << k) - 1;
                while (bitmask < (1 << N)) {
                    int sum_w = 0, sum_c = 0, sum_f = 0;
                    for (int i = 0; i < N; i++) {
                        if (bitmask & (1 << i)) {
                            sum_w += w[i];
                            sum_c += c[i];
                            sum_f += f[i];
                        }
                    }

                    if (sum_w >= W && sum_c >= C && sum_f >= F) {
                        cout << k << "\n";
                        found = true;
                        break;
                    }

                    int smallest = bitmask & -bitmask;
                    int ripple = bitmask + smallest;
                    int new_smallest = bitmask ^ ripple;
                    new_smallest = (new_smallest >> 2) / smallest;
                    bitmask = ripple | new_smallest;
                }
            }
        }
        if (!found) {
            cout << "game over\n";
        }
    }    

    return 0;
}