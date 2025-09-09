#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int limit = 2 * n;
    unsigned char *is_prime = (unsigned char*)malloc((size_t)(limit + 1) * sizeof(unsigned char));
    if (!is_prime) return 0;

    memset(is_prime, 1, (size_t)(limit + 1));
    
    if (limit >= 0) is_prime[0] = 0;
    if (limit >= 1) is_prime[1] = 0;
    for (int p = 2; 1LL * p * p <= limit; ++p) {
        if (is_prime[p]) {
            long long start = 1LL * p * p;
            for (long long q = start; q <= limit; q += p) {
                is_prime[(int)q] = 0;
            }
        }
    }
    int L = n + 1, R = 2 * n - 1;
    int best_l = -1, best_r = -1, best_len = -1;

    int cur_l = -1, cur_len = 0;

    for (int x = L; x <= R; ++x) {
        int composite = (x > 1) && !is_prime[x];
        if (composite) {
            if (cur_len == 0) cur_l = x;
            ++cur_len;
        } else {
            if (cur_len > 0) {
                int cur_r = x - 1;
                if (cur_len > best_len || (cur_len == best_len && cur_l < best_l)) {
                    best_len = cur_len;
                    best_l = cur_l;
                    best_r = cur_r;
                }

                cur_len = 0;
            }
        }
    }

    if (cur_len > 0) {
        int cur_r = R;
        if (cur_len > best_len || (cur_len == best_len && cur_l < best_l)) {
            best_len = cur_len;
            best_l = cur_l;
            best_r = cur_r;
        }
    }
    printf("%d %d\n", best_l, best_r);
    free(is_prime);
    return 0;
}