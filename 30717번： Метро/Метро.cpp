#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll p, k;
    cin >> n >> p >> k;

    vector<ll> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll base_rides = 0;
    vector<ll> deficiencies;

    for (int i = 0; i < n; i++)
    {
        base_rides += a[i] / k;
        ll r = a[i] % k;
        if (r > 0)
        {
            deficiencies.push_back(k - r);
        }
    }

    sort(deficiencies.begin(), deficiencies.end());

    ll extra_rides = 0;

    for (ll cost : deficiencies)
    {
        if (p >= cost)
        {
            p -= cost;
            extra_rides++;
        }
        else
        {
            break;
        }
    }

    extra_rides += p / k;

    cout << base_rides + extra_rides << "\n";

    return 0;
}