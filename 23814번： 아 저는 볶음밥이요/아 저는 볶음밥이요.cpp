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
    ll Q = (N + M + K) / D;
    ll N_mod = N % D;
    ll M_mod = M % D;
    ll required_x = (D - N_mod) % D;
    ll required_y = (D - M_mod) % D;
    ll max_z = 0;
    // Case 1: Assign required_x to x
    if (required_x <= K)
    {
        ll x = required_x;
        ll y = 0;
        ll z = K - x;
        ll dumplings = (N + x) / D + (M + y) / D + z / D;
        if (dumplings >= Q)
        {
            max_z = max(max_z, z);
        }
    }
    // Case 2: Assign required_y to y
    if (required_y <= K)
    {
        ll x = 0;
        ll y = required_y;
        ll z = K - y;
        ll dumplings = (N + x) / D + (M + y) / D + z / D;
        if (dumplings >= Q)
        {
            max_z = max(max_z, z);
        }
    }
    // Case 3: Assign both required_x and required_y
    if (required_x + required_y <= K)
    {
        ll x = required_x;
        ll y = required_y;
        ll z = K - x - y;
        ll dumplings = (N + x) / D + (M + y) / D + z / D;
        if (dumplings >= Q)
        {
            max_z = max(max_z, z);
        }
    }
    // Additional Case 4: Assign as much as possible to z
    ll z_possible = (K / D) * D;
    ll remaining = K - z_possible;
    ll dumplings_case4 = (N + remaining) / D + (M) / D + z_possible / D;
    if (dumplings_case4 >= Q)
    {
        max_z = max(max_z, z_possible);
    }
    dumplings_case4 = (N) / D + (M + remaining) / D + z_possible / D;
    if (dumplings_case4 >= Q)
    {
        max_z = max(max_z, z_possible);
    }
    // Additional Case 5: Assign both required_x and required_y partially
    // This ensures that all possible combinations are considered
    // Iterate over possible assignments to maximize z
    // Since D can be large, limit iterations to a small number
    for (ll add_x = 0; add_x < D && add_x <= K; add_x++)
    {
        ll add_y = max(0LL, (Q * D - (N + add_x)) - M);
        if (add_y < 0)
            add_y = 0;
        if (add_x + add_y > K)
            continue;
        ll z = K - add_x - add_y;
        ll dumplings = (N + add_x) / D + (M + add_y) / D + z / D;
        if (dumplings >= Q)
        {
            max_z = max(max_z, z);
        }
    }
    for (ll add_y = 0; add_y < D && add_y <= K; add_y++)
    {
        ll add_x = max(0LL, (Q * D - (M + add_y)) - N);
        if (add_x < 0)
            add_x = 0;
        if (add_x + add_y > K)
            continue;
        ll z = K - add_x - add_y;
        ll dumplings = (N + add_x) / D + (M + add_y) / D + z / D;
        if (dumplings >= Q)
        {
            max_z = max(max_z, z);
        }
    }
    cout << max_z;
}