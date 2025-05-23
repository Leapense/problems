#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll M;
    cin >> N >> M;
    ll *A = new ll[N + 1];

    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }

    ll dp0 = 0, dp1 = 1;

    for (int i = 2; i <= N; i++)
    {
        ll new_dp0 = max(dp0, dp1);
        ll new_dp1 = dp0 + 1;
        if (dp1 > 0 && abs(A[i] - A[i - 1]) >= M)
        {
            new_dp1 = max(new_dp1, dp1 + 1);
        }

        dp0 = new_dp0;
        dp1 = new_dp1;
    }

    ll maxKeep = max(dp0, dp1);
    cout << N - maxKeep << "\n";

    delete[] A;
    return 0;
}