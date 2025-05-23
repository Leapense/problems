#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    char board[101][101];
    int r, c, rg, rp, cg, cp, pCount = 0;

    cin >> r >> c;
    cin >> rg >> cg >> rp >> cp;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'P') {
                pCount++;
            }
        }
    }
    if (pCount == rp * cp) cout << "0";
    else cout << "1";

    return 0;
}