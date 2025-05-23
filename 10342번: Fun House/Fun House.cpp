#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int W, L, house = 1;
    while (cin >> W >> L)
    {
        if (W == 0 && L == 0)
            break;
        vector<string> room(L);
        for (int i = 0; i < L; i++)
        {
            cin >> room[i];
        }

        int start_i = -1, start_j = -1;
        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j < W; j++)
            {
                if (room[i][j] == '*')
                {
                    start_i = i;
                    start_j = j;
                    break;
                }
            }
            if (start_i != -1)
                break;
        }

        int di = 0, dj = 0;
        if (start_i == 0)
        {
            di = 1;
            dj = 0;
        }
        else if (start_i == L - 1)
        {
            di = -1;
            dj = 0;
        }
        else if (start_j == 0)
        {
            di = 0;
            dj = 1;
        }
        else if (start_j == W - 1)
        {
            di = 0;
            dj = -1;
        }
        int i = start_i, j = start_j;
        while (true)
        {
            i += di;
            j += dj;
            if (room[i][j] == '/')
            {
                if (di == -1 && dj == 0)
                {
                    di = 0;
                    dj = 1;
                }
                else if (di == 1 && dj == 0)
                {
                    di = 0;
                    dj = -1;
                }
                else if (di == 0 && dj == 1)
                {
                    di = -1;
                    dj = 0;
                }
                else if (di == 0 && dj == -1)
                {
                    di = 1;
                    dj = 0;
                }
            }
            else if (room[i][j] == '\\')
            {
                if (di == -1 && dj == 0)
                {
                    di = 0;
                    dj = -1;
                }
                else if (di == 1 && dj == 0)
                {
                    di = 0;
                    dj = 1;
                }
                else if (di == 0 && dj == 1)
                {
                    di = 1;
                    dj = 0;
                }
                else if (di == 0 && dj == -1)
                {
                    di = -1;
                    dj = 0;
                }
            }

            if (room[i][j] == 'x')
            {
                room[i][j] = '&';
                break;
            }
        }

        cout << "HOUSE " << house++ << "\n";
        for (auto &line : room)
            cout << line << "\n";
    }

    return 0;
}