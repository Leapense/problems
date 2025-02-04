#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);

    int q;
    cin >> q;

    while (q--)
    {
        unsigned long long n, p;
        cin >> n >> p;

        unsigned long long x = n - 1;
        int cnt = __builtin_popcountll(x);
        unsigned long long ans = cnt % p;

        cout << ans << "\n";
    }

    return 0;
}