#include <bits/stdc++.h>
using namespace std;

class GameState
{
public:
    long long state;
    vector<char> board;

    GameState(long long s) : state(s), board(9, ' ')
    {
        for (int i = 0; i < 9; i++)
        {
            if ((state >> i) & 1)
            {
                board[i] = ((state >> (i + 9)) & 1) ? 'X' : 'O';
            }
        }
    }

    bool check_winner(char player)
    {
        int wins[8][3] = {
            {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};

        for (auto &win : wins)
        {
            if (board[win[0]] == player && board[win[1]] == player && board[win[2]] == player)
                return true;
        }

        return false;
    }

    string get_result()
    {
        bool x_win = check_winner('X');
        bool o_win = check_winner('O');
        if (x_win)
            return "X wins";
        if (o_win)
            return "O wins";
        bool full = true;
        for (auto c : board)
            if (c == ' ')
            {
                full = false;
                break;
            }

        if (full)
            return "Cat's";
        return "In progress";
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c;
    cin >> c;
    while (c--)
    {
        string s;
        cin >> s;
        long long state = stoll(s, nullptr, 8);
        GameState game(state);
        cout << game.get_result() << "\n";
    }

    return 0;
}