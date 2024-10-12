#include <iostream>
#include <algorithm>

using namespace std;

struct Board {
    int x1, y1, x2, y2;
};

bool check_coverage(int X, int Y, int A, int B, Board &board) {
    if (A <= X && B <= Y) {
        board = {0, 0, A, B};
        return true;
    } else if (B <= X && A <= Y) {
        board = {0, 0, B, A};
        return true;
    }
    return false;
}

bool try_two_boards(int X, int Y, int A1, int B1, int A2, int B2, Board &board1, Board &board2) {
    // Check all possible placements of two boards
    if (A1 + A2 <= X && max(B1, B2) <= Y) {
        board1 = {0, 0, A1, B1};
        board2 = {A1, 0, A1 + A2, B2};
        return true;
    } else if (A1 + B2 <= X && max(B1, A2) <= Y) {
        board1 = {0, 0, A1, B1};
        board2 = {A1, 0, A1 + B2, A2};
        return true;
    } else if (B1 + A2 <= X && max(A1, B2) <= Y) {
        board1 = {0, 0, B1, A1};
        board2 = {B1, 0, B1 + A2, B2};
        return true;
    } else if (B1 + B2 <= X && max(A1, A2) <= Y) {
        board1 = {0, 0, B1, A1};
        board2 = {B1, 0, B1 + B2, A2};
        return true;
    } else if (A1 + A2 <= Y && max(B1, B2) <= X) {
        board1 = {0, 0, B1, A1};
        board2 = {0, A1, B2, A1 + A2};
        return true;
    } else if (A1 + B2 <= Y && max(B1, A2) <= X) {
        board1 = {0, 0, B1, A1};
        board2 = {0, A1, A2, A1 + B2};
        return true;
    } else if (B1 + A2 <= Y && max(A1, B2) <= X) {
        board1 = {0, 0, A1, B1};
        board2 = {0, B1, A2, B1 + A2};
        return true;
    } else if (B1 + B2 <= Y && max(A1, A2) <= X) {
        board1 = {0, 0, A1, B1};
        board2 = {0, B1, B2, B1 + B2};
        return true;
    }
    return false;
}

int main() {
    int X, Y;
    cin >> X >> Y;
    int A1, B1, A2, B2;
    cin >> A1 >> B1;
    cin >> A2 >> B2;

    // Case when only one board is needed to cover the floor
    Board board;
    if (check_coverage(X, Y, A1, B1, board)) {
        cout << board.x1 << " " << board.y1 << " " << board.x2 << " " << board.y2 << endl;
        cout << "Z" << endl;
        return 0;
    } else if (check_coverage(X, Y, A2, B2, board)) {
        cout << "Z" << endl;
        cout << board.x1 << " " << board.y1 << " " << board.x2 << " " << board.y2 << endl;
        return 0;
    }

    // Case when two boards are needed
    Board board1, board2;
    if (try_two_boards(X, Y, A1, B1, A2, B2, board1, board2)) {
        cout << board1.x1 << " " << board1.y1 << " " << board1.x2 << " " << board1.y2 << endl;
        cout << board2.x1 << " " << board2.y1 << " " << board2.x2 << " " << board2.y2 << endl;
        return 0;
    }

    // If no solution found
    cout << "EI SAA" << endl;
    return 0;
}