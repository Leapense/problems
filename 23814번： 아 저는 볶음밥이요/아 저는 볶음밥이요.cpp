#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll D;
    cin >> D;

    ll N, M, K;
    cin >> N >> M >> K;

    ll total_dumplings = (N + M + K) / D;
    ll N_mod = N % D;
    ll M_mod = M % D;
    ll required_x = (D - N_mod) % D;
    ll required_y = (D - M_mod) % D;
    ll max_z = 0;

    if (required_x <= K)
    {
        ll x = required_x;
        ll y = 0;
        ll z = K - x;

        ll dumplings = (N + x) / D + (M + y) / D + z / D;
        if (dumplings >= total_dumplings)
        {
            max_z = max(max_z, z);
        }
    }

    if (required_y <= K)
    {
        ll x = 0;
        ll y = required_y;
        ll z = K - y;
        ll dumplings = (N + x) / D + (M + y) / D + z / D;
        if (dumplings >= total_dumplings)
        {
            max_z = max(max_z, z);
        }
    }

    if (required_x + required_y <= K)
    {
        ll x = required_x;
        ll y = required_y;
        ll z = K - x - y;

        ll dumplings = (N + x) / D + (M + y) / D + z / D;
        if (dumplings >= total_dumplings)
        {
            max_z = max(max_z, z);
        }
    }

    cout << max_z << endl;

    return 0;
}