#include <stdio.h>

typedef struct { int r, c; } P;

static void rotate90(const P* in, int inLen, P* out, int N) {
    for (int i = 0; i < inLen; ++i) {
        out[i].r = in[i].c;
        out[i].c = N - 1 - in[i].r;
    }
}

int main(void) {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    char gA[10][11], gB[10][11];
    for (int i = 0; i < N; ++i) scanf("%10s", gA[i]);
    for (int i = 0; i < N; ++i) scanf("%10s", gB[i]);

    P A[100], B[100], cur[100], nxt[100];
    int aLen = 0, bLen = 0;

    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            if (gA[r][c] == '#') A[aLen++] = (P){r, c};
            if (gB[r][c] == '#') B[bLen++] = (P){r, c};
        }
    }
    for (int i = 0; i < bLen; ++i) cur[i] = B[i];
    int bestOverlap = 0;
    for (int rot = 0; rot < 4; ++rot) {
        int S = 2 * N + 1;
        int cnt[25][25] = {0};

        for (int i = 0; i < aLen; ++i) {
            for (int j = 0; j < bLen; ++j) {
                int dx = A[i].r - cur[j].r;
                int dy = A[i].c - cur[j].c;
                cnt[dx + N][dy + N] += 1;
            }
        }

        for (int i = 0; i < S; ++i) {
            for (int j = 0; j < S; ++j) {
                if (cnt[i][j] > bestOverlap) bestOverlap = cnt[i][j];
            }
        }

        rotate90(cur, bLen, nxt, N);
        for (int i = 0; i < bLen; ++i) cur[i] = nxt[i];
    }
    int answer = aLen - bestOverlap;
    printf("%d\n", answer);
    return 0;
}