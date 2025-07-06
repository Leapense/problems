#include <stdio.h>
#include <stdlib.h>

typedef struct { unsigned int a, b; } Interval;

static int compare(const void *p, const void *q) {
    const Interval *x = p;
    const Interval *y = q;
    return (x->a < y->a) ? -1 : (x->a > y->a);
}

int main(void) {
    unsigned int t;
    if (scanf("%u", &t) != 1) return 0;
    while (t-- > 0) {
        unsigned int n;
        scanf("%u", &n);
        Interval *arr = malloc(sizeof *arr * n);
        for (unsigned int i = 0; i < n; i++) {
            scanf("%u %u", &arr[i].a, &arr[i].b);
        }
        qsort(arr, n, sizeof *arr, compare);
        unsigned int *stack = malloc(sizeof *stack * n);
        unsigned int top = 0;
        unsigned int maxDepth = 0;

        int possible = 1;
        for (unsigned int i = 0; i < n; i++) {
            while (top > 0 && arr[stack[top - 1]].b < arr[i].a) top--;
            if (top > 0 && arr[i].b > arr[stack[top - 1]].b) {
                possible = 0;
                break;
            }
            stack[top++] = i;
            if (top > maxDepth) maxDepth = top;
        }

        if (!possible) {
            puts("IMPOSSIBLE");
        } else {
            printf("%u\n", 2 * maxDepth - 1);
        }

        free(arr);
        free(stack);
    }

    return 0;
}