#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STEPS 60
#define MAX_NODES (MAX_STEPS + 1)
#define INF_DIST 1000000

typedef struct {
    int x;
    int y;
} Point;

static Point nodes[MAX_NODES];
static int nodeCount;
static int adjList[MAX_NODES][MAX_NODES];
static int degreeList[MAX_NODES];

static int getOrCreateNode(int x, int y)
{
    int i;
    for (i = 0; i < nodeCount; ++i) {
        if (nodes[i].x == x && nodes[i].y == y) {
            return i;
        }
    }

    nodes[nodeCount].x = x;
    nodes[nodeCount].y = y;
    degreeList[nodeCount] = 0;
    return nodeCount++;
}

static bool isConnected(int u, int v)
{
    int i;
    for (i = 0; i < degreeList[u]; ++i)
    {
        if (adjList[u][i] == v) {
            return true;
        }
    }

    return false;
}

static void connectNodes(int u, int v)
{
    if (u == v) {
        return;
    }
    if (!isConnected(u, v)) {
        adjList[u][degreeList[u]++] = v;
    }
    if (!isConnected(v, u)) {
        adjList[v][degreeList[v]++] = u;
    }
}

static int bfsShortest(int startIdx, int endIdx) {
    bool visited[MAX_NODES] = {false};
    int dist[MAX_NODES];
    int q[MAX_NODES];
    int head = 0, tail = 0;
    int i, u, v;

    for (i = 0; i < nodeCount; ++i) {
        dist[i] = INF_DIST;
    }

    visited[startIdx] = true;
    dist[startIdx] = 0;
    q[tail++] = startIdx;

    while (head < tail) {
        u = q[head++];
        if (u == endIdx) {
            break;
        }
        for (i = 0; i < degreeList[u]; ++i) {
            v = adjList[u][i];
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                q[tail++] = v;
            }
        }
    }

    return dist[endIdx];
}

int main(void)
{
    int n;
    if (scanf("%d\n", &n) != 1) {
        return 0;
    }

    char buffer[16];
    int pathIdx, s, i;
    for (pathIdx = 0; pathIdx < n; ++pathIdx) {
        do {
            if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
                break;
            }
        } while (buffer[0] == '\n' || buffer[0] == '\r');

        if (sscanf(buffer, "%d", &s) != 1) {
            s = 0;
        }

        nodeCount = 0;
        for (i = 0; i < MAX_NODES; ++i) {
            degreeList[i] = 0;
        }

        int curX = 0, curY = 0;
        int curIdx = getOrCreateNode(0, 0);

        if (s == 0) {
            printf("0\n");
            continue;
        }

        for (i = 0; i < s; ++i) {
            char dir;
            if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
                dir = ' ';
            } else {
                dir = buffer[0];
            }

            int nextX = curX;
            int nextY = curY;
            switch(dir)
            {
                case 'N': nextY = curY + 1; break;
                case 'E': nextX = curX + 1; break;
                case 'S': nextY = curY - 1; break;
                case 'W': nextX = curX - 1; break;
                default: break;
            }

            int nextIdx = getOrCreateNode(nextX, nextY);
            connectNodes(curIdx, nextIdx);

            curX = nextX;
            curY = nextY;
            curIdx = nextIdx;
        }

        int endIdx = curIdx;
        int answer = bfsShortest(0, endIdx);
        printf("%d\n", answer);
    }

    return 0;
}