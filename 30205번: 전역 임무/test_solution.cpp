// test.cpp
#include "gtest/gtest.h"
#include <sstream>
#include <string>

extern int main(int, char **); // solve.cpp에 main 그대로 사용

std::string run_io(const std::string &in)
{
    std::stringstream ss_in(in), ss_out;
    std::streambuf *cinbuf = std::cin.rdbuf(ss_in.rdbuf());
    std::streambuf *coutbuf = std::cout.rdbuf(ss_out.rdbuf());

    main(0, nullptr);

    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);
    return ss_out.str();
}

TEST(Sample, Possible)
{
    std::string input =
        "3 5 10\n"
        "30 7 -1 0 10\n"
        "10 10 10 10 1\n"
        "200 -1 0 0 0\n";
    EXPECT_EQ(run_io(input), "1\n");
}

TEST(Sample, Impossible)
{
    std::string input =
        "3 5 1\n"
        "30 7 -1 0 10\n"
        "10 10 10 10 1\n"
        "200 -1 0 0 0\n";
    EXPECT_EQ(run_io(input), "0\n");
}

// 추가 edge-case
TEST(Edge, OnlyItems)
{
    std::string input =
        "2 3 5\n"
        "-1 -1 -1\n"
        "-1 -1 -1\n";
    EXPECT_EQ(run_io(input), "1\n");
}

TEST(Edge, NeedAllItemsExactly)
{
    std::string input =
        "1 4 3\n"
        "10 20 -1 -1\n"; // 3→6(아이템)→못이김, 3→아이템→6→아이템→26 ⇒ 성공
    EXPECT_EQ(run_io(input), "1\n");
}
