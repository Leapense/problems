#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;

    vector<long long> A(N), T(N);
    long long M = 0;
    for (long long i = 0; i < N; i++)
    {
        cin >> A[i] >> T[i];
        M = max(M, A[i]);
    }

    long long ans = 0;
    for (long long i = 0; i < N; i++)
    {
        long long outward = max(2 * M, T[i] + 2 * M - A[i]);
        long long inbound = max(2 * M, T[i] + A[i]);
        long long candidate = min(outward, inbound);
        ans = max(ans, candidate);
    }
    cout << ans << "\n";

    return 0;
}