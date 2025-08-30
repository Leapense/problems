#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

typedef struct P {
    int x;
    int y;
} P;

int cmpP (const void* a, const void* b) {
    const P *pa = a;
    const P *pb = b;
    if (pa->x != pb->x) return pa->x - pb->x;
    return pa->y - pb->y;
}

int absint (int x) {
    return x < 0 ? -x : x;
}

long long llabsll (long long x) {
    return x < 0 ? -x : x;
}

int gcd_int (int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    if (b == 0) return a;
    
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

void normalize_rect_inplace (int *x, int *y) {
    if (*x < 0 || (*x == 0 && *y < 0)) {
        *x = -*x;
        *y = -*y;
    }
}

void rotate90 (int *x, int *y) {
    int tx = *x;
    int ty = *y;
    *x = -ty;
    *y = tx;
}

P normalize_square_repr(int x, int y) {
    P best;
    int first = 1;
    int rx = x, ry = y;
    for (int i = 0; i < 4; i++) {
        int tx = rx, ty = ry;
        if (tx < 0 || (tx == 0 && ty < 0)) {
            tx = -tx;
            ty = -ty;
        }
        if (first || tx < best.x || (tx == best.x && ty < best.y)) {
            best.x = tx;
            best.y = ty;
            first = 0;
        }
        int ntx = -ry;
        int nty = rx;
        rx = ntx;
        ry = nty;
    }

    return best;
}

int main() {
    long long a, b;
    if (scanf("%lld%lld", &a, &b) != 2) return 0;
    
    long long A = a - 1;
    long long B = b - 1;
    int isSquare = (a == b);
    int cap = 0;
    int alloc = 1024;

    P *arr = (P*)malloc(sizeof(P) * alloc);
    for (long long x = -A; x <= A; ++x) {
        long long y2 = A * A - x * x;
        if (y2 < 0) continue;
        long long y = llround(sqrt((long double)y2));
        if (y * y != y2) continue;
        for (int sign = 1; sign >= -1; sign -= 2) {
            long long yy = y * sign;
            if (x == 0 && yy == 0) continue;
            int g = gcd_int((int)llabsll(x), (int)llabsll(yy));
            if (g == 0) continue;
            if ((B * g) % A != 0) continue;
            P rep;
            if (isSquare) rep = normalize_square_repr((int)x, (int)yy);
            else {
                int rx = (int)x;
                int ry = (int)yy;
                normalize_rect_inplace(&rx, &ry);
                rep.x = rx;
                rep.y = ry;
            }
            if (cap == alloc) {
                alloc *= 2;
                arr = (P*)realloc(arr, sizeof(P) * alloc);
            }
            arr[cap++] = rep;
        }
    }

    if (cap == 0) {
        printf("0\n");
        free(arr);
        return 0;
    }

    qsort(arr, cap, sizeof(P), cmpP);
    int uniqueCount = 1;
    for (int i = 1; i < cap; i++) {
        if (arr[i].x != arr[i - 1].x || arr[i].y != arr[i - 1].y) uniqueCount++;
    }
    printf("%d\n", uniqueCount);
    free(arr);
    return 0;
}