#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) {
        return 0;
    }

    int* c = (int*)malloc(sizeof(int) * k);
    int** freq = (int**)malloc(sizeof(int*) * k);
    int** result = (int**)malloc(sizeof(int*) * k);
    int* assigned = (int*)calloc(k, sizeof(int));
    int* resIndex = (int*)calloc(k, sizeof(int));
    if (!c || !freq || !result || !assigned || !resIndex) {
        return 0;
    }

    for (int g = 0; g < k; ++g) {
        int ci;
        if (scanf("%d", &ci) != 1) {
            return 0;
        }

        c[g] = ci;
        result[g] = (int*)malloc(sizeof(int) * ci);
        freq[g] = (int*)calloc((size_t)(n + 1), sizeof(int));
        if (!result[g] || !freq[g]) {
            return 0;
        }

        for (int j = 0; j < ci; ++j) {
            int s;
            if (scanf("%d", &s) != 1) {
                return 0;
            }
            if (s < 0 || s > n) {
                return 0;
            }
            freq[g][s] += 1;
        }
    }

    for (int t = 0; t < n; ++t) {
        int chosen = -1;
        for (int g = 0; g < k; ++g) {
            int expected = t - assigned[g];
            if (expected >= 0 && expected <= n && freq[g][expected] > 0) {
                chosen = g;
                break;
            }
        }

        if (chosen < 0) {
            return 0;
        }

        int expected = t - assigned[chosen];
        freq[chosen][expected] -= 1;
        result[chosen][resIndex[chosen]++] = t + 1;
        assigned[chosen] += 1;
    }

    for (int g = 0; g < k; ++g) {
        for (int j = 0; j < c[g]; ++j) {
            if (j > 0) {
                printf(" ");
            }
            printf("%d", result[g][j]);
        }
        if (g < k - 1) {
            printf("\n");
        }
    }

    for (int g = 0; g < k; ++g) {
        free(freq[g]);
        free(result[g]);
    }

    free(freq);
    free(result);
    free(assigned);
    free(resIndex);
    free(c);

    return 0;
}