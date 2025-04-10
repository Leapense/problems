#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> grid[i][j];
        }
    }

    // 각 행과 열의 합 미리 계산
    vector<int> rowSum(N, 0), colSum(M, 0);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            rowSum[i] += grid[i][j];
            colSum[j] += grid[i][j];
        }
    }

    // 최대 아름다움을 아주 작은 수로 초기화
    int ans = -1000000000;

    // 두 행 선택
    for (int r1 = 0; r1 < N; r1++)
    {
        for (int r2 = r1 + 1; r2 < N; r2++)
        {
            int currentRowSum = rowSum[r1] + rowSum[r2];
            int rowDiff = r2 - r1 - 1; // 내부 영역의 행 크기

            // 고정된 행 쌍에 대해 각 열에 대한 값을 미리 계산 (스택에 고정 배열 사용)
            int T[128]; // M의 최대값이 100이므로 여유분을 줍니다.
            for (int j = 0; j < M; j++)
            {
                T[j] = colSum[j] - grid[r1][j] - grid[r2][j];
            }

            // 두 열 선택 (고정된 행 쌍에 대해)
            for (int c1 = 0; c1 < M; c1++)
            {
                for (int c2 = c1 + 1; c2 < M; c2++)
                {
                    int interior = rowDiff * (c2 - c1 - 1); // 내부 영역 칸 수
                    int road = currentRowSum + T[c1] + T[c2];
                    int beauty = road + interior;
                    ans = max(ans, beauty);
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
