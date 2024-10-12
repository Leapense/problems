#include <iostream>

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, a, b, c;
    int ans;

    std::cin >> n >> a >> b >> c;


    if (n > 1) {
        if (a < c || b < c) ans = (n - 1) * std::min(a, b);
        else ans = std::min(a, b) + (n - 2) * c;
    } else if (n == 1) {
        ans = 0;
    }

    std::cout << ans / 100 << ' ' << ans % 100 << std::endl;

    return 0;
}