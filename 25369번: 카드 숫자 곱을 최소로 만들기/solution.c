#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    const int MIN_DIGIT = 1;
    const int MAX_DIGIT = 9;

    long long target = 1;
    for (int i = 0; i < n; i++) {
        int x;
        if (scanf("%d", &x) != 1) {
            return 0;
        }
        target *= x;
    }

    long long* maxDigitPowers = (long long*)malloc((size_t)(n + 1) * sizeof(long long));
    if (maxDigitPowers == NULL) {
        return 0;
    }
    maxDigitPowers[0] = 1;
    for (int i = 1; i <= n; i++) {
        maxDigitPowers[i] = maxDigitPowers[i - 1] * MAX_DIGIT;
    }

    if (maxDigitPowers[n] <= target) {
        printf("-1\n");
        free(maxDigitPowers);
        return 0;
    }

    int* result = (int*)malloc((size_t)n * sizeof(int));
    if (result == NULL) {
        free(maxDigitPowers);
        return 0;
    }

    long long currentProduct = 1;
    int prevDigit = MIN_DIGIT;

    for (int pos = 0; pos < n; pos++) {
        int remaining = n - pos - 1;
        for (int d = prevDigit; d <= MAX_DIGIT; d++) {
            long long maxPossible = currentProduct * d * maxDigitPowers[remaining];
            if (maxPossible > target) {
                result[pos] = d;
                currentProduct *= d;
                prevDigit = d;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", result[i]);
    }
    printf("\n");
    free(maxDigitPowers);
    free(result);
    return 0;
}