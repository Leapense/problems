#include <iostream>
using namespace std;
int L, W, n, A;
char grid[105][105];

bool fillRegion(int x, int y, int h, int w, char ch)
{
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            grid[x + i][y + j] = ch;
    return true;
}

bool solveRect(int x, int y, int h, int w, int m, char start)
{
    if (m == 1)
    {
        if (h * w != A)
            return false;
        fillRegion(x, y, h, w, start);
        return true;
    }
    // 시도: 수평 분할
    for (int r = 1; r < h; r++)
    {
        int area1 = r * w, area2 = (h - r) * w;
        if (area1 % A != 0 || area2 % A != 0)
            continue;
        int p = area1 / A, q = area2 / A;
        if (p + q != m)
            continue;
        if (p < 1 || q < 1)
            continue;
        if (solveRect(x, y, r, w, p, start))
        {
            if (solveRect(x + r, y, h - r, w, q, start + p))
                return true;
        }
    }
    // 시도: 수직 분할
    for (int c = 1; c < w; c++)
    {
        int area1 = h * c, area2 = h * (w - c);
        if (area1 % A != 0 || area2 % A != 0)
            continue;
        int p = area1 / A, q = area2 / A;
        if (p + q != m)
            continue;
        if (p < 1 || q < 1)
            continue;
        if (solveRect(x, y, h, c, p, start))
        {
            if (solveRect(x, y + c, h, w - c, q, start + p))
                return true;
        }
    }
    return false;
}

int main()
{
    cin >> L >> W >> n;
    int total = L * W;
    if (total % n != 0)
    {
        cout << "impossible";
        return 0;
    }

    A = total / n;
    if (!solveRect(0, 0, L, W, n, 'A'))
    {
        cout << "impossible";
        return 0;
    }

    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cout << grid[i][j];
        }
        cout << "\n";
    }

    return 0;
}