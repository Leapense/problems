#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const string target = "word";
    constexpr int L = 4;
    constexpr int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    constexpr int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    int n;
    cin >> n;
    while (n--)
    {
        int r, c;
        cin >> r >> c;
        vector<string> grid(r);
        for (int i = 0; i < r; i++)
        {
            cin >> grid[i];
        }

        long long count = 0;
        // 모든 셀 순회
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                // 8방향 검사
                for (int dir = 0; dir < 8; dir++)
                {
                    int x = i, y = j;
                    int k;
                    for (k = 0; k < L; k++)
                    {
                        // 범위 체크
                        if (x < 0 || x >= r || y < 0 || y >= c || grid[x][y] != target[k])
                            break;
                        x += dx[dir];
                        y += dy[dir];
                    }
                    if (k == L)
                    {
                        // 4글자 모두 일치
                        count++;
                    }
                }
            }
        }

        cout << count << '\n';
    }

    return 0;
}