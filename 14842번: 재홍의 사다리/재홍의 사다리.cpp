#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int W, H, N;
    cin >> W >> H >> N;

    if (N % 2 == 0) cout << fixed << setprecision(6) << (double)(N - 2) / 4 * (2 * H) << "\n";
    else cout << fixed << setprecision(6) << (double)(N-1) * (N-1) / (4*N) * (2 * H) << "\n";

    return 0;
}