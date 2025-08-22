#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

static const int64_t MOD = 1000000007LL;

typedef struct {
    int to;
    int next;
} Edge;

int main(void) {
    int n = 0;
    int m = 0;
    if (scanf("%d %d", &n, &m) != 2) {
        return 0;
    }

    int totalEdges = m * 2;
    Edge* edges = (Edge*)malloc((size_t) totalEdges * sizeof(Edge));
    int* head = (int*)malloc((size_t)(n + 1) * sizeof(int));
    if (edges == NULL || head == NULL) {
        free(edges);
        free(head);
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        head[i] = -1;
    }

    int edgeIndex = 0;
    for (int i = 0; i < m; i++) {
        int u = 0;
        int v = 0;
        if (scanf("%d %d", &u, &v) != 2) {
            free(edges);
            free(head);
            return 0;
        }

        edges[edgeIndex].to = v;
        edges[edgeIndex].next = head[u];
        head[u] = edgeIndex++;
        edges[edgeIndex].to = u;
        edges[edgeIndex].next = head[v];
        head[v] = edgeIndex++;
    }

    bool* visited = (bool*) calloc((size_t)(n + 1), sizeof(bool));
    int* stack = (int*) malloc((size_t) n * sizeof(int));
    if (visited == NULL || stack == NULL) {
        free(edges);
        free(head);
        free(visited);
        free(stack);
        return 0;
    }

    int64_t answer = 1;
    for (int start = 1; start <= n; start++) {
        if (visited[start]) {
            continue;
        }

        int top = 0;
        int64_t size = 0;
        visited[start] = true;
        stack[top++] = start;
        while (top > 0) {
            int u = stack[--top];
            size++;
            for (int e = head[u]; e != -1; e = edges[e].next) {
                int v = edges[e].to;
                if (!visited[v]) {
                    visited[v] = true;
                    stack[top++] = v;
                }
            }
        }

        answer = (answer * (size % MOD)) % MOD;
    }
    printf("%lld\n", answer);
    free(edges);
    free(head);
    free(visited);
    free(stack);
    return 0;
}