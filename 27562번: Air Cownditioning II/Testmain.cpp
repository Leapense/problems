#include <gtest/gtest.h>
#include <sstream>
#include <string>
#include <vector>

extern int main(); // 링크 대상: 위 솔루션 객체 파일

static std::string run(const std::string &in)
{
    std::streambuf *cinbuf = std::cin.rdbuf();
    std::streambuf *coutbuf = std::cout.rdbuf();
    std::istringstream input(in);
    std::ostringstream output;
    std::cin.rdbuf(input.rdbuf());
    std::cout.rdbuf(output.rdbuf());
    main();
    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);
    return output.str();
}

TEST(AirCownditioningII, Sample)
{
    std::string in =
        "2 4\n"
        "1 5 2\n"
        "7 9 3\n"
        "2 9 2 3\n"
        "1 6 2 8\n"
        "1 2 4 2\n"
        "6 9 1 5\n";
    EXPECT_EQ(run(in), "10\n");
}

TEST(AirCownditioningII, AllNeeded)
{
    std::string in =
        "1 3\n"
        "1 3 10\n"
        "1 3 3 4\n"
        "1 3 4 5\n"
        "1 3 5 6\n";
    EXPECT_EQ(run(in), "15\n");
}

TEST(AirCownditioningII, NoneNeeded)
{
    std::string in =
        "1 2\n"
        "5 6 0\n"
        "1 10 1 5\n"
        "1 10 2 7\n";
    EXPECT_EQ(run(in), "0\n");
}

#ifndef UNIT_TEST
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif