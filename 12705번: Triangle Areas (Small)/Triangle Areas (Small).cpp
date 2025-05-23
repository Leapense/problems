#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        ll N, M, A;
        cin >> N >> M >> A;
        cout << "Case #" << t << ": ";

        if (A > N * M)
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        ll a = min(N, A);
        if (A % a == 0 && (A / a) <= M)
        {
            cout << 0 << " " << 0 << " " << a << " " << 0 << " " << 0 << " " << A / a << "\n";
            continue;
        }

        ll y3 = (A + a - 1) / a;
        ll x3 = a * y3 - A;

        assert(a <= N && 1 <= M && x3 >= 0 && y3 <= M);
        cout << 0 << " " << 0 << " " << a << " " << 1 << " " << x3 << " " << y3 << "\n";
    }

    return 0;
}