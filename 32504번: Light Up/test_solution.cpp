#include <gtest/gtest.h>
#include <bits/stdc++.h>

using namespace std;

// 그리드를 받아서 유효한 Light Up 해답인지 검사
bool isValidSolution(const vector<string> &G)
{
    int n = (int)G.size();
    auto isBlocked = [&](int r, int c)
    {
        char ch = G[r][c];
        return ch == 'X' || (ch >= '0' && ch <= '4');
    };

    // 1) 두 전구가 직선상에 서로 보이면 안 된다
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (G[r][c] == '?')
            {
                // 4방향 검사
                constexpr int dr[4] = {1, -1, 0, 0}, dc[4] = {0, 0, 1, -1};
                for (int d = 0; d < 4; d++)
                {
                    int rr = r + dr[d], cc = c + dc[d];
                    while (rr >= 0 && rr < n && cc >= 0 && cc < n && !isBlocked(rr, cc))
                    {
                        if (G[rr][cc] == '?')
                            return false;
                        rr += dr[d];
                        cc += dc[d];
                    }
                }
            }
        }
    }

    // 2) 모든 열린 칸은 최소 한 전구에 의해 밝혀져야 한다
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (G[r][c] == '.')
            {
                bool lit = false;
                // 2-1) 자기 자신에 전구 없음 ('.')
                // 2-2) 4방향으로 전구 찾기
                constexpr int dr[4] = {1, -1, 0, 0}, dc[4] = {0, 0, 1, -1};
                for (int d = 0; d < 4 && !lit; d++)
                {
                    int rr = r + dr[d], cc = c + dc[d];
                    while (rr >= 0 && rr < n && cc >= 0 && cc < n && !isBlocked(rr, cc))
                    {
                        if (G[rr][cc] == '?')
                        {
                            lit = true;
                            break;
                        }
                        rr += dr[d];
                        cc += dc[d];
                    }
                }
                if (!lit)
                    return false;
            }
            // '?' 칸은 자체로 발광하므로 항상 lit
        }
    }

    // 3) 숫자 칸의 인접 전구 개수 검사
    constexpr int dr2[4] = {1, -1, 0, 0}, dc2[4] = {0, 0, 1, -1};
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (G[r][c] >= '0' && G[r][c] <= '4')
            {
                int need = G[r][c] - '0';
                int cnt = 0;
                for (int d = 0; d < 4; d++)
                {
                    int rr = r + dr2[d], cc = c + dc2[d];
                    if (rr >= 0 && rr < n && cc >= 0 && cc < n && G[rr][cc] == '?')
                    {
                        cnt++;
                    }
                }
                if (cnt != need)
                    return false;
            }
        }
    }

    return true;
}

TEST(LightUp, Sample1)
{
    vector<string> G = {
        ".?.0..?",
        "..X.1?.",
        ".X.?.2.",
        ".....?.",
        "?3?..2.",
        ".?3.X?.",
        "..?X?.."};
    EXPECT_TRUE(isValidSolution(G));
}

TEST(LightUp, Sample2)
{
    vector<string> G = {
        ".?.0..?",
        "..X.1?.",
        ".X...2.",
        ".....?.",
        "?3?..2.",
        ".?3.X?.",
        "..?X?.."};
    EXPECT_FALSE(isValidSolution(G));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}