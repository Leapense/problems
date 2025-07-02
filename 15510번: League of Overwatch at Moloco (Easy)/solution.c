#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void add_edge(Node** adj, int u, int v) {
    Node *new_node_v = (Node*)malloc(sizeof(Node));
    new_node_v->data = v;
    new_node_v->next = adj[u];
    adj[u] = new_node_v;

    Node *new_node_u = (Node*)malloc(sizeof(Node));
    new_node_u->data = u;
    new_node_u->next = adj[v];
    adj[v] = new_node_u;
}

bool is_bipartite_bfs(int start_node, int n, Node** adj, int* colors) {
    int queue[n];
    int head = 0, tail = 0;

    colors[start_node] = 0;
    queue[tail++] = start_node;

    while (head < tail) {
        int u = queue[head++];

        for (Node* temp = adj[u]; temp != NULL; temp = temp->next) {
            int v = temp->data;
            if (colors[v] == -1) {
                colors[v] = 1 - colors[u];
                queue[tail++] = v;
            } else if (colors[v] == colors[u]) {
                return false;
            }
        }
    }
    return true;
}

void free_adj_list(Node** adj, int n) {
    for (int i = 0; i <= n; ++i) {
        Node* current = adj[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }

    free(adj);
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    if (n <= 1 && m > 0) {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    if (n <= 1) {
        printf("IMPOSSIBLE\n");
        return 0;
    }

    Node** adj = (Node**)calloc(n + 1, sizeof(Node*));
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(adj, u, v);
    }

    int colors[n + 1];
    for (int i = 0; i <= n; ++i) {
        colors[i] = -1;
    }

    bool possible = true;
    for (int i = 1; i <= n; ++i) {
        if (colors[i] == -1) {
            if (!is_bipartite_bfs(i, n, adj, colors)) {
                possible = false;
                break;
            }
        }
    }

    if (possible) {
        printf("POSSIBLE\n");
    } else {
        printf("IMPOSSIBLE\n");
    }

    free_adj_list(adj, n);
    return 0;
}