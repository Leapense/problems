#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<long long> L(N);
        long long S = 0;
        for (int i = 0; i < N; i++)
        {
            cin >> L[i];
            S += L[i];
        }
        // Precompute cumulative distances (clockwise from R1)
        // d[1] = 0, d[2] = L[0], d[3] = L[0]+L[1], ..., d[N] = L[0]+...+L[N-2]
        vector<long long> d(N + 1, 0);
        for (int i = 2; i <= N; i++)
        {
            d[i] = d[i - 1] + L[i - 2];
        }
        long long ans = 1LL << 60;
        for (int i = 0; i < N; i++)
        {
            long long cost = 0;
            // Corridor i connects room R(i+1) and R(i+2) (1-indexed)
            // If one endpoint is R1, extra cost is 0.
            if (i == 0 || i == N - 1)
            {
                cost = S - L[i];
            }
            else
            {
                long long extra1 = min(d[i + 1], S - d[i + 1]); // for room R(i+1)
                long long extra2 = min(d[i + 2], S - d[i + 2]); // for room R(i+2)
                long long extra = min(extra1, extra2);
                cost = (S - L[i]) + extra;
            }
            ans = min(ans, cost);
        }
        cout << ans << "\n";
    }
    return 0;
}
