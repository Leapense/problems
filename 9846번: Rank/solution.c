#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PLAYERS 1001

bool adj_matrix[MAX_PLAYERS][MAX_PLAYERS];
int adj_list[MAX_PLAYERS][MAX_PLAYERS];
int adj_list_counts[MAX_PLAYERS];
int in_degree[MAX_PLAYERS];
int queue[MAX_PLAYERS];
int result_list[MAX_PLAYERS];

void add_edge(int winner, int loser)
{
    if (winner >= MAX_PLAYERS || loser >= MAX_PLAYERS || winner <= 0 || loser <= 0) return;
    adj_matrix[winner][loser] = true; 
}

int main()
{
    int k, n;
    if (scanf("%d %d", &k, &n) != 2) return 1;

    getchar();

    memset(adj_matrix, false, sizeof(adj_matrix));
    memset(adj_list_counts, 0, sizeof(adj_list_counts));
    memset(in_degree, 0, sizeof(in_degree));

    for (int i = 0; i < n; ++i) {
        int p1, p2, p3;
        char line_buffer[50];

        if (fgets(line_buffer, sizeof(line_buffer), stdin) == NULL) {
            return 1;
        }

        if (sscanf(line_buffer, "%d > %d,%d", &p1, &p2, &p3) == 3) {
            add_edge(p1, p2);
            add_edge(p1, p3);
        } else if (sscanf(line_buffer, "%d,%d > %d", &p1, &p2, &p3) == 3) {
            add_edge(p1, p3);
            add_edge(p2, p3);
        } else {

        }
    }

    for (int r = 1; r <= k; ++r) {
        for (int c = 1; c <= k; ++c) {
            if (adj_matrix[r][c]) {
                if (adj_list_counts[r] < MAX_PLAYERS - 1) {
                    adj_list[r][adj_list_counts[r]++] = c;
                }

                in_degree[c]++;
            }
        }
    }

    int q_front = 0, q_rear = 0;
    for (int i = 1; i <= k; ++i)
    {
        if (in_degree[i] == 0)
        {
            if (q_rear < MAX_PLAYERS)
            {
                queue[q_rear++] = i;
            }
        }
    }

    int result_count = 0;
    while (q_front < q_rear)
    {
        if (result_count >= MAX_PLAYERS) break;
        int u = queue[q_front++];
        result_list[result_count++] = u;

        for (int i = 0; i < adj_list_counts[u]; ++i) 
        {
            int v = adj_list[u][i];
            in_degree[v]--;
            if (in_degree[v] == 0) {
                if (q_rear < MAX_PLAYERS) {
                    queue[q_rear++] = v;
                }
            }
        }
    }

    if (result_count == k) {
        for (int i = 0; i < k; ++i) {
            printf("%d%c", result_list[i], (i == k - 1) ? '\n' : ' ');
        }
    } else {
        printf("0\n");
    }

    return 0;
}