#include "testlib.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

const int dr4[] = {-1, 0, 1, 0};
const int dc4[] = {0, 1, 0, -1};
const char dir4[] = {'N', 'E', 'S', 'W'};

struct Result {
    int len;
    char dir;

    bool operator<(const Result& other) const {
        if (len != other.len) {
            return len < other.len;
        }
        return dir < other.dir;
    }
};

Result solve(int R, int S, const std::vector<std::string>& g) {
    int sr = -1, sc = -1;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < S; ++j) {
            if (g[i][j] == 'o') {
                sr = i;
                sc = j;
                break;
            }
        }
    }

    if (sr == -1) return {1000000000, 0};

    Result best = {1000000000, 0};

    for (int d = 0; d < 4; ++d) {
        int r = sr + dr4[d];
        int c = sc + dc4[d];
        int step = 1;
        if (r < 0 || r >= R || c < 0 || c >= S) continue;

        int max_steps = R * S + 5;
        for (int k = 0; k < max_steps; ++k) {
            if (r < 0 || r >= R || c < 0 || c >= S) break;
            char ch = g[r][c];
            if (ch == 'x') {
                Result current = {step, dir4[d]};
                if (current < best) {
                    best = current;
                }

                break;
            }
            if (ch == '.' || (r == sr && c == sc)) break;

            int nr = r, nc = c;
            if (ch == 'v') nr++;
            else if (ch == '^') nr--;
            else if (ch == '<') nc--;
            else if (ch == '>') nc++;
            else break;

            r = nr; c = nc; step++;
        }
    }

    return best;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int max_R = opt<int>("max_r");
    int max_S = opt<int>("max_s");

    ensuref(3 <= max_R && max_R <= 100, "max_r must be in [3, 100]");
    ensuref(3 <= max_S && max_S <= 100, "max_s must be in [3, 100]");

    int R = rnd.next(3, max_R);
    int S = rnd.next(3, max_S);

    bool want_solvable = rnd.next(10) >= 2;

    std::vector<std::string> grid;
    int start_r, start_c;

    while (true) {
        grid.assign(R, std::string(S, '.'));
        start_r = rnd.next(0, R - 1);
        start_c = rnd.next(0, S - 1);
        grid[start_r][start_c] = 'o';

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < S; ++j) {
                if (grid[i][j] == 'o') continue;

                int choice = rnd.next(100);
                if (choice < 60) {
                    grid[i][j] = '.';
                } else if (choice < 95) {
                    grid[i][j] = rnd.any(std::string("v^<>"));
                } else {
                    grid[i][j] = 'x';
                }
            }
        }

        Result res = solve(R, S, grid);
        bool is_actually_solvable = (res.dir != 0);

        if (want_solvable == is_actually_solvable) {
            break;
        }
        if (want_solvable && !is_actually_solvable) {
            std::vector<int> p = {0, 1, 2, 3};
            shuffle(p.begin(), p.end());

            bool fixed = false;
            for (int dir_idx : p) {
                int nr = start_r + dr4[dir_idx];
                int nc = start_c + dc4[dir_idx];
                if (nr >= 0 && nr < R && nc >= 0 && nc < S) {
                    grid[nr][nc] = 'x';
                    fixed = true;
                    break;
                }
            }

            if (fixed) break;
        }

        if (!want_solvable && is_actually_solvable) {
            for (int i = 0; i < R; ++i) {
                for (int j = 0; j < S; ++j) {
                    if (grid[i][j] == 'x') {
                        grid[i][j] = '.';
                    }
                }
            }

            break;
        }
    }

    println(R, S);
    for (int i = 0; i < R; ++i) {
        println(grid[i].c_str());
    }

    return 0;
}