#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<string> board(N);

    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
    }

    int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
    int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

    int bestFlip = 0;
    int bestX = -1, bestY = -1;

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            if (board[y][x] != '.')
                continue;

            int totalFlip = 0;

            for (int d = 0; d < 8; d++)
            {
                int curX = x + dx[d];
                int curY = y + dy[d];
                int cnt = 0;

                if (curX < 0 || curX >= N || curY < 0 || curY >= N)
                    continue;
                if (board[curY][curX] != 'W')
                    continue;

                while (curX >= 0 && curX < N && curY >= 0 && curY < N && board[curY][curX] == 'W')
                {
                    cnt++;
                    curX += dx[d];
                    curY += dy[d];
                }

                if (curX < 0 || curX >= N || curY < 0 || curY >= N)
                    continue;
                if (board[curY][curX] != 'B')
                    continue;
                totalFlip += cnt;
            }

            if (totalFlip > 0)
            {
                if (totalFlip > bestFlip || (totalFlip == bestFlip && (bestY == -1 || y < bestY || (y == bestY && x < bestX))))
                {
                    bestFlip = totalFlip;
                    bestX = x;
                    bestY = y;
                }
            }
        }
    }

    if (bestFlip == 0)
    {
        cout << "PASS";
    }
    else
    {
        cout << bestX << " " << bestY << "\n"
             << bestFlip;
    }

    return 0;
}
