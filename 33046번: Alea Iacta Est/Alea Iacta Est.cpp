#include <bits/stdc++.h>

using namespace std;

int A, B, C, D;

int getPlayer(int diceSum, int currentPlayer) {
    int player = (currentPlayer + diceSum - 1) % 4;
    if (player == 0) player = 4;

    return player;
}

int main() {
    cin >> A >> B;
    cin >> C >> D;

    int firstSum = A + B;
    int gaDong = getPlayer(firstSum, 1);
    int secondSum = C + D;
    int jinDong = getPlayer(secondSum, gaDong);

    cout << jinDong << endl;

    return 0;
}