#include <bits/stdc++.h>
using namespace std;

int H, W;
vector<string> grid;

// Evaluate the subtree rooted at (r,c) spanning h rows and w columns
long long eval(int r, int c, int h, int w)
{
    // 1) Try to find an operator on the top row
    int mid = -1;
    char op = '?';
    for (int j = c; j < c + w; ++j)
    {
        char ch = grid[r][j];
        if (ch == '+' || ch == '-' || ch == '*')
        {
            mid = j;
            op = ch;
            break;
        }
    }
    // 2) If no operator found, it's a leaf‐cell ⇒ find its single digit
    if (mid < 0)
    {
        for (int i = r; i < r + h; ++i)
            for (int j = c; j < c + w; ++j)
                if (isdigit(grid[i][j]))
                    return grid[i][j] - '0';
        return 0; // (should never happen on valid input)
    }
    // 3) Otherwise we split into left/right subcells
    int w1 = mid - c;
    int w2 = (c + w - 1) - mid;

    // Determine actual left‐child height h1 by finding the deepest non-'.'
    int h1 = 0;
    for (int rr = r + 1; rr < r + h; ++rr)
    {
        for (int j = c; j < mid; ++j)
        {
            if (grid[rr][j] != '.')
            {
                h1 = max(h1, rr - r);
                break;
            }
        }
    }
    // Similarly for right child
    int h2 = 0;
    for (int rr = r + 1; rr < r + h; ++rr)
    {
        for (int j = mid + 1; j < c + w; ++j)
        {
            if (grid[rr][j] != '.')
            {
                h2 = max(h2, rr - r);
                break;
            }
        }
    }
    // Safety: each child must be at least height 1
    if (h1 == 0)
        h1 = 1;
    if (h2 == 0)
        h2 = 1;

    // Recurse into the two child cells
    long long L = eval(r + 1, c, h1, w1);
    long long R = eval(r + 1, mid + 1, h2, w2);

    // Combine
    switch (op)
    {
    case '+':
        return L + R;
    case '-':
        return L - R;
    case '*':
        return L * R;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> H >> W;
    grid.resize(H);
    for (int i = 0; i < H; ++i)
        cin >> grid[i];

    cout << eval(0, 0, H, W) << "\n";
    return 0;
}
