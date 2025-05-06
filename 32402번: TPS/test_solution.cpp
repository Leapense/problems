#include <gtest/gtest.h>
#include <bits/stdc++.h>

using namespace std;

vector<array<int, 4>> processCommands(const vector<string> &cmds)
{
    int xp = 0, yp = 0;
    int dx = 0, dy = -1;
    vector<array<int, 4>> result;
    result.reserve(cmds.size());

    for (auto &cmd : cmds)
    {
        if (cmd == "W")
        {
            xp += -dx;
            yp += -dy;
        }
        else if (cmd == "S")
        {
            xp += dx;
            yp += dy;
        }
        else if (cmd == "A")
        {
            xp += dy;
            yp += -dx;
        }
        else if (cmd == "D")
        {
            xp += -dy;
            yp += dx;
        }
        else if (cmd == "MR")
        {
            int ndx = dy, ndy = -dx;
            dx = ndx;
            dy = ndy;
        }
        else if (cmd == "ML")
        {
            int ndx = -dy, ndy = dx;
            dx = ndx;
            dy = ndy;
        }

        int xc = xp + dx, yc = yp + dy;
        result.push_back({xp, yp, xc, yc});
    }

    return result;
}

TEST(TPS_Sample, Sample1)
{
    vector<string> cmds = {"MR", "W", "D"};
    auto res = processCommands(cmds);
    vector<array<int, 4>> exp = {
        {0, 0, -1, 0},
        {1, 0, 0, 0},
        {1, -1, 0, -1},
    };
    ASSERT_EQ(res.size(), exp.size());
    for (size_t i = 0; i < exp.size(); i++)
    {
        EXPECT_EQ(res[i], exp[i]);
    }
}

TEST(TPS_Sample, Sample2)
{
    vector<string> cmds = {"W", "D", "ML", "S", "MR", "A"};
    auto res = processCommands(cmds);
    vector<array<int, 4>> exp = {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {1, 1, 2, 1},
        {2, 1, 3, 1},
        {2, 1, 2, 0},
        {1, 1, 1, 0},
    };
    ASSERT_EQ(res.size(), exp.size());
    for (size_t i = 0; i < exp.size(); i++)
    {
        EXPECT_EQ(res[i], exp[i]);
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}