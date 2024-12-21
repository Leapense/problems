#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;
    while (Q--) {
        long long n, p;
        cin >> n >> p;

        if (n == 1) {
            cout << 0 << '\n';
            continue;
        }

        long long c = __builtin_popcountll(n - 1);

        long long ans = c % p;
        cout << ans << "\n";
    }

    return 0;
}