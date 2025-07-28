#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef enum { CUBE, CYL } Kind;
typedef struct { Kind kind; int val; char raw[24]; } Block;

static int fits(const Block *a, const Block *b) {
    if (a->kind == CUBE && b->kind == CUBE) return a->val <= b->val;
    if (a->kind == CUBE && b->kind == CYL) return (double)a->val <= (double)b->val * sqrt(2.0);
    if (a->kind == CYL && b->kind == CYL) return a->val <= b->val;
    return 2 * a->val <= b->val;
}

static int cmp(const void *p, const void *q) {
    const Block *a = (Block*)p, *b = (Block*)q;
    if (fits(a, b) && !fits(b, a)) return -1;
    if (fits(b, a) && !fits(a, b)) return 1;
    return 0;
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    Block *arr = (Block *)malloc((size_t)n * sizeof *arr);
    for (int i = 0; i < n; ++i) {
        char type[12]; int v;
        scanf("%11s%d", type, &v);
        arr[i].kind = strcmp(type, "cube") == 0 ? CUBE : CYL;
        arr[i].val = v;
        snprintf(arr[i].raw, sizeof arr[i].raw, "%s %d", type, v);
    }

    for (int i = 0; i < n && n > 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (!fits(&arr[i], &arr[j]) && !fits(&arr[j], &arr[i])) {
                puts("impossible");
                free(arr);
                return 0;
            }
        }
    }

    qsort(arr, (size_t)n, sizeof *arr, cmp);

    for (int i = 0; i < n; ++i) puts(arr[i].raw);
    free(arr);
    return 0;
}