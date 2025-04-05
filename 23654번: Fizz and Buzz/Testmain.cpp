#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <gtest/gtest.h>
using namespace std;

void solve(istream& in, ostream& out) {
    int n;
    in >> n;

    string result;
    result.resize(n);

    for (int i = 0; i < n; ++i) {
        int a;
        in >> a;

        if (a % 3 == 0 && a % 5 != 0) {
            result[i] = 'F';
        } else if (a % 5 == 0 && a % 3 != 0) {
            result[i] = 'B';
        } else if (a % 15 == 0) {
            result[i] = 'B';
        }
    }

    out << result << "\n";
}

TEST(FizzBuzzTest, SampleTestCase1) {
    string input = "10\n3216 7770 8448 3438 6255 330 405 5835 6140 7475\n";
    istringstream iss(input);
    ostringstream oss;

    solve(iss, oss);

    string expected = "FBFFBBFBBB\n";
    EXPECT_EQ(oss.str(), expected);
}

TEST(FizzBuzzTest, OnlyFizz) {
    string input = "5\n3 6 9 12 18\n";
    istringstream iss(input);
    ostringstream oss;

    solve(iss, oss);

    string expected = "FFFFF\n";
    EXPECT_EQ(oss.str(), expected);
}

TEST(FizzBuzzTest, OnlyBuzz) {
    string input = "5\n5 10 20 25 35\n";
    istringstream iss(input);
    ostringstream oss;

    solve(iss, oss);

    string expected = "BBBBB\n";
    EXPECT_EQ(oss.str(), expected);
}

TEST(FizzBuzzTest, AmbiguousCase) {
    string input = "4\n15 30 45 60\n";
    istringstream iss(input);
    ostringstream oss;

    solve(iss, oss);

    string expected = "BBBB\n";
    EXPECT_EQ(oss.str(), expected);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
