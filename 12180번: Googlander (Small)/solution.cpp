#include <iostream>
#include <array>

static int R, C;
static std::array<std::array<bool, 10>, 10> visited;
static constexpr std::array<int,4> dr = {-1, 0, +1, 0};
static constexpr std::array<int,4> dc = {0, 1, 0, -1};

int dfs(int r, int c, int dir)
{
    visited[r][c] = true;

    int fr = r + dr[dir];
    int fc = c + dc[dir];
    bool canF = fr >= 0 && fr < R && fc >= 0 && fc < C && !visited[fr][fc];

    int rdir = (dir + 1) % 4;
    int rr = r + dr[rdir];
    int rc = c + dc[rdir];
    bool canR = rr >= 0 && rr < R && rc >= 0 && rc < C && !visited[rr][rc];

    int total = 0;
    if (!canF && !canR) {
        total = 1;
    } else {
        if (canF) total += dfs(fr, fc, dir);
        if (canR) total += dfs(rr, rc, rdir);
    }

    visited[r][c] = false;
    return total;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        std::cin >> R >> C;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                visited[i][j] = false;
            }
        }

        int paths = dfs(R-1, 0, 0);
        std::cout << "Case #" << tc << ": " << paths << "\n";
    }

    return 0;
}