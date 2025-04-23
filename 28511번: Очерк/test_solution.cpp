#include <gtest/gtest.h>
#include <sstream>

using namespace std;

void solve(istream &cin, ostream &cout);

TEST(DrawPattern, Sample1)
{
    string in =
        "5 5\n"
        ".....\n"
        "..***\n"
        "..***\n"
        "..***\n"
        ".....\n";
    istringstream cin(in);
    ostringstream cout;
    solve(cin, cout);
    EXPECT_EQ("YES", cout.str());
}

TEST(DrawPattern, Sample2)
{
    string in =
        "5 5\n"
        ".....\n"
        ".....\n"
        "*....\n"
        ".*...\n"
        "*.*..\n";
    istringstream cin(in);
    ostringstream cout;
    solve(cin, cout);
    EXPECT_EQ("YES", cout.str());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}