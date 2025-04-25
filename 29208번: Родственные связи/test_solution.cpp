#define UNIT_TEST
#include "solution.cpp"
#include <gtest/gtest.h>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

static vector<string> runWithInput(const string &input)
{
    FILE *in = tmpfile();
    fwrite(input.data(), 1, input.size(), in);
    fflush(in);
    rewind(in);
    FILE *old_stdin = stdin;
    stdin = in;

    ostringstream oss;
    auto *old_buf = cout.rdbuf(oss.rdbuf());

    solve();

    cout.rdbuf(old_buf);
    stdin = old_stdin;
    fclose(in);

    vector<string> lines;
    istringstream iss(oss.str());
    string line;
    while (getline(iss, line))
        lines.push_back(line);
    return lines;
}

TEST(Relation, Sample1)
{
    string in =
        "5\n"
        "10 74 47 77 301\n";
    auto out = runWithInput(in);
    ASSERT_EQ(out.size(), 1);
    EXPECT_EQ(out[0], "4");
}

TEST(Relation, Single)
{
    string in = "1\n5\n";
    auto out = runWithInput(in);
    ASSERT_EQ(out.size(), 1);
    EXPECT_EQ(out[0], "0");
}

TEST(Relation, AllSameDigits)
{
    string in =
        "4\n"
        "111 11 1 1111\n";
    auto out = runWithInput(in);
    ASSERT_EQ(out.size(), 1);
    EXPECT_EQ(out[0], "6");
}

// Google Test 전용 main
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}