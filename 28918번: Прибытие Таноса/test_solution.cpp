#include <gtest/gtest.h>
#include <sstream>
#include <string>

// solution.cpp 안에 정의된 함수 시그니처
std::string Solve(std::istream& in);

TEST(ThanosArrival, Sample) {
    std::istringstream in("0001 01 01\n");
    EXPECT_EQ(Solve(in),
R"(16
0001 01 01
0001 01 10
0001 10 01
0001 10 10
0010 01 01
0010 01 10
0010 10 01
0010 10 10
0100 01 01
0100 01 10
0100 10 01
0100 10 10
1000 01 01
1000 01 10
1000 10 01
1000 10 10
)");
}

TEST(ThanosArrival, LeapYearContainsOriginal) {
    std::istringstream in("2012 02 29\n");
    std::stringstream out(Solve(in));
    int n; out >> n;
    std::string line, original = "2012 02 29";
    bool found = false;
    std::getline(out, line);          // 개행 소비
    while (std::getline(out, line))
        if (line == original) { found = true; break; }
    EXPECT_TRUE(found);
}

