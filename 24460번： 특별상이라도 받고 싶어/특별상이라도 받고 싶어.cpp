#include <bits/stdc++.h>
using namespace std;

class SpecialAwardSelector
{
public:
    int N;
    vector<vector<int>> grid;
    SpecialAwardSelector(int size) : N(size), grid(size, vector<int>(size)) {}
    int select_special(int start_row, int start_col, int size)
    {
        if (size == 1)
            return grid[start_row][start_col];
        int half = size / 2;
        vector<int> candidates;
        candidates.push_back(select_special(start_row, start_col, half));
        candidates.push_back(select_special(start_row, start_col + half, half));
        candidates.push_back(select_special(start_row + half, start_col, half));
        candidates.push_back(select_special(start_row + half, start_col + half, half));

        sort(candidates.begin(), candidates.end());
        return candidates[1];
    }

    int get_special_award()
    {
        return select_special(0, 0, N);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    SpecialAwardSelector selector(N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> selector.grid[i][j];
        }
    }
    cout << selector.get_special_award() << endl;
    return 0;
}