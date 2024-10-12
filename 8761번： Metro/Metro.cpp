#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Z;
    cin >> Z;

    while (Z--) {
        int N;
        cin >> N;

        int s;
        long long min_t = LLONG_MAX;

        for (int i = 1; i <= N; i++) {
            cin >> s;
            if (s == 2) {
                long long t = max((long long)(i-1), (long long)(N - i));
                if (t < min_t) {
                    min_t = t;
                }
            }
        }

        cout << min_t * 2 << "\n";
    }

    return 0;
}