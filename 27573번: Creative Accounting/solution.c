#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void)
{
    int n, l, h;
    if (scanf("%d %d %d", &n, &l, &h) != 3) return 0;

    long long *S = (long long*)malloc((n + 1) * sizeof(long long));
    if (!S) return 0;

    S[0] = 0;
    for (int i = 0; i < n; ++i) {
        long long p;
        scanf("%lld", &p);
        S[i + 1] = S[i] + p;
    }

    int global_min = INT_MAX;
    int global_max = INT_MIN;

    unsigned char *D = NULL;
    int Dcap = 0;
    for (int k = l; k <= h; ++k) {
        int m = n - k + 1;
        if (m < 0) m = 0;
        if (m > Dcap) {
            free(D);
            D = (unsigned char*)malloc((size_t)m * sizeof(unsigned char));
            if (!D) {
                free(S);
                return 0;
            }
            Dcap = m;
        }

        for (int x = 0; x < m; ++x) {
            long long diff = S[x + k] - S[x];
            D[x] = (unsigned char)(diff > 0);
        }

        int k_min = INT_MAX, k_max = INT_MIN;

        for (int r = 0; r < k; ++r) {
            int sum_stride = 0;
            for (int x = r; x <= n - k; x += k) {
                sum_stride += D[x];
            }

            int cnt = 0;

            if (r <= n && S[r] > 0) ++cnt;
            cnt += sum_stride;

            long long L = r;
            if (n - r >= 0) L = r + (long long)((n - r) / k) * k;
            if (L < n) {
                if (S[n] - S[(int)L] > 0) ++cnt;
            }

            if (cnt < k_min) k_min = cnt;
            if (cnt > k_max) k_max = cnt;
        }

        if (k_min < global_min) global_min = k_min;
        if (k_max > global_max) global_max = k_max;
    }

    printf("%d %d\n", global_min, global_max);

    free(D);
    free(S);
    return 0;
}