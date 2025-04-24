#include <gtest/gtest.h>
#include <sstream>
#include <string>

std::string Solve(std::istream& in);

TEST(Championship, Sample1) {
    std::string input =
        "3 3\n"
        "1 0 2\n"
        "1 1 1\n";
    std::stringstream ss(input);
    std::string out = Solve(ss);
    std::stringstream os(out);
    std::string ok; os >> ok;
    int cnt; os >> cnt;
    EXPECT_EQ(ok, "YES");
    EXPECT_EQ(cnt, 3);
}

TEST(Championship, Sample2) {
    std::string input =
        "3 3\n"
        "3 3 3\n"
        "3 3 3\n";
    std::stringstream ss(input);
    std::string out = Solve(ss);
    std::stringstream os(out);
    std::string ok; os >> ok;
    int cnt; os >> cnt;
    EXPECT_EQ(ok, "YES");
    EXPECT_EQ(cnt, 9);
}
