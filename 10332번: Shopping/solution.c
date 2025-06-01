#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int left;
    int right;
} Interval;

static int compare_interval(const void *a, const void *b)
{
    const Interval *ia = (const Interval *)a;
    const Interval *ib = (const Interval *)b;
    if (ia -> left < ib -> left) return -1;
    if (ia -> left > ib -> left) return 1;

    if (ia -> right < ib -> right) return -1;
    if (ia -> right > ib -> right) return 1;
    
    return 0;
}

int main(void)
{
    int N, m;
    if (scanf("%d %d", &N, &m) != 2)
    {
        return 0;
    }

    if (m == 0) {
        printf("%d\n", N + 1);
        return 0;
    }

    Interval *intervals = (Interval *)malloc(sizeof(Interval) * m);
    if (intervals == NULL) {
        return 0;
    }

    for (int i = 0; i < m; i++) {
        int c, d;
        scanf("%d %d", &c, &d);
        intervals[i].left = c;
        intervals[i].right = d;
    }

    qsort(intervals, m, sizeof(Interval), compare_interval);

    int merged_sum = 0;
    int curL = intervals[0].left;
    int curR = intervals[0].right;

    for (int i = 1; i < m; i++) {
        int L = intervals[i].left;
        int R = intervals[i].right;

        if (L <= curR) {
            if (R > curR) {
                curR = R;
            }
        } else {
            merged_sum += (curR - curL);
            curL = L;
            curR = R;
        }
    }

    merged_sum += (curR - curL);
    free(intervals);

    long long answer = (long long)(N + 1) + 2LL * merged_sum;
    printf("%lld\n", answer);

    return 0;
}