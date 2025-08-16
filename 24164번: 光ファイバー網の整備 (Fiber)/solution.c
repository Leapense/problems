#include <stdio.h>
#include <stdlib.h>

static int find_set(int *parent, int x) {
    while (parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }

    return x;
}

static void unite(int *parent, int *size, int a, int b) {
    int ra = find_set(parent, a);
    int rb = find_set(parent, b);
    if (ra == rb) {
        return;
    }
    if (size[ra] < size[rb]) {
        int t = ra;
        ra = rb;
        rb = t;
    }
    parent[rb] = ra;
    size[ra] += size[rb];
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }
    int m;
    if (scanf("%d", &m) != 1) {
        return 0;
    }
    if (n <= 0) {
        printf("0\n");
        return 0;
    }

    int *parent = (int *)malloc((size_t)(n + 1) * sizeof(int));
    int *size = (int *)malloc((size_t)(n + 1) * sizeof(int));
    if (parent == NULL || size == NULL) {
        free(parent);
        free(size);
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        if (scanf("%d %d", &a, &b) != 2) {
            continue;
        }
        if (a >= 1 && a <= n && b >= 1 && b <= n && a != b) {
            unite(parent, size, a, b);
        }
    }

    int *seen = (int *)calloc((size_t)(n + 1), sizeof(int));
    if (seen == NULL) {
        free(parent);
        free(size);
        return 0;
    }

    int comps = 0;
    for (int i = 1; i <= n; i++) {
        int r = find_set(parent, i);
        if (!seen[r]) {
            seen[r] = 1;
            comps++;
        }
    }

    int ans = comps > 0 ? comps - 1 : 0;
    printf("%d\n", ans);

    free(parent);
    free(size);
    free(seen);

    return 0;
}