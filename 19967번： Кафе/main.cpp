#include <bits/stdc++.h>
using namespace std;

int iCeil(int a, int b)
{
    return (a + b - 1) / b;
}

vector<string> solveCafe(int n, int m, int k)
{
    int tablesNeeded = iCeil(n, 3) * iCeil(m, 3);
    int totalCells = n * m;
    int maxChairs = totalCells - tablesNeeded;
    if (k > maxChairs)
    {
        return {"Impossible"};
    }

    vector<string> grid(n, string(m, 'h'));
    for (int i = 0; i < iCeil(n, 3); i++)
    {
        for (int j = 0; j < iCeil(m, 3); j++)
        {
            int r = min(n - 1, 1 + 3 * i);
            int c = min(m - 1, 1 + 3 * j);
            grid[r][c] = 'T';
        }
    }

    int curChairs = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'h')
            {
                curChairs++;
            }
        }
    }

    int removeCount = curChairs - k;

    for (int i = 0; i < n && removeCount > 0; i++)
    {
        for (int j = 0; j < m && removeCount > 0; j++)
        {
            if (grid[i][j] == 'h')
            {
                grid[i][j] = '.';
                removeCount--;
            }
        }
    }

    return grid;
}

#ifndef UNIT_TESTS
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<string> ans = solveCafe(n, m, k);

    for (auto &line : ans)
    {
        cout << line << "\n";
    }

    return 0;
}
#endif

#ifdef UNIT_TESTS
#include <gtest/gtest.h>

TEST(CafeTest, Sample1)
{
    int n = 3, m = 4, k = 8;
    vector<string> sol = solveCafe(n, m, k);
    ASSERT_NE(sol.size(), 1) << "Solution should exist";

    int chairCount = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (sol[i][j] == 'h')
            {
                chairCount++;
                bool ok = false;
                for (int di = -1; di <= 1; di++)
                {
                    for (int dj = -1; dj <= 1; dj++)
                    {
                        if (di == 0 && dj == 0)
                            continue;
                        int ni = i + di, nj = j + dj;
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m && sol[ni][nj] == 'T')
                            ok = true;
                    }
                }

                EXPECT_TRUE(ok) << "Chair at (" << i << "," << j << ") has no adjacent table.";
            }
        }
    }
    EXPECT_EQ(chairCount, k);
}

TEST(CafeTest, Sample2)
{
    int n = 2, m = 2, k = 4;
    vector<string> sol = solveCafe(n, m, k);
    ASSERT_EQ(sol.size(), 1);
    EXPECT_EQ(sol[0], "Impossible");
}

TEST(CafeTest, Edge1)
{
    int n = 50, m = 50, k = 2211;
    vector<string> sol = solveCafe(n, m, k);
    ASSERT_NE(sol.size(), 1) << "Solution should exist";
    int chairCount = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (sol[i][j] == 'h')
            {
                chairCount++;
                bool ok = false;
                for (int di = -1; di <= 1; di++)
                {
                    for (int dj = -1; dj <= 1; dj++)
                    {
                        if (di == 0 && dj == 0)
                            continue;
                        int ni = i + di, nj = j + dj;
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m && sol[ni][nj] == 'T')
                            ok = true;
                    }
                }

                EXPECT_TRUE(ok) << "Chair at (" << i << "," << j << ") has no adjacent table.";
            }
        }
    }

    EXPECT_EQ(chairCount, k);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif