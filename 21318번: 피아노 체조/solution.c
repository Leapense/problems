#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) {return 0;}
    int64_t *score = (int64_t *) malloc((size_t)n * sizeof(int64_t));
    for (int i = 0; i < n; ++i) {
        scanf("%" SCNd64, &score[i]);
    }
    int *pref = (int *)calloc((size_t)n, sizeof(int));
    for (int i = 1; i < n; ++i) {
        pref[i] = pref[i - 1] + (score[i - 1] > score[i]);
    }
    free(score);
    int q;
    scanf("%d", &q);
    while (q--) {
        int x, y;
        scanf("%d %d", &x, &y);
        int result = pref[y - 1] - pref[x - 1];
        printf("%d\n", result);
    }

    free(pref);
    return 0;
}