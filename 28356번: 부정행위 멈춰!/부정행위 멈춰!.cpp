#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    void solve()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N, M;
        cin >> N >> M;

        if (N == 1 && M == 1)
        {
            cout << 1 << "\n"
                 << 1 << "\n";
            return;
        }

        if (N == 1 || M == 1)
        {
            int K = 2;
            cout << K << "\n";
            if (N == 1)
            {
                for (int j = 0; j < M; j++)
                {
                    cout << (j % 2) + 1 << (j == M - 1 ? "\n" : " ");
                }
            }
            else
            {
                for (int i = 0; i < N; i++)
                {
                    cout << (i % 2) + 1 << "\n";
                }
            }

            return;
        }

        int K = 4;
        cout << K << "\n";
        vector<vector<int>> grid(N, vector<int>(M));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                grid[i][j] = ((i % 2) * 2 + (j % 2)) + 1;
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cout << grid[i][j] << (j == M - 1 ? "\n" : " ");
            }
        }
    }
};

int main()
{
    Solution sol;
    sol.solve();
    return 0;
}