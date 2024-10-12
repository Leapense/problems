#include <bits/stdc++.h>

using namespace std;

#define MAX 100

int R, C;
char board[MAX][MAX + 1];

int gore(int i) {
    if (board[0][i] != '.') return 0;

    for (int x = 0; x < R-1; x++) {
        board[x][i] = board[x+1][i];
    }

    board[R-1][i] = '.';

    return 1;
}

int dolje(int i) {
    if (board[R-1][i] != '.') return 0;

    for (int x = R-1; x > 0; --x) {
        board[x][i] = board[x-1][i];
    }

    board[0][i] = '.';

    return 1;
}

int main(void) {
    cin >> R >> C;

    for (int r = 0; r < R; r++) {
        cin >> board[r];
    }

    int r = 0;
    while(board[r][0] != 'L') ++r;

    int delta = -1;

    for (int s = 1; s < C; ++s) {
        if (r == 0) delta = 1;
        if (r == R-1) delta = -1;
        r += delta;

        while (board[r][s] != '.' && gore(s));
        while (board[r][s] != '.' && dolje(s));

        board[r][s] = 'L';
    }

    for (int r = 0; r < R; r++) cout << board[r] << endl;

    return 0;
}