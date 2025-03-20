#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    getline(cin, s);
    vector<ll> freq(26, 0);
    ll tot = 0;
    for (auto c : s)
        if (isalpha(c))
        {
            freq[toupper(c) - 'A']++;
            tot++;
        }
    vector<ll> F;
    for (auto f : freq)
        if (f)
            F.push_back(f);
    sort(F.begin(), F.end(), greater<ll>());
    int m = F.size();
    // m <= 26. We will assign codes using lengths 1..4.
    ll best = LLONG_MAX;
    for (int r1 = 0; r1 <= min(m, 2); r1++)
    {
        for (int r2 = 0; r2 <= min(m - r1, 4); r2++)
        {
            for (int r3 = 0; r3 <= min(m - r1 - r2, 8); r3++)
            {
                int r4 = m - r1 - r2 - r3;
                if (r4 < 0 || r4 > 16)
                    continue;
                vector<int> B;
                for (int j = 0; j < r1; j++)
                    B.push_back(2 * 1 - 1 + 2 * j);
                for (int j = 0; j < r2; j++)
                    B.push_back(2 * 2 - 1 + 2 * j);
                for (int j = 0; j < r3; j++)
                    B.push_back(2 * 3 - 1 + 2 * j);
                for (int j = 0; j < r4; j++)
                    B.push_back(2 * 4 - 1 + 2 * j);
                sort(B.begin(), B.end());
                if (B.size() != (size_t)m)
                    continue;
                ll sum = 0;
                for (int i = 0; i < m; i++)
                    sum += F[i] * B[i];
                best = min(best, sum);
            }
        }
    }
    cout << best + (tot - 1) * 3;
    return 0;
}
