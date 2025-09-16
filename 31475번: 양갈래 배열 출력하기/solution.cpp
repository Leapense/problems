// C++26
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; 
    if (!(cin >> N >> M)) return 0;
    char S; cin >> S;

    vector<vector<int>> A(N, vector<int>(M, 0));
    auto inb = [&](int r, int c){ return 0 <= r && r < N && 0 <= c && c < M; };

    // 시작점 & 방향(Forward: 축 방향, Perp: 수직 방향의 +)
    int r=0, c=0, drF=0, dcF=0, drP=0, dcP=0;
    if (S=='U'){ r=0; c=M/2;   drF= 1; dcF=0;  drP=0; dcP=1; }
    else if(S=='D'){ r=N-1; c=M/2; drF=-1; dcF=0;  drP=0; dcP=1; }
    else if(S=='L'){ r=N/2; c=0;   drF=0;  dcF=1;  drP=1; dcP=0; }
    else { /*R*/    r=N/2; c=M-1; drF=0;  dcF=-1; drP=1; dcP=0; }

    long long cur = 1, filled = 0;
    A[r][c] = (int)cur; ++filled;

    // 1) 축 방향 직진
    while (true) {
        int nr = r + drF, nc = c + dcF;
        if (!inb(nr, nc)) break;
        ++cur; A[nr][nc] = (int)cur; ++filled;
        r = nr; c = nc;
    }

    // 두 팔의 현재 위치(같은 점에서 시작)
    int r1=r, c1=c, r2=r, c2=c;

    auto step_perp = [&](int sgn)->bool {
        // sgn=+1: OUTWARD, sgn=-1: INWARD
        // 이번 틱에 이동/기입할 후보 좌표를 먼저 계산
        pair<int,int> t1 = {r1 + (sgn==+1? -drP : +drP), c1 + (sgn==+1? -dcP : +dcP)};
        pair<int,int> t2 = {r2 + (sgn==+1? +drP : -drP), c2 + (sgn==+1? +dcP : -dcP)};
        bool ok1 = inb(t1.first, t1.second) && A[t1.first][t1.second]==0;
        bool ok2 = inb(t2.first, t2.second) && A[t2.first][t2.second]==0;
        if (!ok1 && !ok2) return false;

        int val = (int)(++cur);
        if (ok1){ A[t1.first][t1.second]=val; ++filled; r1=t1.first; c1=t1.second; }
        if (ok2){ A[t2.first][t2.second]=val; ++filled; r2=t2.first; c2=t2.second; }
        return true;
    };

    auto step_par = [&](int sgn)->bool {
        // sgn=+1: FORWARD, sgn=-1: BACKWARD
        int dr = (sgn==+1? drF : -drF);
        int dc = (sgn==+1? dcF : -dcF);
        pair<int,int> t1 = {r1+dr, c1+dc};
        pair<int,int> t2 = {r2+dr, c2+dc};
        bool ok1 = inb(t1.first, t1.second) && A[t1.first][t1.second]==0;
        bool ok2 = inb(t2.first, t2.second) && A[t2.first][t2.second]==0;
        if (!ok1 && !ok2) return false;

        int val = (int)(++cur);
        if (ok1){ A[t1.first][t1.second]=val; ++filled; r1=t1.first; c1=t1.second; }
        if (ok2){ A[t2.first][t2.second]=val; ++filled; r2=t2.first; c2=t2.second; }
        return true;
    };

    // 2) 네 국면 반복: OUT → BACK → IN → FORW
    for (int phase=0; filled < 1LL*N*M; phase = (phase+1)&3) {
        if (phase==0){ while (step_perp(+1)) {} }   // OUTWARD
        else if (phase==1){ while (step_par(-1)) {} } // BACKWARD
        else if (phase==2){ while (step_perp(-1)) {} } // INWARD
        else { while (step_par(+1)) {} }              // FORWARD
    }

    // 출력
    for (int i=0;i<N;++i){
        for (int j=0;j<M;++j){
            if (j) cout << ' ';
            cout << A[i][j];
        }
        cout << '\n';
    }
    return 0;
}