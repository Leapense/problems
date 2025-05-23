#include <iostream>
#include <vector>

using namespace std;

struct Point
{
    int r, c;
};

int main()
{
    int N;
    cin >> N;

    vector<string> grid(N);
    for (int i = 0; i < N; i++)
    {
        cin >> grid[i];
    }

    vector<Point> letters;

    vector<vector<bool>> hasLetter(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] != '.')
            {
                letters.push_back({i, j});
                hasLetter[i][j] = true;
            }
        }
    }

    int count = 0;
    int size = letters.size();

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            for (int k = j + 1; k < size; k++)
            {
                // 세 점의 좌표
                int x1 = letters[i].r, y1 = letters[i].c;
                int x2 = letters[j].r, y2 = letters[j].c;
                int x3 = letters[k].r, y3 = letters[k].c;

                // 공선 조건 검사
                if ((x2 - x1) * (y3 - y1) == (y2 - y1) * (x3 - x1))
                {
                    count++;
                }
            }
        }
    }

    cout << count << "\n";

    return 0;
}