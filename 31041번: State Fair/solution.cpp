#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    if (!(cin >> tc)) return 0;
    cout.setf(ios::fixed);
    cout << setprecision(3);
    for (int _ = 0; _ < tc; ++_) {
        double r, c;
        cin >> r >> c;
        double s = (c * (c * c + 4 * r * r)) / (2 * (c * c - 4 * r * r));
        cout << s + 1e-12 << "\n";
    }

    return 0;
}