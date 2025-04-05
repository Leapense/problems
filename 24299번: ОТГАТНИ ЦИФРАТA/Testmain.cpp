#include <iostream>
#include <string>
#include <set>
#include <cctype>
#include <stdexcept>
#include <sstream>
#include <cstdlib>
#include <gtest/gtest.h>

using namespace std;

bool isValidNumber(const string &s) {
    int n = s.size();
    if (n == 0) return false;

    int start = 0;

    if (s[0] == '-') {
        if (n == 1) return false;
        start = 1;
    }

    if (s[start] == '0' && n - start > 1) return false;

    return true;
}

long long toLL(const string &s) {
    return stoll(s);
}

string solveEquation(const string &equation) {
    set<char> usedDigits;
    for (char c : equation) {
        if (isdigit(c)) {
            usedDigits.insert(c);
        }
    }

    for (int cand = 0; cand <= 9; cand++) {
        char candidate = '0' + cand;
        if (usedDigits.find(candidate) != usedDigits.end()) {
            continue;
        }
        string replaced;

        for (char c : equation) {
            if (c == '?') replaced.push_back(candidate);
            else replaced.push_back(c);
        }
        size_t startPos = (replaced[0] == '-' ? 1 : 0);
        size_t posOp = replaced.find_first_of("+-*", startPos);
        if (posOp == string::npos) continue;

        char op = replaced[posOp];

        string left = replaced.substr(0, posOp);
        size_t posEqual = replaced.find('=', posOp);
        if (posEqual == string::npos) continue;

        string middle = replaced.substr(posOp + 1, posEqual - posOp - 1);
        string right = replaced.substr(posEqual + 1);

        if (!isValidNumber(left) || !isValidNumber(middle) || !isValidNumber(right)) continue;


        long long num1, num2, num3;
        try 
        {
            num1 = toLL(left);
            num2 = toLL(middle);
            num3 = toLL(right);
        } catch (...) {
            continue;
        }

        long long res = 0;

        if (op == '+') res = num1 + num2;
        else if (op == '-') res = num1 - num2;
        else if (op == '*') res = num1 * num2;
        else continue;

        if (res == num3) {
            return string(1, candidate);
        }
    }

    return "mistake";
}

TEST(GuessDigitTest, SampleTest1) {
    EXPECT_EQ(solveEquation("5+?=7"), "2");
}

TEST(GuessDigitTest, SampleTest2) {
    EXPECT_EQ(solveEquation("789*?54=51?00?"), "6");
}

TEST(GuessDigitTest, SampleTest3) {
    EXPECT_EQ(solveEquation("-8?*-1=8?"), "0");
}

TEST(GuessDigitTest, SampleTest4) {
    EXPECT_EQ(solveEquation("51-5?=?"), "mistake");
}

TEST(GuessDigitTest, SampleTest5) {
    EXPECT_EQ(solveEquation("??*??=435?"), "6");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
