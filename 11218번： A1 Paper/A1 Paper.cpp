#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

using ll = long long;

int n;
vector<ll> A;

double INF = 1e18;

double F(int k, ll x)
{
    if (k == n)
    {
        return (A[k - 2] >= x ? 0.0 : INF);
    }

    ll available = A[k - 2];
    if (available >= x)
        return 0.0;
    ll deficit = x - available;

    double costNext = F(k + 1, 2 * deficit);

    if (costNext >= INF)
        return INF;

    double tapeCost = deficit * pow(2.0, -double(2 * (k + 1) - 1) / 4.0);
    return costNext + tapeCost;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    A.resize(n - 1);

    for (int i = 0; i < n - 1; i++)
    {
        cin >> A[i];
    }

    double cost = F(2, 2);
    if (cost >= INF)
    {
        cout << "impossible";
        return 0;
    }

    cost += pow(2.0, -3.0 / 4.0);

    cout.precision(11);
    cout << fixed << cost;

    return 0;
}