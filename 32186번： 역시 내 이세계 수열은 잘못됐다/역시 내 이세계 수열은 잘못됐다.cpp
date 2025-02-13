#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll K;
    cin >> N >> K;

    vector<ll> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    ll ans = 0;

    for (int i = 0; i < N / 2; i++)
    {
        ll x = min(A[i], A[N - i - 1]);
        ll y = max(A[i], A[N - i - 1]);
        ll d = y - x;

        if (d == 0)
            continue;

        ll q = d / K;
        ll r = d % K;

        if (r == 0)
        {
            ans += q;
        }
        else
        {
            ll cost1 = q + r;
            ll cost2 = q + (K - r + 1);

            ans += min(cost1, cost2);
        }
    }
    cout << ans << "\n";

    return 0;
}