#include <bits/stdc++.h>
using namespace std;

bool isValidPuzzle(const vector<string> &row, const vector<string> &col)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (row[i][j] != col[j][i])
                return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> words(6);
    for (int i = 0; i < 6; i++)
    {
        cin >> words[i];
    }

    bool found = false;
    string bestPuzzle = "";

    vector<int> indices = {0, 1, 2, 3, 4, 5};

    vector<int> bitmask(6, 0);
    fill(bitmask.begin(), bitmask.begin() + 3, 1);

    do
    {
        vector<int> rowIdx, colIdx;
        for (int i = 0; i < 6; i++)
        {
            if (bitmask[i])
                rowIdx.push_back(i);
            else
                colIdx.push_back(i);
        }

        sort(rowIdx.begin(), rowIdx.end());
        do
        {
            sort(colIdx.begin(), colIdx.end());
            do
            {
                vector<string> rowWords(3), colWords(3);
                for (int i = 0; i < 3; i++)
                {
                    rowWords[i] = words[rowIdx[i]];
                    colWords[i] = words[colIdx[i]];
                }

                if (isValidPuzzle(rowWords, colWords))
                {
                    string puzzleConcat = rowWords[0] + rowWords[1] + rowWords[2];
                    if (!found || puzzleConcat < bestPuzzle)
                    {
                        found = true;
                        bestPuzzle = puzzleConcat;
                    }
                }
            } while (next_permutation(colIdx.begin(), colIdx.end()));
        } while (next_permutation(rowIdx.begin(), rowIdx.end()));
    } while (prev_permutation(bitmask.begin(), bitmask.end()));

    if (!found)
        cout << 0 << "\n";
    else
    {
        for (int i = 0; i < 3; i++)
        {
            cout << bestPuzzle.substr(i * 3, 3) << "\n";
        }
    }

    return 0;
}