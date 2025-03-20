#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
using ll = long long;

const int MOD = 210;
string s;
int n;
unordered_map<ll, ll> memo[20];

ll solve(int pos, int current)
{
    long long key = ((long long)pos << 32) | (unsigned int)(current + 1000);
    if (memo[pos].count(key))
        return memo[pos][key];
    if (pos == n)
    {
        int val = (current % MOD + MOD) % MOD;
        ll ans = ((val % 2 == 0) || (val % 3 == 0) || (val % 5 == 0) || (val % 7 == 0)) ? 1LL : 0LL;
        return memo[pos][key] = ans;
    }

    ll ways = 0;
    long long num = 0;

    for (int i = pos; i < n; i++)
    {
        num = num * 10 + (s[i] - '0');
        num %= MOD;
        int numVal = num;
        if (pos == 0)
        {
            ways += solve(i + 1, numVal);
        }
        else
        {
            int plus = (current + numVal) % MOD;
            if (plus < 0)
                plus += MOD;
            ways += solve(i + 1, plus);
            int minus = (current - numVal) % MOD;
            if (minus < 0)
                minus += MOD;
            ways += solve(i + 1, minus);
        }
    }

    return memo[pos][key] = ways;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        cin >> s;
        n = s.size();

        for (int i = 0; i <= n; i++)
        {
            memo[i].clear();
        }

        ll ans = solve(0, 0);

        cout << "Case #" << tc << ": " << ans << "\n";
    }

    return 0;
}