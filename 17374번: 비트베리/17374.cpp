#include <iostream>
#include <algorithm>
#include <vector>

using ll = long long;

void solve() {
    ll p, q, a, b, c, d;
    std::cin >> p >> q >> a >> b >> c >> d;

    ll coins_from_berries = (q / c) * d;
    ll max_bitcoins = 0;

    ll sell_iterations = p / a;
    for (ll i = 0; i <= sell_iterations; ++i) {
        ll current_bits = p - i * a;
        ll current_coins = coins_from_berries + i * b;
        max_bitcoins = std::max(max_bitcoins, std::min(current_bits, current_coins));
    }

    if (b > 0) {
        ll low = 0;
        ll high = coins_from_berries / b;

        while (high - low >= 3) {
            ll m1 = low + (high - low) / 3;
            ll m2 = high - (high - low) / 3;

            ll val1 = std::min(p + m1 * a, coins_from_berries - m1 * b);
            ll val2 = std::min(p + m2 * a, coins_from_berries - m2 * b);

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
                max_bitcoins = std::max(max_bitcoins, std::min(current_bits, current_coins));
            }
        }
    } else {
        max_bitcoins = std::max(max_bitcoins, std::min(p, coins_from_berries));
    }

    std::cout << max_bitcoins << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}