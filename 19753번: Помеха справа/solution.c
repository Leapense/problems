#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct { long long t; int dir; int idx; } Car;

int dir_index(char c) { return c == 'U' ? 0 : c == 'L' ? 1 : c == 'D' ? 2 : 3;}

int main(void) {
    int n; scanf("%d", &n);
    Car *arr[4]; int sz[4] = {0}, cap[4] = {0};
    for (int i = 0; i < 4; ++i) cap[i] = 8, arr[i] = (Car *)malloc(sizeof(Car) * cap[i]);
    for (int i = 0; i < n; ++i) {
        long long t; char d; scanf("%lld %c", &t, &d);
        int k = dir_index(d);
        if (sz[k] == cap[k]) { cap[k] <<= 1; arr[k] = (Car *)realloc(arr[k], sizeof(Car) * cap[k]); }
        arr[k][sz[k]++] = (Car){t, k, i};
    }
    int ptr[4] = {0};
    int **queue = (int **)malloc(sizeof(int *) * 4);
    int qsz[4] = {0}, qcap[4] = {0};
    for (int i = 0; i < 4; ++i) { qcap[i] = 8; queue[i] = (int*)malloc(sizeof(int) * qcap[i]); }
    long long *ans = (long long*)malloc(sizeof(long long) * n);
    for (int i = 0; i < n; ++i) ans[i] = -1;
    long long now = 0;
    while (1) {
        int waiting = 0, remaining = 0;
        for (int k = 0; k < 4; ++k) {
            if (qsz[k]) waiting = 1;
            if (ptr[k] < sz[k]) remaining = 1;
        }
        if (!waiting && !remaining) break;
        if (!waiting) {
            long long nxt = LLONG_MAX;
            for (int k = 0; k < 4; ++k)
                if (ptr[k] < sz[k] && arr[k][ptr[k]].t < nxt) nxt = arr[k][ptr[k]].t;
            now = nxt;
        }
        for (int k = 0; k < 4; ++k)
            while (ptr[k] < sz[k] && arr[k][ptr[k]].t == now) {
                if (qsz[k] == qcap[k]) { qcap[k] <<= 1; queue[k] = (int *)realloc(queue[k], sizeof(int) * qcap[k]); }
                queue[k][qsz[k]++] = arr[k][ptr[k]++].idx;
            }
        int can[4] = {0}, any = 0;
        for (int k = 0; k < 4; ++k) {
            can[k] = qsz[k] && !qsz[(k + 1) % 4];
            if (can[k]) any = 1;
        }
        if (any) {
            for (int k = 0; k < 4; ++k) if (can[k]) {
                int id = queue[k][0];
                for (int j = 1; j < qsz[k]; ++j) queue[k][j - 1] = queue[k][j];
                --qsz[k];
                ans[id] = now;
            }
            ++now;
        } else break;
    }
    for (int i = 0; i < n; ++i) printf("%lld\n", ans[i]);
    return 0;
}