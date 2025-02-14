#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long X_lo, X_hi, Y_lo, Y_hi, Z_lo, Z_hi;
    cin >> X_lo >> X_hi >> Y_lo >> Y_hi >> Z_lo >> Z_hi;

    long long x_lo, x_hi, y_lo, y_hi, z_lo, z_hi;
    cin >> x_lo >> x_hi >> y_lo >> y_hi >> z_lo >> z_hi;

    if (min(X_hi, x_hi) - max(X_lo, x_lo) <= 0 || min(Y_hi, y_hi) - max(Y_lo, y_lo) <= 0)
    {
        cout << -1;
        return 0;
    }

    long long t_candidate = max(0LL, Z_lo - z_hi + 1);
    if (t_candidate < Z_hi - z_lo)
        cout << t_candidate;
    else
        cout << -1;

    return 0;
}