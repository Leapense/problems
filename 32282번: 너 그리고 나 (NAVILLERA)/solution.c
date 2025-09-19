#include <stdio.h>
#include <math.h>

int main(void) {
	long long X, Y, c;
	if (scanf("%lld %lld %lld", &X, &Y, &c) != 3) return 0;

	long long d2 = X * X + Y * Y;
	long long c2 = c * c;

	if (d2 == 0) {
		printf("0\n");
		return 0;
	}
	if (d2 == c2) {
		printf("1\n");
		return 0;
	}
	if (d2 < c2) {
		printf("2\n");
		return 0;
	}

	long double r = sqrtl((long double)d2);
	long long ans = (long long)ceill(r / (long double)c - 1e-15L);

	printf("%lld\n", ans);
	return 0;
}
