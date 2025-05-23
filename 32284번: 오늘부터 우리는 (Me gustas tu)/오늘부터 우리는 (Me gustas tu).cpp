#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    int a, b;
    cin >> a >> b;

    // 바람 방향을 저장할 격자 (초기에는 모두 '?'로 설정)
    vector<vector<char>> wind(N, vector<char>(M, '?'));
    // 방문 여부 체크 배열
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    // 4방향 이동 (상, 하, 좌, 우) 및 이에 대응하는 바람 문자
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    char dir[4] = {'N', 'S', 'W', 'E'}; // 현재 칸에서 부모 칸으로 향하는 방향

    // BFS 큐 (각 원소는 좌표 (x, y))
    queue<pair<int, int>> q;
    q.push({a, b});
    visited[a][b] = true;

    // BFS를 통해 격자 전체를 방문하며 스패닝 트리 구성
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int x = cur.first, y = cur.second;
        // 상하좌우 4방향에 대해 검사
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            // 격자 범위 내이며 아직 방문하지 않은 칸
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if (visited[nx][ny])
                continue;
            visited[nx][ny] = true;
            // 현재 칸(cur)로 이동하도록, (nx, ny)의 바람 방향을 설정한다.
            // 예: (nx,ny)에서 (x,y)로 이동하는 것이므로,
            // x = nx + dx (따라서, 만약 x = nx+1이면, (nx,ny)의 바람은 S)
            if (x == nx + 1 && y == ny)
                wind[nx][ny] = 'S';
            else if (x == nx - 1 && y == ny)
                wind[nx][ny] = 'N';
            else if (x == nx && y == ny + 1)
                wind[nx][ny] = 'E';
            else if (x == nx && y == ny - 1)
                wind[nx][ny] = 'W';
            q.push({nx, ny});
        }
    }
    // (a,b) 칸은 출발지이므로, 아무 방향이나 넣어도 상관없다.
    wind[a][b] = 'E';

    // 결과 출력
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << wind[i][j];
        }
        cout << "\n";
    }
    return 0;
}