#include <stdio.h>
#include <stdbool.h>

#define MAXN 2000

static int N, M;
static int A[MAXN][MAXN];

static int drF, dcF;
static int drP, dcP;
static int r1, c1, r2, c2;
static long long cur, filled;

static inline bool inb(int r, int c) {
    return (0 <= r && r < N && 0 <= c && c < M);
}

static bool step_perp(int sgn) {
    int t1r = r1 + (sgn==+1 ? -drP : +drP);
    int t1c = c1 + (sgn==+1 ? -dcP : +dcP);
    int t2r = r2 + (sgn==+1 ? +drP : -drP);
    int t2c = c2 + (sgn==+1 ? +dcP : -dcP);

    bool ok1 = inb(t1r, t1c) && A[t1r][t1c]==0;
    bool ok2 = inb(t2r, t2c) && A[t2r][t2c]==0;
    if (!ok1 && !ok2) return false;

    int val = (int)(++cur);
    if (ok1){ A[t1r][t1c]=val; ++filled; r1=t1r; c1=t1c; }
    if (ok2){ A[t2r][t2c]=val; ++filled; r2=t2r; c2=t2c; }
    return true;
}

static bool step_par(int sgn) {
    int dr = (sgn==+1 ? drF : -drF);
    int dc = (sgn==+1 ? dcF : -dcF);

    int t1r = r1 + dr, t1c = c1 + dc;
    int t2r = r2 + dr, t2c = c2 + dc;

    bool ok1 = inb(t1r, t1c) && A[t1r][t1c]==0;
    bool ok2 = inb(t2r, t2c) && A[t2r][t2c]==0;
    if (!ok1 && !ok2) return false;

    int val = (int)(++cur);
    if (ok1){ A[t1r][t1c]=val; ++filled; r1=t1r; c1=t1c; }
    if (ok2){ A[t2r][t2c]=val; ++filled; r2=t2r; c2=t2c; }
    return true;
}

int main(void) {
    if (scanf("%d %d", &N, &M) != 2) return 0;
    char S; scanf(" %c", &S);

    int r=0, c=0;
    drF=dcF=drP=dcP=0;
    if (S=='U'){ r=0;   c=M/2; drF= 1; dcF=0;  drP=0; dcP=1; }
    else if(S=='D'){ r=N-1; c=M/2; drF=-1; dcF=0;  drP=0; dcP=1; }
    else if(S=='L'){ r=N/2; c=0;   drF=0;  dcF=1;  drP=1; dcP=0; }
    else { /*R*/   r=N/2; c=M-1; drF=0;  dcF=-1; drP=1; dcP=0; }

    cur = 1; filled = 0;
    A[r][c] = (int)cur;
    ++filled;

    while (1) {
        int nr = r + drF, nc = c + dcF;
        if (!inb(nr, nc)) break;
        ++cur; A[nr][nc] = (int)cur; ++filled;
        r = nr; c = nc;
    }

    r1 = r; c1 = c; r2 = r; c2 = c;

    for (int phase = 0; filled < (long long)N * M; phase = (phase + 1) & 3) {
        if (phase == 0) {while(step_perp(+1)) {}}
        else if (phase == 1) {while(step_par(-1)) {}}
        else if (phase == 2) {while(step_perp(-1)) {}}
        else {while(step_par(+1)) {}}
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (j) putchar(' ');
            printf("%d", A[i][j]);
        }
        putchar('\n');
    }

    return 0;
}