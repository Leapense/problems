#include <stdio.h>
#include <stdlib.h>
#include <float.h>

// SonarQube Compliant: A type-safe min function is preferred over macros.
static inline double min_double(double a, double b) {
    return a < b ? a : b;
}

void solve() {
    int n, q;
    scanf("%d %d", &n, &q);

    // Using long long for endurance to handle large values
    long long* e = (long long*)malloc((n + 1) * sizeof(long long));
    int* s = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; ++i) {
        scanf("%lld %d", &e[i], &s[i]);
    }

    // Allocate 2D arrays for distances
    long long (*d_matrix)[n + 1] = malloc(sizeof(long long[n + 1][n + 1]));
    double (*dist)[n + 1] = malloc(sizeof(double[n + 1][n + 1]));

    const long long INF_LL = -1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%lld", &d_matrix[i][j]);
            if (i == j) {
                dist[i][j] = 0;
            } else if (d_matrix[i][j] != INF_LL) {
                dist[i][j] = (double)d_matrix[i][j];
            } else {
                dist[i][j] = DBL_MAX;
            }
        }
    }

    // Phase 1: Floyd-Warshall for shortest distances
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dist[i][k] != DBL_MAX && dist[k][j] != DBL_MAX) {
                    dist[i][j] = min_double(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Phase 2: Build the decision graph with time as edge weights
    double (*time_graph)[n + 1] = malloc(sizeof(double[n + 1][n + 1]));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) {
                time_graph[i][j] = 0;
            } else if (dist[i][j] <= (double)e[i]) {
                time_graph[i][j] = dist[i][j] / (double)s[i];
            } else {
                time_graph[i][j] = DBL_MAX;
            }
        }
    }

    // Phase 3: Floyd-Warshall for minimum time on the decision graph
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (time_graph[i][k] != DBL_MAX && time_graph[k][j] != DBL_MAX) {
                    time_graph[i][j] = min_double(time_graph[i][j], time_graph[i][k] + time_graph[k][j]);
                }
            }
        }
    }

    for (int k = 0; k < q; ++k) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (k > 0) {
            printf(" ");
        }

        printf("%.10f", time_graph[u][v]);
    }

    printf("\n");

    free(e);
    free(s);
    free(d_matrix);
    free(dist);
    free(time_graph);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {
        printf("Case #%d: ", i);
        solve();
    }

    return 0;
}