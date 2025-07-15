#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

ll min(ll x, ll y) {
    return x < y ? x : y;
}

ll max(ll x, ll y) {
    return x > y ? x : y;
}

void solve() {
    ll p, q, a, b, c, d;
    scanf("%lld %lld %lld %lld %lld %lld", &p, &q, &a, &b, &c, &d);

    ll coins_from_berries = (q / c) * d;
    ll max_bitcoins = 0;

    ll sell_iterations = p / a;
    for (ll i = 0; i <= sell_iterations; ++i) {
        ll current_bits = p - i * a;
        ll current_coins = coins_from_berries + i * b;
        max_bitcoins = max(max_bitcoins, min(current_bits, current_coins));
    }

    if (b > 0) {
        ll low = 0;
        ll high = coins_from_berries / b;

        while (high - low >= 3) {
            ll m1 = low + (high - low) / 3;
            ll m2 = high - (high - low) / 3;

            ll val1 = min(p + m1 * a, coins_from_berries - m1 * b);
            ll val2 = min(p + m2 * a, coins_from_berries - m2 * b);

            if (val1 < val2) {
                low = m1;
            } else {
                high = m2;
            }
        }

        for (ll j = low; j <= high; ++j) {
            ll current_bits = p + j * a;
            ll current_coins = coins_from_berries - j * b;
            if (current_coins >= 0) {
                max_bitcoins = max(max_bitcoins, min(current_bits, current_coins));
            }
        }
    } else {
        max_bitcoins = max(max_bitcoins, min(p, coins_from_berries));
    }

    printf("%lld\n", max_bitcoins);
}

int main(void)
{
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}