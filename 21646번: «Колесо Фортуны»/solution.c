#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long long max(long long a, long long b) {
	return a > b ? a : b;
}

int main(void) {
	int n;
	scanf("%d", &n);

	int* sectors = (int*)malloc(n * sizeof(int));
	if (sectors == NULL) {
		return 1;
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &sectors[i]);
	}

	long long a, b, k;
	scanf("%lld %lld %lld", &a, &b, &k);
	
	long long max_prize = 0;
	if (a <= k) max_prize = sectors[0];

	long long m_min = (a > k) ? (a - 1) / k : 0;
	long long m_max = (b > k) ? (b - 1) / k : 0;
	
	if (m_min == 0 && a <= k) {
		m_min = 1;
	}

	if (m_min > 0 && m_min <= m_max) {
		if (m_max - m_min >= n - 1) {
			for (int i = 0; i < n; ++i) {
				max_prize = max(max_prize, sectors[i]);
			}
		} else {
			for (long long m = m_min; m <= m_max; ++m) {
				long long cw_idx = m % n;
				long long ccw_idx = (n - (m % n)) % n;
				max_prize = max(max_prize, sectors[cw_idx]);
				max_prize = max(max_prize, sectors[ccw_idx]);
			}
		}
	}

	if (max_prize == 0 && a <= k) {
		max_prize = sectors[0];
	} else if (max_prize == 0 && n > 0) {
		max_prize = sectors[0];
	}

	printf("%lld\n", max_prize);
	free(sectors);

	return 0;
}
