#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<string> board(N);
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    vector<int> costW(N, 0), costB(N, 0), costR(N, 0);

    for (int r = 0; r < N; r++) {
        int wCount = 0, bCount = 0, rCount = 0;
        for (int c = 0; c < M; c++) {
            if (board[r][c] != 'W') wCount++;
            if (board[r][c] != 'B') bCount++;
            if (board[r][c] != 'R') rCount++;
        }
        costW[r] = wCount;
        costB[r] = bCount;
        costR[r] = rCount;
    }

    vector<int> prefixW(N+1, 0), prefixB(N+1, 0), prefixR(N+1, 0);
    for(int r = 0; r < N; r++) {
        prefixW[r+1] = prefixW[r] + costW[r];
        prefixB[r+1] = prefixB[r] + costB[r];
        prefixR[r+1] = prefixR[r] + costR[r];
    }

    int answer = INT_MAX;
    for(int i = 0; i < N-2; i++) {
        for(int j = i+1; j < N-1; j++) {
            // cost for white rows = prefixW[i+1] - prefixW[0]
            int costWhite = prefixW[i+1] - prefixW[0];
            // cost for blue rows = prefixB[j+1] - prefixB[i+1]
            int costBlue = prefixB[j+1] - prefixB[i+1];
            // cost for red rows = prefixR[N] - prefixR[j+1]
            int costRed = prefixR[N] - prefixR[j+1];

            int totalCost = costWhite + costBlue + costRed;
            answer = min(answer, totalCost);
        }
    }

    cout << answer << "\n";

    return 0;
}