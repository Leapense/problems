#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void solve()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N, M, K;
        cin >> N >> M >> K;

        vector<string> grid(N);
        for (int i = 0; i < N; i++)
        {
            cin >> grid[i];
        }

        int blockRows = N / K, blockCols = M / K;
        vector<vector<char>> best(K, vector<char>(K));

        long long changes = 0;

        for (int r = 0; r < K; r++)
        {
            for (int c = 0; c < K; c++)
            {
                vector<int> freq(26, 0);
                for (int bi = 0; bi < blockRows; bi++)
                {
                    for (int bj = 0; bj < blockCols; bj++)
                    {
                        int i = bi * K + r;
                        int j = bj * K + c;
                        freq[grid[i][j] - 'A']++;
                    }
                }

                int maxFreq = 0;
                int bestColor = 0;

                for (int k = 0; k < 26; k++)
                {
                    if (freq[k] > maxFreq)
                    {
                        maxFreq = freq[k];
                        bestColor = k;
                    }
                }
                best[r][c] = 'A' + bestColor;
                changes += (blockRows * blockCols - maxFreq);
            }
        }

        cout << changes << "\n";

        for (int i = 0; i < N; i++)
        {
            string row = "";
            for (int j = 0; j < M; j++)
            {
                row.push_back(best[i % K][j % K]);
            }

            cout << row << "\n";
        }
    }
};

int main()
{
    Solution sol;
    sol.solve();
    return 0;
}