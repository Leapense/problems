#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int Z;
    cin >> Z;

    while(Z--) {
        long long N, K;
        cin >> N >> K;

        long long target = N + 1;
        long long base = K + 1;

        if (base == 1) {
            cout << (N == 0 ? 0 : 1) << "\n";
            continue;
        }

        int ans = 0;
        long long val = 1;

        while (val < target) {
            val *= base;
            ans++;
        }

        cout << ans << "\n";
    }

    return 0;
}