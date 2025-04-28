#include <gtest/gtest.h>
#include <sstream>

// solve 함수를 외부에서 선언
void solve(std::istream &cin, std::ostream &cout);

TEST(CakeTest, Sample1)
{
    std::string input =
        "swi's cake is missing!\n"
        "5\n"
        "dongho\n"
        "potato\n"
        "cake\n"
        "bumin\n"
        "dhyang\n"
        "5\n"
        "dongho\n"
        "dongho\n"
        "dongho\n"
        "dongho\n"
        "dongho\n";
    std::istringstream iss(input);
    std::ostringstream oss;
    solve(iss, oss);
    EXPECT_EQ(oss.str(), "dongho\n");
}

TEST(CakeTest, UnwitnessedSingle)
{
    std::string input =
        "swi's cake is missing!\n"
        "3\n"
        "alice\n"
        "bob\n"
        "charlie\n"
        "2\n"
        "alice\n"
        "alice\n";
    std::istringstream iss(input);
    std::ostringstream oss;
    solve(iss, oss);
    // bob과 charlie 중 목격 안 된 사람이 둘이지만, 단 한 명 규칙이 안 성립 -> bumin, cake, lawyer 없음 -> lex min -> bob
    EXPECT_EQ(oss.str(), "bob\n");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}