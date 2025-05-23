#include <iostream>
#include <queue>
#include <vector>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M;
    std::cin >> N >> M;

    std::vector<std::string> campus(N);
    for (int i = 0; i < N; i++)
    {
        std::cin >> campus[i];
    }

    int startX = -1, startY = -1;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (campus[i][j] == 'I')
            {
                startX = i;
                startY = j;
                break;
            }
        }

        if (startX != -1)
            break;
    }

    std::vector<std::vector<bool>> visited(N, std::vector<bool>(M, false));
    std::queue<std::pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;

    int people = 0;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if (visited[nx][ny])
                continue;
            if (campus[nx][ny] == 'X')
                continue;
            visited[nx][ny] = true;
            if (campus[nx][ny] == 'P')
                people++;
            q.push({nx, ny});
        }
    }

    if (people == 0)
        std::cout << "TT";
    else
        std::cout << people;
    return 0;
}