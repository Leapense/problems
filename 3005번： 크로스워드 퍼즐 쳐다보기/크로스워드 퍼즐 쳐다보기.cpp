#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int R, C;
    cin >> R >> C;
    vector<string> puzzle(R);

    for (int i = 0; i < R; i++)
    {
        cin >> puzzle[i];
    }

    vector<string> words;

    for (int i = 0; i < R; i++)
    {
        string current = "";
        for (int j = 0; j < C; j++)
        {
            if (puzzle[i][j] != '#')
            {
                current.push_back(puzzle[i][j]);
            }
            else
            {
                if (current.length() >= 2)
                {
                    words.push_back(current);
                }

                current = "";
            }
        }

        if (current.length() >= 2)
        {
            words.push_back(current);
        }
    }

    for (int j = 0; j < C; j++)
    {
        string current = "";
        for (int i = 0; i < R; i++)
        {
            if (puzzle[i][j] != '#')
            {
                current.push_back(puzzle[i][j]);
            }
            else
            {
                if (current.length() >= 2)
                {
                    words.push_back(current);
                }
                current = "";
            }
        }

        if (current.length() >= 2)
        {
            words.push_back(current);
        }
    }

    sort(words.begin(), words.end());
    cout << words[0] << endl;

    return 0;
}