#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

pair<ll, ll> addFraction(pair<ll, ll> f, pair<ll, ll> g)
{
    ll num = f.first * g.second + g.first * f.second;
    ll den = f.second * g.second;
    ll d = gcd(num, den);
    return {num / d, den / d};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;

    vector<int> cake(N);
    for (auto &v : cake)
        cin >> v;

    int ans = 0;

    for (int mask = 1; mask < (1 << N); mask++)
    {
        pair<ll, ll> sum = {0, 1};
        for (int i = 0; i < N; i++)
        {
            if (mask & (1 << i))
            {
                pair<ll, ll> piece = {1, cake[i]};
                sum = addFraction(sum, piece);
            }
        }

        if (100 * sum.first >= 99 * sum.second && 100 * sum.first <= 101 * sum.second)
            ans++;
    }

    cout << ans;
    return 0;
}