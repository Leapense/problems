#include <gtest/gtest.h>
#include <sstream>
#include "solution.cpp"
using namespace std;

string runCase(const string& input){
    istringstream in(input);
    ostringstream out;
    solve(in,out);
    return out.str();
}

TEST(Sample, Provided){
    string input =
        "4 5\n"
        "0 1 1 2\n"
        "1 2 4\n"
        "1 4 2\n"
        "2 3 2\n"
        "3 1\n"
        "3 2\n";
    string expect = "2\n0\n";
    EXPECT_EQ(runCase(input), expect);
}

TEST(Custom, TeacherGroupEffect){
    string input =
        "4 4\n"
        "0 1 1 2\n"
        "1 4 2\n"
        "3 2\n"
        "2 2 1\n"
        "3 2\n";
    string expect = "1\n0\n";
    EXPECT_EQ(runCase(input), expect);
}
