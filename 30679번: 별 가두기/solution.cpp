#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 주어진 그리드에서 별을 가둘 수 있는 시작 행(1-based)들의 목록을 반환한다.
 * @param N 행 개수
 * @param M 열 개수
 * @param A N x M 격자 (0-based indexing)
 * @return 가둘 수 있는 시작 행(1-based)들의 오름차순 벡터
 */
vector<int> find_trapped(int N, int M, const vector<vector<int>> &A)
{
    static constexpr array<int, 4> dr = {0, 1, 0, -1};
    static constexpr array<int, 4> dc = {1, 0, -1, 0};

    vector<int> result;
    result.reserve(N);

    for (int start = 0; start < N; ++start)
    {
        static bool vis[100][100][4];
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                for (int d = 0; d < 4; ++d)
                {
                    vis[i][j][d] = false;
                }
            }
        }

        int r = start, c = 0, dir = 0;
        bool trapped = false;
        while (true)
        {
            if (vis[r][c][dir])
            {
                trapped = true;
                break;
            }
            vis[r][c][dir] = true;

            int step = A[r][c];
            int nr = r + dr[dir] * step;
            int nc = c + dc[dir] * step;

            if (nr < 0 || nr >= N || nc < 0 || nc >= M)
            {
                trapped = false;
                break;
            }

            r = nr;
            c = nc;

            dir = (dir + 1) & 3;
        }

        if (trapped)
        {
            result.push_back(start + 1);
        }
    }

    return result;
}

#ifndef UNIT_TEST
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> A(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> A[i][j];
        }
    }

    auto res = find_trapped(N, M, A);
    cout << res.size() << "\n";

    if (!res.empty())
    {
        for (int x : res)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}
#endif