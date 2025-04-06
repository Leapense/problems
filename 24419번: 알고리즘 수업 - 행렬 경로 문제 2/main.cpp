#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;

ll modPow(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }

    return res;
}

ll modInverse(ll x, ll mod) {
    return modPow(x, mod - 2, mod);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int maxVal = 2 * n;
    vector<ll> fact(maxVal + 1), invFact(maxVal + 1);
    fact[0] = 1;

    for (int i = 1; i <= maxVal; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    invFact[maxVal] = modInverse(fact[maxVal], MOD);

    for (int i = maxVal; i >= 1; i--) {
        invFact[i - 1] = (invFact[i] * i) % MOD;
    }

    ll code1 = (fact[2 * n] * ((invFact[n] * invFact[n]) % MOD)) % MOD;

    ll code2 = (ll)n * n % MOD;

    cout << code1 << " " << code2 << "\n";
    return 0;
}
