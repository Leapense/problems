#include <iostream>
#include <cmath>
#include <cstdint>

int main() {
	long long X, Y, c;
	if (!(std::cin >> X >> Y >> c)) return 0;

	long long d2 = X * X + Y * Y;
	long long c2 = c * c;

	if (d2 == 0) {
		std::cout << 0 << '\n';
		return 0;
	}
	if (d2 == c2) {
		std::cout << 1 << '\n';
		return 0;
	}
	if (d2 < c2) {
		std::cout << 2 << '\n';
		return 0;
	}

	long double r = std::sqrt((long double)d2);
	long long ans = (long long)std::ceil(r / (long double)c - 1e-15L);

	std::cout << ans << '\n';
	return 0;
}
