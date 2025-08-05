#include <iostream>
#include <cmath>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	long long eps_numerator, eps_denominator;
	std::cin >> eps_numerator >> eps_denominator;

	long long a, b;
	std::cin >> a >> b;

	long long x0;
	std::cin >> x0;

	long long limit_l = a * x0 + b;
	std::cout << limit_l << "\n";

	if (a == 0) std::cout << "0 0\n";
	else {
		long long delta_numerator = eps_numerator;
		long long delta_denominator = std::abs(a) * eps_denominator;
		std::cout << delta_numerator << " " << delta_denominator << "\n";
	}
	return 0;
}
