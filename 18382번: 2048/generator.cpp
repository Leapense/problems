#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    int maxMoves = (argc >= 2 ? atoi(argv[1]) : 1000);
    int maxScore = (argc >= 3 ? atoi(argv[2]) : 1000000);
    int maxCellVal = (argc >= 4 ? atoi(argv[3]) : 2048);

    int score = rnd.next(0, maxScore);
    cout << score << "\n";

    static const char DIRS[4] = {'L', 'R', 'U', 'D'};
    int M = rnd.next(0, maxMoves);
    string moves;
    moves.reserve(M * 4);

    for (int i = 0; i < M; i++) {
        char d = DIRS[rnd.next(0, 3)];
        int v = (rnd.next(0, 1) == 0 ? 2 : 4);
        int r = rnd.next(0, 3);
        int c = rnd.next(0, 3);
        moves += d;
        moves += char('0' + v);
        moves += char('0' + r);
        moves += char('0' + c);
    }

    cout << moves << "\n";

    for (int i = 0; i < 16; i++) {
        int cell = rnd.next(0, maxCellVal);
        cout << cell << (i + 1 < 16 ? ' ' : '\n');
    }

    return 0;
}