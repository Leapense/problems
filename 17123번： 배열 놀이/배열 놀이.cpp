#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--)
    {
        int N, M;
        std::cin >> N >> M;

        std::vector<std::vector<int>> A(N + 1, std::vector<int>(N + 1, 0));

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                std::cin >> A[i][j];
            }
        }

        std::vector<std::vector<int>> diff(N + 2, std::vector<int>(N + 2, 0));

        for (int i = 0; i < M; i++)
        {
            int r1, c1, r2, c2, val;
            std::cin >> r1 >> c1 >> r2 >> c2 >> val;

            diff[r1][c1] += val;
            if (r2 + 1 <= N)
            {
                diff[r2 + 1][c1] -= val;
            }
            if (c2 + 1 <= N)
            {
                diff[r1][c2 + 1] -= val;
            }
            if (r2 + 1 <= N && c2 + 1 <= N)
            {
                diff[r2 + 1][c2 + 1] += val;
            }
        }

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                diff[i][j] += diff[i][j - 1];
            }
        }

        for (int j = 1; j <= N; j++)
        {
            for (int i = 1; i <= N; i++)
            {
                diff[i][j] += diff[i - 1][j];
            }
        }

        std::vector<long long> rowSum(N + 1, 0);
        std::vector<long long> colSum(N + 1, 0);

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                A[i][j] += diff[i][j];
                rowSum[i] += A[i][j];
                colSum[j] += A[i][j];
            }
        }

        for (int i = 1; i <= N; i++)
        {
            std::cout << rowSum[i] << (i == N ? "\n" : " ");
        }
        for (int j = 1; j <= N; j++)
        {
            std::cout << colSum[j] << (j == N ? "\n" : " ");
        }
    }

    return 0;
}