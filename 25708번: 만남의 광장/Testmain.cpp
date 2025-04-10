#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <algorithm>
#include <string>

#include <gtest/gtest.h>
using namespace std;

void solve(istream &in, ostream &out)
{
    int N, M;
    in >> N >> M;
    vector<vector<int>> grid(N, vector<int>(M));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            in >> grid[i][j];
        }
    }

    vector<int> rowSum(N, 0), colSum(M, 0);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            rowSum[i] += grid[i][j];
            colSum[j] += grid[i][j];
        }
    }

    long long ans = numeric_limits<long long>::min();
    for (int r1 = 0; r1 < N; r1++)
    {
        for (int r2 = r1 + 1; r2 < N; r2++)
        {
            for (int c1 = 0; c1 < M; c1++)
            {
                for (int c2 = c1 + 1; c2 < M; c2++)
                {
                    long long roadSum = static_cast<long long>(rowSum[r1]) + rowSum[r2] + colSum[c1] + colSum[c2] - grid[r1][c1] - grid[r1][c2] - grid[r2][c1] - grid[r2][c2];
                    long long inner = static_cast<long long>(max(0, r2 - r1 - 1)) * max(0, c2 - c1 - 1);
                    long long beauty = roadSum + inner;
                    ans = max(ans, beauty);
                }
            }
        }
    }

    out << ans << "\n";
}

TEST(MeetSquareTest, SampleTest1)
{
    string input = R"(4 4
8 2 1 4
2 3 7 4
4 1 2 3
5 6 9 1
)";
    string expected = "58\n";

    stringstream ss(input);
    stringstream os;
    solve(ss, os);
    EXPECT_EQ(os.str(), expected);
}

TEST(MeetSquareTest, SampleTest2)
{
    string input = R"(3 6
-9 -1 -3 13 -8 -14
-6 -20 -15 0 14 4
-6 7 18 13 14 4
)";
    string expected = "46\n";

    stringstream ss(input);
    stringstream os;
    solve(ss, os);
    EXPECT_EQ(os.str(), expected);
}

TEST(MeetSquareTest, SampleTest3)
{
    string input = R"(10 10
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
)";
    string expected = "100\n";

    stringstream ss(input);
    stringstream os;

    solve(ss, os);
    EXPECT_EQ(os.str(), expected);
}

#ifndef UNIT_TEST
int main(int argc, char **argv)
{
    if (argc == 1)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        solve(cin, cout);
        return 0;
    }

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#else
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif