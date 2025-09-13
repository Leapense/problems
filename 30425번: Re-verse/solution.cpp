#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    string S;
    cin >> S;

    int p = N;
    for (int d = 1; d < N; ++d) {
        bool ok = true;
        for (int i = d; i < N; ++i) {
            if (S[i] != S[i - d]) { ok = false; break; }
        }
        if (ok) { p = d; break; }
    }
    int ans = 1 + (N - 1) / p;
    cout << ans << '\n';
    return 0;
}