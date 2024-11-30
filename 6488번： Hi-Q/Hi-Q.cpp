#include <bits/stdc++.h>
using namespace std;

const int ROWS = 7;
const int COLS = 7;

const vector<pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

struct Move {
    int source;
    int over;
    int target;
};

vector<Move> initialize_moves(vector<pair<int, int>> &hole_to_pos_map) {
    int grid[ROWS][COLS];
    memset(grid, 0, sizeof(grid));

    // Assign hole numbers to grid positions
    // Row 0
    grid[0][2] = 1;
    grid[0][3] = 2;
    grid[0][4] = 3;
    // Row1
    grid[1][2] = 4;
    grid[1][3] = 5;
    grid[1][4] = 6;
    // Row2
    grid[2][0] = 7;
    grid[2][1] = 8;
    grid[2][2] = 9;
    grid[2][3] = 10;
    grid[2][4] = 11;
    grid[2][5] = 12;
    grid[2][6] = 13;
    // Row3
    grid[3][0] = 14;
    grid[3][1] = 15;
    grid[3][2] = 16;
    grid[3][3] = 17;
    grid[3][4] = 18;
    grid[3][5] = 19;
    grid[3][6] = 20;
    // Row4
    grid[4][0] = 21;
    grid[4][1] = 22;
    grid[4][2] = 23;
    grid[4][3] = 24;
    grid[4][4] = 25;
    grid[4][5] = 26;
    grid[4][6] = 27;
    // Row5
    grid[5][2] = 28;
    grid[5][3] = 29;
    grid[5][4] = 30;
    // Row6
    grid[6][2] = 31;
    grid[6][3] = 32;
    grid[6][4] = 33;

    hole_to_pos_map.assign(34, {-1, -1});
    for(int r = 0; r < ROWS; ++r){
        for(int c = 0; c < COLS; ++c){
            if(grid[r][c] != 0){
                hole_to_pos_map[grid[r][c]] = {r, c};
            }
        }
    }

    vector<Move> all_moves;

    for (int hole = 1; hole <= 33; ++hole) {
        auto [r, c] = hole_to_pos_map[hole];
        if (r == -1) continue;
        for (auto &[dr, dc] : directions) {
            int over_r = r + dr;
            int over_c = c + dc;
            int target_r = r + 2*dr;
            int target_c = c + 2*dc;
            if(over_r >=0 && over_r < ROWS && over_c >=0 && over_c < COLS &&
               target_r >=0 && target_r < ROWS && target_c >=0 && target_c < COLS){
                int over_hole = grid[over_r][over_c];
                int target_hole = grid[target_r][target_c];
                if(over_hole != 0 && target_hole != 0){
                    Move m;
                    m.source = hole;
                    m.over = over_hole;
                    m.target = target_hole;
                    all_moves.push_back(m);
                }
            }
        }
    }

    return all_moves;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<int, int>> hole_to_pos_map;
    vector<Move> all_moves = initialize_moves(hole_to_pos_map);

    int N;
    cin >> N;
    while(N--) {
        vector<int> pegs;
        int num;

        while(cin >> num && num != 0) {
            pegs.push_back(num);
        }

        vector<bool> peg_state(34, false);
        for (auto hole : pegs) {
            if(hole >= 1 && hole <= 33) {
                peg_state[hole] = true;
            }
        }

        while(true) {
            vector<Move> possible_moves;
            for (auto &m : all_moves) {
                if(peg_state[m.source] && peg_state[m.over] && !peg_state[m.target]){
                    possible_moves.push_back(m);
                }
            }

            if (possible_moves.empty()) break;

            sort(possible_moves.begin(), possible_moves.end(), [&](const Move &a, const Move &b) -> bool {
                if (a.target != b.target) return a.target > b.target;
                return a.source > b.source;
            });

            Move selected_move = possible_moves[0];
            peg_state[selected_move.source] = false;
            peg_state[selected_move.target] = true;
            peg_state[selected_move.over] = false;
        }

        long long sum = 0;
        for (int hole = 1; hole <= 33; ++hole) {
            if(peg_state[hole]) {
                sum += hole;
            }
        }

        cout << sum << "\n";
    }

    return 0;
}