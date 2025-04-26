#include <gtest/gtest.h>
#include <sstream>
void solve(std::istream &, std::ostream &); // forward

TEST(BeadsIcecream, Sample1)
{
    std::string in =
        "6\n1 3 3 5 5 5\n3\n"
        "1 3\n2 4 4\n"
        "2 3 3\n1 4\n"
        "2 5 5\n1 5\n";
    std::string expected1 = "6\n";
    std::istringstream iss(in);
    std::ostringstream oss;
    solve(iss, oss);
    std::string out = oss.str();
    ASSERT_TRUE(out.substr(0, 2) == "6\n"); // 개수만 고정, 순서는 자유
}

TEST(BeadsIcecream, Sample2)
{
    std::string in =
        "2\n1 1000000000\n1\n"
        "2 1 1000000000\n0\n";
    std::string expected = "0\n";
    std::istringstream iss(in);
    std::ostringstream oss;
    solve(iss, oss);
    ASSERT_EQ(oss.str(), expected);
}