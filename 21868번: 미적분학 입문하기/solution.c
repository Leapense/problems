#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	long long eps_numerator, eps_denominator;
	scanf("%lld %lld", &eps_numerator, &eps_denominator);

	long long a, b;
	scanf("%lld %lld", &a, &b);

	long long x0;
	scanf("%lld", &x0);

	long long limit_l = a * x0 + b;
	printf("%lld\n", limit_l);

	if (a == 0) printf("0 0\n");
	else {
		long long delta_numerator = eps_numerator;
		long long delta_denominator = llabs(a) * eps_denominator;
		printf("%lld %lld\n", delta_numerator, delta_denominator);
	}

	return 0;
}
