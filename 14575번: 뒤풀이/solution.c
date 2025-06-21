#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static bool check(long long s_candidate, int n, long long total_t, long long total_l, const int l[], const int r[]) {
    if (s_candidate < 0) {
        return false;
    }

    long long current_max_sum = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s_candidate < l[i]) {
            return false;
        }

        current_max_sum += (r[i] < s_candidate) ? r[i] : s_candidate;
    }

    return total_l <= total_t && total_t <= current_max_sum;
}

int main(void) {
    int n;
    long long t;
    if (scanf("%d %lld", &n, &t) != 2) {
        return 1;
    }

    int* l = (int*)malloc(n * sizeof(int));
    int* r = (int*)malloc(n * sizeof(int));

    if (l == NULL || r == NULL) {
        if (l) free(l);
        if (r) free(r);
        return 1;
    }

    long long total_l = 0;
    long long total_r = 0;
    int max_l = 0;

    for (int i = 0; i < n; ++i) {
        if (scanf("%d %d", &l[i], &r[i]) != 2) {
            free(l);
            free(r);
            return 1;
        }

        total_l += l[i];
        total_r += r[i];
        if (l[i] > max_l) {
            max_l = l[i];
        }
    }

    if (t < total_l || t > total_r) {
        printf("-1\n");
        free(l);
        free(r);
        return 0;
    }

    long long low = max_l;
    long long high = 1000000000;
    long long ans = -1;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (check(mid, n, t, total_l, l, r)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%lld\n", ans);

    free(l);
    free(r);
    return 0;
}