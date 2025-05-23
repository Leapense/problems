#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

int R, C;
vector<string> grid;

// 방향: 0: 위, 1: 오른쪽, 2: 아래, 3: 왼쪽
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

// 반대 방향 계산 (0 <-> 2, 1 <-> 3)
int opposite(int d)
{
    return (d + 2) % 4;
}

// (sr, sc)에서 출발하여, 첫 이동 방향이 initDir일 때, 유턴 없이 (sr, sc)로 돌아올 수 있는지 검사.
bool canReturn(int sr, int sc, int initDir)
{
    int nr = sr + dr[initDir];
    int nc = sc + dc[initDir];
    if (nr < 0 || nr >= R || nc < 0 || nc >= C || grid[nr][nc] == 'X')
        return false;

    // visited[r][c][d] : (r, c)에 d방향으로 들어온 상태 방문 여부
    bool visited[11][11][4] = {false};
    queue<tuple<int, int, int>> q;
    q.push({nr, nc, initDir});
    visited[nr][nc][initDir] = true;

    while (!q.empty())
    {
        auto [r, c, d] = q.front();
        q.pop();

        // 현재 상태에서 인접 이동 가능한 모든 방향 탐색
        for (int nd = 0; nd < 4; nd++)
        {
            // 바로 반대 방향은 허용하지 않음
            if (nd == opposite(d))
                continue;
            int rr = r + dr[nd];
            int cc = c + dc[nd];
            if (rr < 0 || rr >= R || cc < 0 || cc >= C)
                continue;
            if (grid[rr][cc] == 'X')
                continue;
            // 출발지에 도착한 경우, 유턴 없이 돌아올 수 있음.
            if (rr == sr && cc == sc)
                return true;
            if (!visited[rr][cc][nd])
            {
                visited[rr][cc][nd] = true;
                q.push({rr, cc, nd});
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C;
    grid.resize(R);
    for (int i = 0; i < R; i++)
    {
        cin >> grid[i];
    }

    // 모든 도로 칸에 대해 검사
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (grid[i][j] == '.')
            {
                // 인접 도로로 갈 수 있는 모든 초기 방향에 대해 검사
                for (int d = 0; d < 4; d++)
                {
                    int ni = i + dr[d];
                    int nj = j + dc[d];
                    if (ni < 0 || ni >= R || nj < 0 || nj >= C)
                        continue;
                    if (grid[ni][nj] == '.')
                    {
                        if (!canReturn(i, j, d))
                        {
                            cout << 1 << "\n";
                            return 0;
                        }
                    }
                }
            }
        }
    }

    cout << 0 << "\n";
    return 0;
}
