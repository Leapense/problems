#include <stdio.h>
#include <string.h>
#define MAXN 101
#define MAXT 251

typedef struct {int t; int x; int y;} Event;

int main(void)
{
    int n, t;
    if (scanf("%d %d", &n, &t) != 2) return 0;

    char state[MAXN];
    scanf("%s", state);
    Event ev[MAXT];
    for (int i = 0; i < t; ++i) scanf("%d %d %d", &ev[i].t, &ev[i].x, &ev[i].y);
    for (int i = 0; i < t - 1; ++i) for (int j = i + 1; j < t; ++j) if (ev[i].t > ev[j].t) {
        Event tmp = ev[i];
        ev[i] = ev[j];
        ev[j] = tmp;
    }

    int patientCnt = 0;
    int minK = MAXT + 5;
    int maxK = -1;
    for (int p = 1; p <= n; ++p) {
        int validK[MAXT + 2] = {0};
        for (int K = 0; K <= t + 1; ++K) {
            int infected[MAXN] = {0};
            int used[MAXN] = {0};
            infected[p] = 1;
            for (int i = 0; i < t; ++i) {
                int a = ev[i].x, b = ev[i].y;
                int aCan = infected[a] && used[a] < K;
                int bCan = infected[b] && used[b] < K;
                if (aCan) {infected[b] = 1; ++used[a];}
                if (bCan) {infected[a] = 1; ++used[b];}
            }

            int ok = 1;
            for (int i = 1; i <= n && ok; ++i) {
                if (infected[i] != state[i - 1] - '0') ok = 0;
            }
            if (ok) validK[K] = 1;
        }

        int any = 0;
        for (int K = 0; K <= t + 1; ++K) if (validK[K]) any = 1;
        if (any) {
            ++patientCnt;
            for (int K = 0; K <= t + 1; ++K) if (validK[K]) {
                if (K < minK) minK = K;
                if (K > maxK) maxK = K;
            }
        }
    }

    printf("%d %d ", patientCnt, minK);
    if (maxK == t + 1) puts("Infinity"); else printf("%d\n", maxK);
    return 0;
}