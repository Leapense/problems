#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> processQueries(
    int N,
    const vector<ll> &arr,
    const vector<tuple<int, ll, ll>> &queries)
{
    vector<ll> pref(N + 1, 0);
    for (int i = 0; i < N; ++i)
        pref[i + 1] = pref[i] + arr[i];
    const ll total = pref[N];

    int offset = 0;
    vector<ll> output;

    for (auto [type, x, y] : queries)
    {
        if (type == 1)
        {
            int k = static_cast<int>(x % N);
            offset = (offset - k + N) % N;
        }
        else if (type == 2)
        {
            int k = static_cast<int>(x % N);
            offset = (offset + k) % N;
        }
        else
        {
            int a = static_cast<int>(x) - 1;
            int b = static_cast<int>(y) - 1;

            int s = (offset + a) % N;
            int e = (offset + b) % N;
            ll ans;

            if (s <= e)
            {
                ans = pref[e + 1] - pref[s];
            }
            else
            {
                ans = total - (pref[s] - pref[e + 1]);
            }

            output.push_back(ans);
        }
    }

    return output;
}

#ifndef UNIT_TEST
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    if (!(cin >> N >> Q))
        return 0;

    vector<ll> arr(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    vector<tuple<int, ll, ll>> queries;
    queries.reserve(Q);

    for (int i = 0; i < Q; ++i)
    {
        int t;
        cin >> t;
        if (t == 1 || t == 2)
        {
            ll k;
            cin >> k;
            queries.emplace_back(t, k, 0);
        }
        else
        {
            ll a, b;
            cin >> a >> b;
            queries.emplace_back(t, a, b);
        }
    }

    auto answers = processQueries(N, arr, queries);
    for (ll v : answers)
        cout << v << "\n";
    return 0;
}
#endif