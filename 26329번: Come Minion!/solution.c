#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static int cmp_strptr(const void *a, const void *b) {
    const char *const *sa = (const char *const *)a;
    const char *const *sb = (const char *const *)b;
    return strcmp(*sa, *sb);
}

static bool is_forbidden(char **forb, int t, const char *q) {
    return bsearch(&q, forb, (size_t)t, sizeof(char *), cmp_strptr) != NULL;
}

int main(void) {
    int m;
    if (scanf("%d", &m) != 1) return 0;
    for (int case_idx = 0; case_idx < m; ++case_idx) {
        int t;
        if (scanf("%d", &t) != 1) return 0;
        char **forb = NULL;
        forb = (char **)malloc(sizeof(char *) * (size_t)t);
        for (int i = 0; i < t; ++i) {
            char buf[32];
            if (scanf("%31s", buf) != 1) return 0;
            size_t len = strlen(buf) + 1;
            forb[i] = (char *)malloc(len);
            memcpy(forb[i], buf, len);
        }
        qsort(forb, (size_t)t, sizeof(char *), cmp_strptr);

        int n, e;
        if (scanf("%d %d", &n, &e) != 2) return 0;
        char ***label = (char ***)malloc((size_t)n * sizeof(char **));
        for (int i = 0; i < n; ++i) {
            label[i] = (char **)malloc((size_t)n * sizeof(char *));
            for (int j = 0; j < n; ++j) label[i][j] = NULL;
        }
        for (int i = 0; i < e; ++i) {
            int a, b;
            char q[32];
            if (scanf("%d %d %31s", &a, &b, q) != 3) return 0;
            size_t len = strlen(q) + 1;
            char *qs = (char *)malloc(len);
            memcpy(qs, q, len);
            label[a][b] = qs;
            label[b][a] = qs;
        }

        bool *vis = (bool *)calloc((size_t)n, sizeof(bool));
        int *queue = (int *)malloc((size_t)n * sizeof(int));
        int head = 0, tail = 0;
        vis[0] = true;
        queue[tail++] = 0;
        bool ok = false;
        while (head < tail) {
            int u = queue[head++];
            if (u == n - 1) {
                ok = true;
                break;
            }

            for (int v = 0; v < n; ++v) {
                if (!label[u][v]) continue;
                if (vis[v]) continue;
                if (is_forbidden(forb, t, label[u][v])) continue;
                vis[v] = true;
                queue[tail++] = v;
            }
        }

        printf("%d\n", ok ? 1 : 0);

        for (int i = 0; i < n; ++i) free(label[i]);
        free(label);
        for (int i = 0; i < t; ++i) free(forb[i]);
        free(forb);
        free(vis);
        free(queue);
    }

    return 0;
}