#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;

    while(T--)
    {
        ll A, B;
        cin >> A >> B;
        ll max_lcm = 0;
        ll start = max(1LL, B - 100);
        for (ll x = B; x >= start; x--)
        {
            ll g = gcd(A, x);
            ll lcm = (A / g) * x;

            if (lcm > max_lcm) {
                max_lcm = lcm;
            }

            if (g == 1) {
                break;
            }
        }

        cout << max_lcm << "\n";
    }
}