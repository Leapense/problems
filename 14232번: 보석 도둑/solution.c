#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void solve() {
    long long k;
    if (scanf("%lld", &k) != 1) {
        return;
    }

    size_t capacity = 10;
    size_t count = 0;
    long long* factors = (long long*)malloc(sizeof(long long) * capacity);

    if (factors == NULL) {
        perror("Failed to allocate memory");
        return;
    }

    long long temp_k = k;

    while (temp_k % 2 == 0) {
        if (count == capacity) {
            capacity *= 2;
            long long* new_factors = (long long*)realloc(factors, sizeof(long long) * capacity);
            if (new_factors == NULL) {
                perror("Failed to reallocate memory");
                free(factors);
                return;
            }
            factors = new_factors;
        }

        factors[count++] = 2;
        temp_k /= 2;
    }

    for (long long i = 3; i * i <= temp_k; i += 2) {
        while (temp_k % i == 0) {
            if(count == capacity) {
                capacity *= 2;
                long long* new_factors = (long long*)realloc(factors, sizeof(long long) * capacity);
                if (new_factors == NULL) {
                    perror("Failed to reallocate memory");
                    free(factors);
                    return;
                }

                factors = new_factors;
            }
            factors[count++] = i;
            temp_k /= i;
        }
    }

    if (temp_k > 1) {
        if (count == capacity) {
            long long* new_factors = (long long*)realloc(factors, sizeof(long long) * (capacity + 1));
            if (new_factors == NULL) {
                perror("Failed to reallocate memory");
                free(factors);
                return;
            }
            factors = new_factors;
        }
        factors[count++] = temp_k;
    }

    printf("%zu\n", count);
    for (size_t i = 0; i < count; ++i) {
        printf("%lld%c", factors[i], (i == count - 1 ? '\n' : ' '));
    }

    free(factors);
}

int main() {
    solve();
    return 0;
}