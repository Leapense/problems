#define UNIT_TEST
#include "solution.cpp"
#include <gtest/gtest.h>

bool ok(const vector<string> &g)
{
    int M = g.size();
    if (M == 0)
        return false;
    int N = M / 3;
    if (M != 3 * N)
        return false;
    for (auto &row : g)
        if ((int)row.size() != M)
            return false;

    for (int i = 0; i < M; ++i)
    {
        int ca = 0, cn = 0, cz = 0;
        for (int j = 0; j < M; ++j)
        {
            ca += g[i][j] == 'A';
            cn += g[i][j] == 'N';
            cz += g[i][j] == 'Z';
        }

        if (ca != N || cn != N || cz != N)
            return false;
    }
    for (int j = 0; j < M; ++j)
    {
        int ca = 0, cn = 0, cz = 0;
        for (int i = 0; i < M; ++i)
        {
            ca += g[i][j] == 'A';
            cn += g[i][j] == 'N';
            cz += g[i][j] == 'Z';
        }
        if (ca != N || cn != N || cz != N)
            return false;
    }

    auto bad = [&](char a, char b, char c)
    {
        return a == 'A' && b == 'N' && c == 'Z';
    };

    for (int i = 0; i < M; ++i)
        for (int j = 0; j + 2 < M; ++j)
            if (bad(g[i][j], g[i][j + 1], g[i][j + 2]))
                return false;
    for (int i = 0; i + 2 < M; ++i)
        for (int j = 0; j < M; ++j)
            if (bad(g[i][j], g[i + 1][j], g[i + 2][j]))
                return false;
    for (int i = 0; i + 2 < M; ++i)
        for (int j = 0; j + 2 < M; ++j)
            if (bad(g[i][j], g[i + 1][j + 1], g[i + 2][j + 2]))
                return false;
    return true;
}

TEST(AntiFanDeath, SampleN1)
{
    auto g = build(1);
    EXPECT_TRUE(ok(g));
}
TEST(AntiFanDeath, SampleN2)
{
    auto g = build(2);
    EXPECT_TRUE(ok(g));
}
TEST(AntiFanDeath, RandomN)
{
    for (int N : {3, 5, 10, 100})
    {
        auto g = build(N);
        EXPECT_TRUE(ok(g));
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}