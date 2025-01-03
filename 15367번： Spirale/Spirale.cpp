#include <bits/stdc++.h>
using namespace std;

static const long long INF = LLONG_MAX;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N, M, K; cin >> N >> M >> K;
    vector<vector<long long>> ans(N, vector<long long>(M, INF));

    long long S = 4LL * (N + M) * (N + M);

    vector<pair<int, int>> cw = {{0,1},{1,0},{0,-1},{-1,0}};
    vector<pair<int, int>> ccw = {{-1,0},{0,-1},{1,0},{0,1}};

    for (int i = 0; i < K; i++) {
        int x, y, t; cin >> x >> y >> t;
        x--;
        y--;

        vector<vector<long long>> earliest(N, vector<long long>(M, INF));
        long long step = 1;
        long long segLen = 1, usedLen = 0, leftLen = 1;
        int dirIdx = 0;

        long long curX = x, curY = y;

        if (curX >= 0 && curX < N && curY >= 0 && curY < M) earliest[curX][curY] = min(earliest[curX][curY], step);

        while (step <= S) {
            step++;
            if (t == 0) {
                curX += cw[dirIdx].first;
                curY += cw[dirIdx].second;
            } else {
                curX += ccw[dirIdx].first;
                curY += ccw[dirIdx].second;
            }

            if (curX >= 0 && curX < N && curY >= 0 && curY < M) {
                if (earliest[curX][curY] == INF) {
                    earliest[curX][curY] = step;
                }
            }

            leftLen--;
            if (leftLen == 0) {
                dirIdx = (dirIdx + 1) % 4;
                usedLen++;
                if (usedLen == 2) {
                    segLen++;
                    usedLen = 0;
                }
                leftLen = segLen;
            }
        }

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                ans[r][c] = min(ans[r][c], earliest[r][c]);
            }
        }
    }

    for(int r=0;r<N;r++){
        for(int c=0;c<M;c++){
            cout << ans[r][c];
            if(c+1<M) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}