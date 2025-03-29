#include "gtest/gtest.h"
#include <sstream>
#include <vector>
#include <utility>
#include <string>
#include "../cpp/src/main.h"

using namespace std;

class IOTest : public ::testing::Test
{
protected:
    streambuf *origCin;
    streambuf *origCout;
    ostringstream testOutput;
    istringstream testInput;

    virtual void SetUp()
    {
        origCin = cin.rdbuf();
        origCout = cout.rdbuf();
        cin.rdbuf(testInput.rdbuf());
        cout.rdbuf(testOutput.rdbuf());
    }

    virtual void TearDown()
    {
        cin.rdbuf(origCin);
        cout.rdbuf(origCout);
    }
};

TEST_F(IOTest, TestN1)
{
    testInput.str("1\n");
    solve();
    string result = testOutput.str();
    string expected = "1\n1 1\n";
    EXPECT_EQ(result, expected);
}

TEST_F(IOTest, TestN2)
{
    testInput.str("2\n");
    solve();
    string result = testOutput.str();
    istringstream iss(result);
    int M;
    iss >> M;
    EXPECT_EQ(M, 2);

    vector<pair<int, int>> positions;
    int r, c;
    while (iss >> r >> c)
    {
        positions.push_back({r, c});
    }

    EXPECT_EQ(positions.size(), 2);

    EXPECT_EQ(positions[0].first, 1);
    EXPECT_EQ(positions[0].second, 1);
    EXPECT_EQ(positions[1].first, 2);
    EXPECT_EQ(positions[1].second, 1);
}

TEST_F(IOTest, TestN4)
{
    testInput.str("4\n");
    solve();
    string result = testOutput.str();
    istringstream iss(result);
    int M;
    iss >> M;
    EXPECT_EQ(M, 6);

    vector<pair<int, int>> positions;
    int r, c;
    while (iss >> r >> c)
    {
        positions.push_back({r, c});
    }
    EXPECT_EQ(positions.size(), 6);

    for (auto &p : positions)
    {
        EXPECT_GE(p.first, 1);
        EXPECT_LE(p.first, 4);
        EXPECT_GE(p.second, 1);
        EXPECT_LE(p.second, 4);
    }
}

TEST_F(IOTest, TestN10)
{
    testInput.str("10\n");
    solve();
    string result = testOutput.str();
    istringstream iss(result);
    int M;
    iss >> M;
    EXPECT_EQ(M, 18);

    vector<pair<int, int>> positions;
    int r, c;
    while (iss >> r >> c)
    {
        positions.push_back({r, c});
    }
    EXPECT_EQ(positions.size(), 18);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}