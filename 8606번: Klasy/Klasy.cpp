/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 8606                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: cjhool <boj.kr/u/cjhool>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/8606                           #+#        #+#      #+#    */
/*   Solved: 2025/02/27 12:29:34 by cjhool        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string dirStr, turnStr;
    cin >> n >> dirStr >> turnStr;

    int x1, x2, y1, y2;
    cin >> x1 >> x2 >> y1 >> y2;

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int d;

    if (dirStr == "POLNOC")
        d = 0;
    else if (dirStr == "WSCHOD")
        d = 1;
    else if (dirStr == "POLUDNIE")
        d = 2;
    else if (dirStr == "ZACHOD")
        d = 3;

    int startX, startY;
    if (dirStr == "POLNOC")
    {
        if (turnStr == "PRAWO")
        {
            startX = 1;
            startY = 1;
        }
        else
        {
            startX = n;
            startY = 1;
        }
    }
    else if (dirStr == "POLUDNIE")
    {
        if (turnStr == "PRAWO")
        {
            startX = n;
            startY = n;
        }
        else
        {
            startX = 1;
            startY = n;
        }
    }
    else if (dirStr == "WSCHOD")
    {
        if (turnStr == "PRAWO")
        {
            startX = 1;
            startY = n;
        }
        else
        {
            startX = 1;
            startY = 1;
        }
    }
    else if (dirStr == "ZACHOD")
    {
        if (turnStr == "PRAWO")
        {
            startX = n;
            startY = 1;
        }
        else
        {
            startX = n;
            startY = n;
        }
    }

    int cols = x2 - x1 + 1, rows = y2 - y1 + 1;
    vector<int> ans(rows * cols, 0);

    auto store = [&](int col, int row, int num)
    {
        if (col >= x1 && col <= x2 && row >= y1 && row <= y2)
        {
            int idx = (row - y1) * cols + (col - x1);
            ans[idx] = num;
        }
    };

    vector<char> visited(n * n, 0);
    auto idx = [&](int col, int row) -> int
    { return (row - 1) * n + (col - 1); };

    int total = n * n;
    int curX = startX, curY = startY, curD = d;
    store(curX, curY, 1);
    visited[idx(curX, curY)] = 1;

    for (int num = 2; num <= total; num++)
    {
        int nx = curX + dx[curD], ny = curY + dy[curD];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && !visited[idx(nx, ny)])
        {
            curX = nx;
            curY = ny;
        }
        else
        {
            int nd;
            if (turnStr == "PRAWO")
                nd = (curD + 1) % 4;
            else
                nd = (curD + 3) % 4;
            curD = nd;
            curX += dx[curD];
            curY += dy[curD];
        }
        visited[idx(curX, curY)] = 1;
        store(curX, curY, num);
    }

    for (int r = rows - 1; r >= 0; r--)
    {
        for (int c = 0; c < cols; c++)
        {
            cout << ans[r * cols + c] << (c == cols - 1 ? "\n" : " ");
        }
    }

    return 0;
}