#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L;
    string S;
    cin >> L >> S;

    int maxCapture = 0;

    for (int i = 0; i < L; i++)
    {
        if (S[i] != '.')
            continue;

        string board = S;
        board[i] = 'W';

        bool legal = true;
        for (int j = 0; j < L;)
        {
            if (board[j] == 'W')
            {
                int start = j;
                while (j < L && board[j] == 'W')
                {
                    j++;
                }

                int end = j - 1;
                if (start > 0 && end < L - 1 && board[start - 1] == 'B' && board[end + 1] == 'B')
                {
                    legal = false;
                    break;
                }
            }
            else
            {
                j++;
            }
        }

        if (!legal)
            continue;

        int captured = 0;
        for (int j = 0; j < L;)
        {
            if (board[j] == 'B')
            {
                int start = j;
                while (j < L && board[j] == 'B')
                {
                    j++;
                }

                int end = j - 1;
                if (start > 0 && end < L - 1 && board[start - 1] == 'W' && board[end + 1] == 'W')
                {
                    captured += (end - start + 1);
                }
            }
            else
            {
                j++;
            }
        }

        maxCapture = max(maxCapture, captured);
    }

    cout << maxCapture << "\n";
    return 0;
}