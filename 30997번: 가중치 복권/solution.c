#include <stdio.h>
#include <stdlib.h>

typedef unsigned __int128 u128;
typedef unsigned long long u64;

static u128 upow(u64 a, int e) {
    u128 r = 1, b = a;
    while (e) {
        if (e & 1) r *= b;
        b *= b;
        e >>= 1;
    }
    return r;
}

static u128 ugcd(u128 a, u128 b) {
    while (b) {
        u128 t = a % b;
        a = b;
        b = t;
    }
    return a;
}

static void print_u128(u128 x) {
    if (x == 0) {
        putchar('0');
        return;
    }

    char buf[64];
    int p = 0;
    while (x) {
        int d = (int)(x % 10);
        buf[p++] = '0' + d;
        x /= 10;
    }
    while (p--) {
        putchar(buf[p]);
    }
}

int cmp_int(const void* a, const void* b) {
    int x = *(const int*)a, y = *(const int*)b;
    return (x > y) - (x < y);
}

int main(void) {
    int N, M, K;
    if (scanf("%d %d %d", &N, &M, &K) != 3) return 0;
    int *cnt = (int*)calloc(N + 1, sizeof(int));
    for (int i = 0; i < M - 1; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        cnt[a]++;
        cnt[b]++;
        cnt[c]++;
    }
    u64 T = 3ull * (u64)M;

    u128 best = 0;
    int bi = 1, bj = 2, bk = 3;

    for (int i = 1; i <= N; i++)
    for (int j = i + 1; j <= N; j++)
    for (int k = j + 1; k <= N; k++) {
        u64 x = 3ull + (u64)cnt[i] + (u64)cnt[j] + (u64)cnt[k];
        u64 Tx = T - x;
        u128 v = (u128)x * upow(Tx, K);
        if (v > best) { best = v; bi = i; bj = j; bk = k; }
    }

    u128 q = upow(T, K + 1);
    u128 g = ugcd(best, q);

    best /= g;
    q /= g;

    print_u128(best);
    putchar(' ');
    print_u128(q);
    putchar('\n');
    int arr[3] = {bi, bj, bk};
    qsort(arr, 3, sizeof(int), cmp_int);
    printf("%d %d %d\n", arr[0], arr[1], arr[2]);

    free(cnt);

    return 0;
}