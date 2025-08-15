#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    int *to;
    int *next;
    int *head;
    int edge_count;
    int capacity;
} Graph;

static bool graph_init(Graph *g, int n, int edges_capacity) {
    g->to = (int *)malloc((size_t)edges_capacity * sizeof(int));
    g->next = (int *)malloc((size_t)edges_capacity * sizeof(int));
    g->head = (int *)malloc((size_t)(n + 1) * sizeof(int));
    if (!g->to || !g->next || !g->head) return false;
    for (int i = 0; i <= n; i++) g->head[i] = -1;
    g->edge_count = 0;
    g->capacity = edges_capacity;
    return true;
}

static void graph_add_edge(Graph *g, int u, int v) {
    int idx = g->edge_count++;
    g->to[idx] = v;
    g->next[idx] = g->head[u];
    g->head[u] = idx;
}

static void graph_free(Graph *g) {
    free(g->to);
    free(g->next);
    free(g->head);
}

int main(void) {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    for (int tc = 1; tc <= T; tc++) {
        int N;
        if (scanf("%d", &N) != 1) return 0;

        Graph g;
        if (!graph_init(&g, N, 2 * N)) return 0;

        int *deg = (int *)calloc((size_t)(N + 1), sizeof(int));
        int *queue = (int *)malloc((size_t)N * sizeof(int));
        int *queue2 = (int *)malloc((size_t)N * sizeof(int));
        int *dist = (int *)malloc((size_t)(N + 1) * sizeof(int));
        bool *in_cycle = (bool *)calloc((size_t)(N + 1), sizeof(bool));
        if (!deg || !queue || !queue2 || !dist || !in_cycle) return 0;

        for (int i = 0; i < N; i++) {
            int x, y;
            if (scanf("%d %d", &x, &y) != 2) return 0;
            graph_add_edge(&g, x, y);
            graph_add_edge(&g, y, x);
            deg[x]++;
            deg[y]++;
        }

        int qh = 0, qt = 0;
        for (int i = 1; i <= N; i++) {
            if (deg[i] == 1) queue[qt++] = i;
        }

        while (qh < qt) {
            int v = queue[qh++];
            for (int e = g.head[v]; e != -1; e = g.next[e]) {
                int u = g.to[e];
                if (deg[u] > 0) {
                    deg[u]--;
                    if (deg[u] == 1) queue[qt++] = u;
                }
            }
            deg[v] = 0;
        }

        for (int i = 1; i <= N; i++) {
            if (deg[i] > 0) in_cycle[i] = true;
        }

        for (int i = 1; i <= N; i++) dist[i] = -1;
        int qh2 = 0, qt2 = 0;
        for (int i = 1; i <= N; i++) {
            if (in_cycle[i]) {
                dist[i] = 0;
                queue2[qt2++] = i;
            }
        }
        
        while (qh2 < qt2) {
            int v = queue2[qh2++];
            for (int e = g.head[v]; e != -1; e = g.next[e]) {
                int u = g.to[e];
                if (dist[u] == -1) {
                    dist[u] = dist[v] + 1;
                    queue2[qt2++] = u;
                }
            }
        }

        printf("Case #%d:", tc);
        for (int i = 1; i <= N; i++) {
            printf(" %d", dist[i]);
        }
        printf("\n");

        graph_free(&g);
        free(deg);
        free(queue);
        free(queue2);
        free(dist);
        free(in_cycle);
    }

    return 0;
}