#include "main.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void solve(istream &in, ostream &out)
{
    int N, M;
    in >> N >> M;

    vector<vector<int>> image(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int R, G, B;
            in >> R >> G >> B;
            int avg = (R + G + B) / 3;
            image[i][j] = avg;
        }
    }

    int T;
    in >> T;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            image[i][j] = (image[i][j] >= T) ? 255 : 0;
        }
    }

    vector<vector<bool>> visited(N, vector<bool>(M, false));
    int objectCount = 0;

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (image[i][j] == 255 && !visited[i][j])
            {
                objectCount++;
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;

                while (!q.empty())
                {
                    auto [x, y] = q.front();
                    q.pop();

                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];
                        if (nx >= 0 && nx < N && ny >= 0 && ny < M)
                        {
                            if (image[nx][ny] == 255 && !visited[nx][ny])
                            {
                                visited[nx][ny] = true;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
    }

    out << objectCount;
}

#ifndef UNIT_TESTS
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve(std::cin, std::cout);
    return 0;
}
#endif