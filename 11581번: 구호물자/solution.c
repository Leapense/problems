#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

typedef struct EdgeNode
{
    int vertex;
    struct EdgeNode *next;
} EdgeNode;

typedef struct Graph
{
    int num_nodes;
    EdgeNode *adj[MAX_NODES + 1];
} Graph;

static void init_graph(Graph *g, int n);
static bool add_edge(Graph *g, int from, int to);
static void dfs_reachable(int u, bool visited[], EdgeNode *adj_list[]);
static bool dfs_cycle_detect(int u, int status[], EdgeNode *adj_list[], const bool reachable[]);

int main(void)
{
    int N = 0;
    if (scanf("%d", &N) != 1) {
        return EXIT_FAILURE;
    }
    if ((N < 1) || (N > MAX_NODES)) {
        return EXIT_FAILURE;
    }

    Graph graph;
    init_graph(&graph, N);

    for (int i = 1; i <= N - 1; i++) {
        int M = 0;
        if (scanf("%d", &M) != 1) {
            return EXIT_FAILURE;
        }

        if ((M < 0) || (M > N)) {
            return EXIT_FAILURE;
        }

        for (int j = 0; j < M; j++) {
            int c = 0;
            if (scanf("%d", &c) != 1) {
                return EXIT_FAILURE;
            }

            if ((c < 1) || (c > N)) {
                return EXIT_FAILURE;
            }

            if (!add_edge(&graph, i, c)) {
                return EXIT_FAILURE;
            }
        }
    }

    bool visited_from_start[MAX_NODES + 1] = { false };
    dfs_reachable(1, visited_from_start, graph.adj);

    int status[MAX_NODES + 1] = { 0 };

    for (int u = 1; u <= N; u++) {
        if (visited_from_start[u] && status[u] == 0) {
            if (dfs_cycle_detect(u, status, graph.adj, visited_from_start)) {
                printf("CYCLE\n");
                return EXIT_SUCCESS;
            }
        }
    }

    printf("NO CYCLE\n");
    return EXIT_SUCCESS;
}

static void init_graph(Graph *g, int n) {
    g->num_nodes = n;
    for (int i = 1; i <= n; i++) 
    {
        g->adj[i] = NULL;
    }
}

static bool add_edge(Graph *g, int from, int to) {
    if ((g == NULL) || (from < 1) || (from > g->num_nodes) || (to < 1) || (to > g->num_nodes)) {
        return false;
    }

    EdgeNode *new_node = (EdgeNode *) malloc(sizeof(EdgeNode));
    if (new_node == NULL) {
        return false;
    }

    new_node->vertex = to;
    new_node->next = g->adj[from];
    g->adj[from] = new_node;
    return true;
}

static void dfs_reachable(int u, bool visited[], EdgeNode *adj_list[]) {
    if (u < 1 || u > MAX_NODES || visited[u]) {
        return;
    }

    visited[u] = true;
    for (EdgeNode *ptr = adj_list[u]; ptr != NULL; ptr = ptr->next) {
        int v = ptr->vertex;
        if (!visited[v]) {
            dfs_reachable(v, visited, adj_list);
        }
    }
}

static bool dfs_cycle_detect(int u, int status[], EdgeNode *adj_list[], const bool reachable[]) {
    status[u] = 1;
    for (EdgeNode *ptr = adj_list[u]; ptr != NULL; ptr = ptr->next) {
        int v = ptr->vertex;
        if (!reachable[v]) {
            continue;
        }

        if (status[v] == 0) {
            if (dfs_cycle_detect(v, status, adj_list, reachable)) {
                return true;
            }
        }
        else if (status[v] == 1) {
            return true;
        }
    }

    status[u] = 2;
    return false;
}