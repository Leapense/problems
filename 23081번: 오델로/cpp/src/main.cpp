#include "main.h"
#include <iostream>
#include <vector>
#include <string>
#include <optional>
#include <algorithm>

using namespace std;

std::optional<Move> find_best_move(const std::vector<std::string> &board)
{
    int N = board.size();

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
        return std::nullopt;
    }

    return Move{bestX, bestY, bestFlip};
}

#ifndef UNIT_TESTS
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    std::vector<std::string> board(N);
    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
    }

    auto move = find_best_move(board);
    if (!move.has_value())
    {
        cout << "PASS";
    }
    else
    {
        cout << move->x << " " << move->y << "\n"
             << move->flipCount;
    }

    return 0;
}
#endif