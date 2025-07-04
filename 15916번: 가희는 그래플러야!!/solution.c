#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    int64_t *arr = malloc((size_t)(n + 1) * sizeof(int64_t));
    if (arr == NULL) {
        return 0;
    }

    arr[0] = 0;

    for (int i = 1; i <= n; i++) {
        scanf("%" SCNd64, &arr[i]);
    }

    int64_t k;
    scanf("%" SCNd64, &k);

    int64_t prev = 0;
    bool meet = false;

    for (int i = 1; i <= n && !meet; i++) {
        int64_t curr = arr[i] - k * (int64_t)i;
        if ((curr == 0 && i > 0) || (prev == 0 && i - 1 > 0) || ((prev < 0 && curr > 0) || (prev > 0 && curr < 0))) {
            meet = true;
        }

        prev = curr;
    }

    printf("%c\n", meet ? 'T' : 'F');
    free(arr);
    return 0;
}