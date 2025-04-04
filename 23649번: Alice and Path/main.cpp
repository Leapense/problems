#include <iostream>
#include <string>
#include <cmath>
#include <cassert>

using namespace std;

int hexDistance(int q, int r) {
    int s = -q - r;
    return max({abs(q), abs(r), abs(s)});
}

pair<int, int> dirs[6] = {
    {1, 0},
    {0, 1},
    {-1, 1},
    {-1, 0},
    {0, -1},
    {1, -1}
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int q = 0, r = 0;
    int d = 0;

    for (char c : s) {
        int turn = 0;
        if (c == 'l') turn = 1;
        else if (c == 'r') turn = 5;
        else if (c == 'b') turn = 3;
        else assert(false);

        d = (d + turn) % 6;
        q += dirs[d].first;
        r += dirs[d].second;
    }

    string ans = "";

    while (q != 0 || r != 0) {
        int currentDist = hexDistance(q, r);
        int bestDist = currentDist;
        char bestMove = ' ';
        int best_d = d, best_q = q, best_r = r;

        for (char move : {'l', 'r', 'b'}) {
            int turn = 0;
            if (move == 'l') turn = 1;
            else if (move == 'r') turn = 5;
            else if (move == 'b') turn = 3;
            int new_d = (d + turn) % 6;
            int new_q = q + dirs[new_d].first;
            int new_r = r + dirs[new_d].second;
            int newDist = hexDistance(new_q, new_r);
            if (newDist < bestDist) {
                bestDist = newDist;
                bestMove = move;
                best_d = new_d;
                best_q = new_q;
                best_r = new_r;
            }
        }

        if (bestMove == ' ') {
            bestMove = 'l';
            best_d = (d + 1) % 6;
            best_q = q + dirs[best_d].first;
            best_r = r + dirs[best_d].second;
        }

        ans.push_back(bestMove);
        d = best_d; q = best_q; r = best_r;
        if (ans.size() > 100000) break;
    }

    cout << ans << "\n";
    return 0;
}
