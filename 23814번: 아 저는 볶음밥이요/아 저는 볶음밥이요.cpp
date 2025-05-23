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
    ll A = N / D;
    ll remN = N % D;
    ll B = M / D;
    ll remM = M % D;
    ll x_req_N = remN > 0 ? D - remN : 0;
    ll y_req_M = remM > 0 ? D - remM : 0;
    ll max_dumplings = -1;
    ll max_z = 0;

    // Case 1: Assign nothing
    ll z1 = K;
    ll dumplings1 = A + B + (z1 / D);
    if (dumplings1 > max_dumplings)
    {
        max_dumplings = dumplings1;
        max_z = z1;
    }
    else if (dumplings1 == max_dumplings)
    {
        max_z = max(max_z, z1);
    }

    // Case 2: Assign x_req_N to x
    if (x_req_N <= K)
    {
        ll x2 = x_req_N;
        ll z2 = K - x2;
        ll dumplings2 = A + B + 1 + (z2 / D);
        if (dumplings2 > max_dumplings)
        {
            max_dumplings = dumplings2;
            max_z = z2;
        }
        else if (dumplings2 == max_dumplings)
        {
            max_z = max(max_z, z2);
        }
    }

    // Case 3: Assign y_req_M to y
    if (y_req_M <= K)
    {
        ll y3 = y_req_M;
        ll z3 = K - y3;
        ll dumplings3 = A + B + 1 + (z3 / D);
        if (dumplings3 > max_dumplings)
        {
            max_dumplings = dumplings3;
            max_z = z3;
        }
        else if (dumplings3 == max_dumplings)
        {
            max_z = max(max_z, z3);
        }
    }

    // Case 4: Assign both x_req_N to x and y_req_M to y
    if (x_req_N + y_req_M <= K)
    {
        ll x4 = x_req_N;
        ll y4 = y_req_M;
        ll z4 = K - x4 - y4;
        ll dumplings4 = A + B + 2 + (z4 / D);
        if (dumplings4 > max_dumplings)
        {
            max_dumplings = dumplings4;
            max_z = z4;
        }
        else if (dumplings4 == max_dumplings)
        {
            max_z = max(max_z, z4);
        }
    }

    cout << max_z;
}
