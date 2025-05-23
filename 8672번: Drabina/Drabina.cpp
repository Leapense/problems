/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 8672                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: cjhool <boj.kr/u/cjhool>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/8672                           #+#        #+#      #+#    */
/*   Solved: 2025/02/27 18:52:49 by cjhool        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
using namespace std;
using ll = long long;

pair<ll, ll> fastFib(ll n, ll mod)
{
    if (n == 0)
        return {0, 1};
    auto [a, b] = fastFib(n >> 1, mod);
    ll c = (a * ((b << 1) - a + mod)) % mod;
    ll d = (a * a + b * b) % mod;
    if (n & 1)
        return {d, (c + d) % mod};
    else
        return {c, d};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int z;
    cin >> z;

    while (z--)
    {
        int s, p;
        cin >> s >> p;
        ll mod = 1LL << p;
        auto res = fastFib(s + 1, mod);
        cout << res.first % mod << "\n";
    }
    return 0;
}