#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000009LL

static inline long long add_mod(long long a, long long b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
    return a;
}

int main(void) {
    int T = 0;
    if (scanf("%d", &T) != 1) {
        return 1;
    }

    int *queries = malloc(sizeof(int) * T);
    int max_n = 0;
    for (int i = 0; i < T; i++) {
        if (scanf("%d", &queries[i]) != 1) {
            free(queries);
            return 1;
        }
        if (queries[i] > max_n) {
            max_n = queries[i];
        }
    }

    long long *odd = calloc((size_t) (max_n + 4), sizeof(long long));
    long long *even = calloc((size_t) (max_n + 4), sizeof(long long));
    if (!odd || !even) {
        free(queries);
        free(odd);
        free(even);
        return 1;
    }

    even[0] = 1;
    for (int i = 1; i <= max_n; i++) {
        long long new_odd = 0;
        long long new_even = 0;

        if (i - 1 >= 0) {
            new_odd = add_mod(new_odd, even[i - 1]);
            new_even = add_mod(new_even, odd[i - 1]);
        }
        if (i - 2 >= 0) {
            new_odd = add_mod(new_odd, even[i - 2]);
            new_even = add_mod(new_even, odd[i - 2]);
        }
        if (i - 3 >= 0) {
            new_odd = add_mod(new_odd, even[i - 3]);
            new_even = add_mod(new_even, odd[i - 3]);
        }

        odd[i] = new_odd;
        even[i] = new_even;
    }

    for (int i = 0; i < T; i++) {
        printf("%lld %lld\n", odd[queries[i]], even[queries[i]]);
    }

    free(queries);
    free(odd);
    free(even);
    return 0;
}