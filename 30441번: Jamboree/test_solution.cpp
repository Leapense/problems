#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

using namespace std;

extern int main();

string runTest(const string &input)
{
    auto cin_buf = cin.rdbuf();
    auto cout_buf = cout.rdbuf();

    stringstream in(input), out;
    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());

    main();

    cin.rdbuf(cin_buf);
    cout.rdbuf(cout_buf);
    return out.str();
}

TEST(JamboreeTest, Sample1)
{
    EXPECT_EQ(runTest("3 4\n10 10 10\n"), "10");
}

TEST(JamboreeTest, Sample2)
{
    EXPECT_EQ(runTest("5 4\n9 12 3 9 10\n"), "12");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}