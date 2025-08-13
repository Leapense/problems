#include <stdio.h>
#include <stdlib.h>

static char* build_min_number_c(long long sum, int forbidden_digit) {
    const int digit_min = 0;
    const int digit_max = 9;
    const int max_digit = forbidden_digit == 9 ? 8 : 9;
    const int min_other = forbidden_digit == 0 ? 1 : 0;

    long long length = (sum + max_digit - 1) / max_digit;
    for (;; ++length) {
        char* result = (char*)malloc((size_t)length + 1);
        if (result == NULL) return NULL;

        long long remaining = sum;
        int ok = 1;

        for (long long i = 0; i < length; ++i) {
            int start_digit = i == 0 ? 1 : digit_min;
            int placed = 0;

            for (int d = start_digit; d <= digit_max; ++d) {
                if (d == forbidden_digit) continue;
                long long rem = remaining - d;
                if (rem < 0) break;
                long long left = length - 1 - i;
                long long min_rem = left * (long long)min_other;
                long long max_rem = left * (long long)max_digit;
                if (rem >= min_rem && rem <= max_rem) {
                    result[i] = (char)('0' + d);
                    remaining = rem;
                    placed = 1;
                    break;
                }
            }

            if (!placed) {
                ok = 0;
                break;
            }
        }

        if (ok && remaining == 0) {
            result[length] = '\0';
            return result;
        }

        free(result);
        if (length > sum) {
            return NULL;
        }
    }
}

int main(void) {
    long long N;
    int d;
    if (scanf("%lld %d", &N, &d) != 2) {
        return 0;
    }
    char* ans = build_min_number_c(N, d);
    if (ans == NULL) {
        return 0;
    }

    printf("%s\n", ans);
    free(ans);
    return 0;
}