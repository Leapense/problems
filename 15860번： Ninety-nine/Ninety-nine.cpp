#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int total = 0;
    int my_move = 1;
    cout << my_move << "\n" << flush;
    total += my_move;

    while (total < 99) {
        int opponent_move;

        if (!(cin >> opponent_move)) {
            return 0;
        }

        int add;
        int remainder = total % 3;
        if (remainder == 0) {
            add = 1;
        } else {
            add = 3 - remainder;
            if (add > 2) {
                add = 1;
            }
        }

        if (add < 1 || add > 2) {
            add = 1;
        }

        my_move = add;
        cout << my_move << "\n" << flush;
        total += my_move;
    }

    return 0;
}