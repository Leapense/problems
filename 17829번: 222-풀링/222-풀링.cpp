#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> matrix(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    while (N > 1)
    {
        int newSize = N / 2;
        vector<vector<int>> newMatrix(newSize, vector<int>(newSize));

        for (int i = 0; i < N; i += 2)
        {
            for (int j = 0; j < N; j += 2)
            {
                int a = matrix[i][j];
                int b = matrix[i][j + 1];
                int c = matrix[i + 1][j];
                int d = matrix[i + 1][j + 1];

                vector<int> block = {a, b, c, d};
                sort(block.begin(), block.end());
                newMatrix[i / 2][j / 2] = block[2];
            }
        }

        matrix = move(newMatrix);
        N = newSize;
    }
    cout << matrix[0][0] << "\n";
    return 0;
}