// K-Queen.cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
using ll = long long;

struct Pos {
    ll r, c;
};

bool is_attacked(ll r, ll c, const vector<Pos>& queens) {
    for (const auto& queen : queens) {
        if (queen.r == r) return true;
        if (queen.c == c) return true;
        if (abs(queen.r - r) == abs(queen.c - c)) return true;
    }
    return false;
}

// This is the function you will test
string kqueen_status(ll N, ll K, ll king_r, ll king_c, const vector<Pos>& queens) {
    bool king_attacked = is_attacked(king_r, king_c, queens);

    int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    int safeMoves = 0;
    int validMoves = 0;

    for (int i = 0; i < 8; i++) {
        ll nr = king_r + dr[i];
        ll nc = king_c + dc[i];

        if (nr < 1 || nr > N || nc < 1 || nc > N) continue;
        validMoves++;
        if (!is_attacked(nr, nc, queens)) safeMoves++;
    }

    if (king_attacked) {
        if (safeMoves > 0) {
            return "CHECK";
        } else {
            return "CHECKMATE";
        }
    } else {
        if (validMoves > 0 && safeMoves == 0) {
            return "STALEMATE";
        } else {
            return "NONE";
        }
    }
}

#ifndef UNIT_TEST
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    int K;
    cin >> N >> K;
    ll king_r, king_c;
    cin >> king_r >> king_c;

    vector<Pos> queens(K);

    for (int i = 0; i < K; i++) {
        cin >> queens[i].r >> queens[i].c;
    }

    cout << kqueen_status(N, K, king_r, king_c, queens) << "\n";
    return 0;
}
#endif