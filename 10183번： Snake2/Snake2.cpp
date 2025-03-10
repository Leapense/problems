#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <string>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> board0(15);
    for (int i = 0; i < 15; i++)
    {
        getline(cin, board0[i]);
        if (board0[i].size() < 15)
            board0[i] += string(15 - board0[i].size(), ' ');
    }
    int T;
    cin >> T;
    cin.ignore();
    vector<pii> snakeInit;
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            if (board0[i][j] == 'X')
                snakeInit.push_back({i, j});
        }
    }
    sort(snakeInit.begin(), snakeInit.end(), [](const pii &a, const pii &b)
         { return a.first == b.first ? a.second < b.second : a.first < b.first; });
    deque<pii> initSnake;
    for (auto &p : snakeInit)
    {
        int r = p.first, c = p.second;
        if (c + 1 < 15 && c + 2 < 15 && board0[r][c + 1] == 'X' && board0[r][c + 2] == 'X')
        {
            initSnake.push_back({r, c});
            initSnake.push_back({r, c + 1});
            initSnake.push_back({r, c + 2});
            break;
        }
    }
    for (int t = 0; t < T; t++)
    {
        string moves;
        getline(cin, moves);
        deque<pii> snake = initSnake;
        set<long long> snakeSet;
        for (auto &p : snake)
            snakeSet.insert((long long)p.first * 100 + p.second);
        vector<vector<char>> board(15, vector<char>(15));
        for (int i = 0; i < 15; i++)
        {
            for (int j = 0; j < 15; j++)
            {
                char ch = board0[i][j];
                board[i][j] = (ch == 'X' ? ' ' : ch);
            }
        }
        int pellets = 0;
        int dr = 0, dc = 1;
        bool gameOver = false;
        for (char m : moves)
        {
            if (m == 'U')
            {
                dr = -1;
                dc = 0;
            }
            else if (m == 'D')
            {
                dr = 1;
                dc = 0;
            }
            else if (m == 'L')
            {
                dr = 0;
                dc = -1;
            }
            else if (m == 'R')
            {
                dr = 0;
                dc = 1;
            }
            pii head = snake.back();
            pii next = {head.first + dr, head.second + dc};
            // For both cases, check out-of-bound for pellet moves first.
            if (board[next.first < 0 || next.first >= 15 || next.second < 0 || next.second >= 15 ? 0 : next.first][next.second] != 'F')
            {
                // Normal move: remove tail first.
                pii tail = snake.front();
                snake.pop_front();
                snakeSet.erase((long long)tail.first * 100 + tail.second);
                if (next.first < 0 || next.first >= 15 || next.second < 0 || next.second >= 15)
                {
                    gameOver = true;
                    break;
                }
                long long key = (long long)next.first * 100 + next.second;
                if (snakeSet.find(key) != snakeSet.end())
                {
                    gameOver = true;
                    break;
                }
                snake.push_back(next);
                snakeSet.insert(key);
            }
            else
            {
                // Pellet move: check out-of-bound then collision; do not remove tail.
                if (next.first < 0 || next.first >= 15 || next.second < 0 || next.second >= 15)
                {
                    gameOver = true;
                    break;
                }
                long long key = (long long)next.first * 100 + next.second;
                if (snakeSet.find(key) != snakeSet.end())
                {
                    gameOver = true;
                    break;
                }
                snake.push_back(next);
                snakeSet.insert(key);
                pellets++;
                board[next.first][next.second] = ' ';
            }
        }
        vector<string> finalBoard(15, string(15, ' '));
        for (int i = 0; i < 15; i++)
        {
            for (int j = 0; j < 15; j++)
            {
                finalBoard[i][j] = board[i][j];
            }
        }
        for (auto &p : snake)
        {
            finalBoard[p.first][p.second] = 'X';
        }
        if (gameOver)
            cout << "GAME OVER" << "\n";
        else
            cout << pellets << " pellets" << "\n";
        for (auto &line : finalBoard)
            cout << line << "\n";
        if (t != T - 1)
            cout << "\n";
    }
    return 0;
}
