#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    int T;
    if (scanf("%d", &T) != 1) {
        return 0;
    }

    int *queries = (int*)malloc(T * sizeof(int));
    int maxN = 0;
    for (int i = 0; i < T; i++) {
        scanf("%d", &queries[i]);
        if (queries[i] > maxN) {
            maxN = queries[i];
        }
    }
    int limit = 2 * maxN;
    bool *is_prime = (bool*)malloc((limit + 1) * sizeof(bool));
    for (int i = 0; i <= limit; i++) {
        is_prime[i] = true;
    }

    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 2; i * i <= limit; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (int i = 0; i < T; i++) {
        int N = queries[i];
        int target = 2 * N;
        for (int p = 2; p <= target / 2; p++) {
            if (is_prime[p] && is_prime[target - p]) {
                printf("%d %d\n", p, target - p);
                break;
            }
        }
    }

    free(is_prime);
    free(queries);
    return 0;
}