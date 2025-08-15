#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long i64;

typedef struct {
    int to;
    int next;
    i64 sum;
} Edge;

typedef struct {
    int width;
    int height;
} Size;

static void add_edge(int u, int v, i64 s, int *head, Edge *edges, int *edge_count) {
    int idx = (*edge_count)++;
    edges[idx].to = v;
    edges[idx].sum = s;
    edges[idx].next = head[u];
    head[u] = idx;

    idx = (*edge_count)++;
    edges[idx].to = u;
    edges[idx].sum = s;
    edges[idx].next = head[v];
    head[v] = idx;
}

static bool is_unique_solution(int w, int h, int k) {
    int n = w + h;
    int max_edges = 2 * k;
    int *head = (int *)malloc(sizeof(int) * n);
    Edge *edges = (Edge *)malloc(sizeof(Edge) * max_edges);
    bool *visited = (bool *)malloc(sizeof(bool) * n);
    i64 *value = (i64 *)malloc(sizeof(i64) * n);
    int edge_count = 0;
    if (!head || !edges || !visited || !value) {
        free(head);
        free(edges);
        free(visited);
        free(value);
        return false;
    }

    for (int i = 0; i < n; i++) head[i] = -1;
    for (int i = 0; i < n; i++) visited[i] = false;

    for (int i = 0; i < k; i++) {
        int x, y, s;
        if (scanf("%d %d %d", &x, &y, &s) != 3) {
            free(head);
            free(edges);
            free(visited);
            free(value);
            return false;
        }
        int u = x - 1;
        int v = w + (y - 1);
        add_edge(u, v, (i64)s, head, edges, &edge_count);
    }

    int *queue = (int *)malloc(sizeof(int) * n);
    if (!queue) {
        free(head);
        free(edges);
        free(visited);
        free(value);
        return false;
    }

    int front = 0;
    int back = 0;
    visited[0] = true;
    value[0] = 0;
    queue[back++] = 0;
    int visit_count = 1;
    bool inconsistent = false;

    while (front < back && !inconsistent) {
        int u = queue[front++];
        for (int e = head[u]; e != -1; e = edges[e].next) {
            int v = edges[e].to;
            i64 s = edges[e].sum;
            if (!visited[v]) {
                value[v] = s - value[u];
                visited[v] = true;
                queue[back++] = v;
                visit_count++;
            } else {
                if (value[u] + value[v] != s) {
                    inconsistent = true;
                    break;
                }
            }
        }
    }

    free(queue);
    free(head);
    free(edges);
    free(visited);
    free(value);

    if (inconsistent) return false;
    return visit_count == n;
}

int main(void) {
    while (1) {
        int w, h;
        if (scanf("%d %d", &w, &h) != 2) return 0;
        if (w == 0 && h == 0) break;
        int k = w + h - 1;
        bool ok = is_unique_solution(w, h, k);
        printf("%s\n", ok ? "YES" : "NO");
    }

    return 0;
}