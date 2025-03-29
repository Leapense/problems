#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> image(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int R, G, B;
            cin >> R >> G >> B;

            int avg = (R + G + B) / 3;
            image[i][j] = avg;
        }
    }

    int T;
    cin >> T;

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

    cout << objectCount << "\n";
    return 0;
}