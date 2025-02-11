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
    ll M;
    cin >> N >> M;

    vector<ll> V(N);
    ll total = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> V[i];
        total += V[i];
    }

    ll req = (total + 1) / 2;
    sort(V.begin(), V.end(), greater<ll>());

    ll sum = 0;
    int k = 0;
    for (int i = 0; i < N; i++)
    {
        sum += V[i];
        k++;
        if (sum >= req)
            break;
    }

    ll ans = M / (k + 1);
    cout << ans << "\n";

    return 0;
}