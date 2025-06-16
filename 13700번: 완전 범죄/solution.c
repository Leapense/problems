#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_N 100001

static int dist[MAX_N];
static bool is_police[MAX_N];
static int queue[MAX_N];
static int front = 0, rear = 0;

void push(int val) {
    queue[rear++] = val;
}

int pop() {
    return queue[front++];
}

bool is_empty() {
    return front == rear;
}

void solve() {
    int n, s, d, f, b, k;
    scanf("%d %d %d %d %d %d", &n, &s, &d, &f, &b, &k);

    memset(is_police, false, sizeof(is_police));
    if (k > 0) {
        for (int i = 0; i < k; ++i) {
            int police_loc;
            scanf("%d", &police_loc);
            is_police[police_loc] = true;
        }
    }

    if (is_police[s]) {
        printf("BUG FOUND\n");
        return;
    }

    memset(dist, -1, sizeof(dist));

    dist[s] = 0;
    push(s);

    while (!is_empty()) {
        int current_building = pop();

        if (current_building == d) {
            printf("%d\n", dist[d]);
            return;
        }

        int moves[2] = {current_building + f, current_building - b};
        for (int i = 0; i < 2; i++) {
            int next_building = moves[i];
            if (next_building >= 1 && next_building <= n && !is_police[next_building] && dist[next_building] == -1) {
                dist[next_building] = dist[current_building] + 1;
                push(next_building);
            }
        }
    }

    printf("BUG FOUND\n");
}

int main() {
    solve();
    return 0;
}