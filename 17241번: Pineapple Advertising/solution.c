#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void solve(void) {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);

    int* degrees = (int*)calloc(n + 1, sizeof(int));
    int** edge_pairs = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; ++i) {
        edge_pairs[i] = (int*)malloc(2 * sizeof(int));
        scanf("%d %d", &edge_pairs[i][0], &edge_pairs[i][1]);
        degrees[edge_pairs[i][0]]++;
        degrees[edge_pairs[i][1]]++;
    }

    int** adj = (int**)malloc((n + 1) * sizeof(int*));
    int* adj_len = (int*)calloc(n + 1, sizeof(int));
    for (int i = 1; i <= n; ++i) {
        if (degrees[i] > 0) {
            adj[i] = (int*)malloc(degrees[i] * sizeof(int));
        } else {
            adj[i] = NULL;
        }
    }

    for (int i = 0; i < m; ++i) {
        int u = edge_pairs[i][0];
        int v = edge_pairs[i][1];
        adj[u][adj_len[u]++] = v;
        adj[v][adj_len[v]++] = u;
        free(edge_pairs[i]);
    }
    free(edge_pairs);
    free(degrees);

    bool* converted = (bool*)calloc(n + 1, sizeof(bool));

    for (int i = 0; i < q; ++i) {
        int target_house;
        scanf("%d", &target_house);

        long long newly_converted_count = 0;
        if (!converted[target_house]) {
            converted[target_house] = true;
            newly_converted_count++;
        }

        int current_len = adj_len[target_house];
        int new_len = 0;
        int* temp_adj = (int*)malloc(current_len * sizeof(int));

        for (int j = 0; j < current_len; ++j) {
            int neighbor = adj[target_house][j];
            if (converted[neighbor]) {
                temp_adj[new_len++] = neighbor;
            } else {
                converted[neighbor] = true;
                newly_converted_count++;
            }
        }

        free(adj[target_house]);
        adj[target_house] = (int*)malloc(new_len * sizeof(int));
        for(int k = 0; k < new_len; ++k) {
            adj[target_house][k] = temp_adj[k];
        }
        adj_len[target_house] = new_len;
        free(temp_adj);

        printf("%lld\n", newly_converted_count);
    }

    for (int i = 1; i <= n; ++i) {
        free(adj[i]);
    }
    free(adj);
    free(adj_len);
    free(converted);
}

int main(void) {
    solve();
    return 0;
}