#include <gtest/gtest.h>
#include <sstream>
using namespace std;

void solve(istream &in, ostream &out)
{
    int n, m;
    in >> n >> m;

    vector<string> a(n);

    for (int i = 0; i < n; i++)
        in >> a[i];
    const int INF = -1000000;

    vector<vector<int>> dp(n, vector<int>(m, INF));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'W')
                dp[i][j] = 0;
        }
    }

    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < m; j++)
        {
            if (dp[i][j] < 0)
                continue;
            ans = max(ans, dp[i][j]);
            for (int d = -1; d <= 1; d++)
            {
                int ni = i - 1, nj = j + d;
                if (ni >= 0 && nj >= 0 && nj < m && a[ni][nj] != 'W')
                {
                    int add = (a[ni][nj] == 'B');
                    dp[ni][nj] = max(dp[ni][nj], dp[i][j] + add);
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans = max(ans, dp[i][j]);
        }
    }

    out << ans << "\n";
}

TEST(SampleTest, GivenExample)
{
    string input =
        "8 10\n"
        ".W...BB...\n"
        "W..B.WB...\n"
        ".B.WB...W.\n"
        ".B..B.....\n"
        "..W...BB..\n"
        "B.B..B.W.W\n"
        ".WB.W...B.\n"
        "..W..BW.B.\n";
    istringstream in(input);
    ostringstream out;
    solve(in, out);
    EXPECT_EQ(out.str(), "5\n");
}

TEST(SimpleTest, NoBlack)
{
    string input =
        "3 3\n"
        "W.W\n"
        "...\n"
        "...";
    istringstream in(input);
    ostringstream out;
    solve(in, out);
    EXPECT_EQ(out.str(), "0\n");
}

TEST(SimpleTest, ImmediateBlock)
{
    string input =
        "2 2\n"
        "WB\n"
        "B.";
    istringstream in(input);
    ostringstream out;
    solve(in, out);
    EXPECT_EQ(out.str(), "0\n");
}

TEST(LargeTest, FullBlack)
{
    int n = 50, m = 50;
    string input = to_string(n) + " " + to_string(m) + "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            input += (i == n - 1 && j == m / 2) ? 'W' : 'B';
        }
        input += '\n';
    }
    istringstream in(input);
    ostringstream out;
    solve(in, out);
    EXPECT_EQ(out.str(), to_string(n - 1) + "\n");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}