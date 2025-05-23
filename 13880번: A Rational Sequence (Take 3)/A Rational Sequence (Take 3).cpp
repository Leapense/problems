#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int P;
    cin >> P;

    while (P--) {
        long long K, N;
        cin >> K >> N;

        long long p = 1, q = 1;
        if (N > 1) {
            int highest = 31 - __builtin_clz(N);
            for (int i = highest - 1; i >= 0; i--) {
                if ((N >> i) & 1) {
                    p += q;
                } else {
                    q += p;
                }
            }
        }
        cout << K << " " << p << "/" << q << "\n";
    }

    return 0;
}