#define UNIT_TEST
#include "solution.cpp"
#include <gtest/gtest.h>
#include <sstream>

using namespace std;

string run(const string &in)
{
    istringstream iss(in);
    ostringstream oss;
    streambuf *cinbuf = cin.rdbuf();
    streambuf *coutbuf = cout.rdbuf();
    cin.rdbuf(iss.rdbuf());
    cout.rdbuf(oss.rdbuf());
    main();
    cin.rdbuf(cinbuf);
    cout.rdbuf(coutbuf);
    return oss.str();
}

TEST(Sample1, Provided)
{
    string in = "4\n4 2 1 3\n";
    EXPECT_EQ(run(in), "YES\n");
}

TEST(Sample2, Provided)
{
    string in = "2\n4 3\n";
    EXPECT_EQ(run(in), "NO\n");
}

TEST(N2Yes, Ascending)
{
    string in = "2\n1 5\n";
    EXPECT_EQ(run(in), "YES\n");
}

TEST(N3Decreasing, AlwaysYes)
{
    string in = "3\n5 4 3\n";
    EXPECT_EQ(run(in), "YES\n");
}

TEST(RandomLarge, AlwaysYes)
{
    string in = "100000\n";
    for (int i = 0; i < 100000; ++i)
        in += "1 ";
    in.back() = '\n';
    EXPECT_EQ(run(in), "YES\n");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
