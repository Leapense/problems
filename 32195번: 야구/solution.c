#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

static int cmp_ull(const void* a, const void* b) {
	unsigned long long x = *(const unsigned long long*)a;
	unsigned long long y = *(const unsigned long long*)b;
	if (x < y) return -1;
	if (x > y) return 1;
	return 0;
}

static int upper_bound_ull(const unsigned long long* arr, int n, unsigned long long key) {
	int lo = 0, hi = n;
	while (lo < hi) {
		int mid = lo + ((hi - lo) >> 1);
		if (arr[mid] <= key) lo = mid + 1;
		else hi = mid;
	}
	return lo;
}

int main(void) {
	int N;
	if (scanf("%d", &N) != 1) return 0;

	unsigned long long* A = (unsigned long long*)malloc((size_t)N * sizeof(unsigned long long));
	int K = 0;

	long long x, y;
	for (int i = 0; i < N; ++i) {
		scanf("%lld %lld", &x, &y);
		if (y >= llabs(x)) {
			unsigned long long s = (unsigned long long)(x * x) + (unsigned long long)(y * y);
			A[K++] = s;
		}
	}
	qsort(A, (size_t)K, sizeof(unsigned long long), cmp_ull);
	const int foul = N - K;

	int Q;
	scanf("%d", &Q);
	for (int i = 0; i < Q; ++i) {
		long long R;
		scanf("%lld", &R);
		unsigned long long t = (unsigned long long)R * (unsigned long long)R;

		int infield = upper_bound_ull(A, K, t);
		int homerun = K - infield;
		printf("%d %d %d\n", foul, infield, homerun);
	}

	free(A);
	return 0;
}
