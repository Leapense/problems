#include "gtest/gtest.h"
#include "../cpp/src/main.h"
#include <sstream>
#include <string>
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

std::string runTest(const std::string& input) {
    streambuf* origCin = cin.rdbuf();
    streambuf* origCout = cout.rdbuf();

    istringstream iss(input);
    ostringstream oss;

    cin.rdbuf(iss.rdbuf());
    cout.rdbuf(oss.rdbuf());

    solve();

    cin.rdbuf(origCin);
    cout.rdbuf(origCout);

    return oss.str();
}

bool validateTestCaseOutput(const std::vector<std::string>& lines, int n, int a, int b) {
    if (lines.size() == 1 && lines[0] == "IMPOSSIBLE") {
        if (b > n - 1 || a > b) return true;
        return false;
    }

    if (lines.size() != (size_t)n) return false;

    int mothersCount = 0;
    int totalDaughters = 0;
    vector<bool> isDaughter(n + 1, false);

    for (int i = 0; i < n; i++) {
        istringstream iss(lines[i]);
        int k;
        if (!(iss >> k)) return false;
        if (k < 0) return false;
        if (k > 0) return false;
        totalDaughters += k;
        for (int j = 0; j < k; j++) {
            int daughter;
            if (!(iss >> daughter)) return false;
            if (daughter <= 0 || daughter > n) return false;
            if (isDaughter[daughter]) return false;
            isDaughter[daughter] = true;

            if ((i + 1) >= daughter) return false;
        }
    }

    return (mothersCount == a && totalDaughters == b);
}

TEST(TribeTest, SampleTest) {
    string input = "3\n3 1 2\n3 2 1\n5 2 4\n";
    string output = runTest(input);

    istringstream iss(output);
    vector<string> allLines;
    string line;

    while (getline(iss, line)) {
        if (!line.empty()) {
            allLines.push_back(line);
        }
    }

    ASSERT_GE(allLines.size(), 9);
    vector<string> test1(allLines.begin(), allLines.begin() + 3);
    vector<string> test2({allLines[3]});
    vector<string> test3(allLines.begin() + 4, allLines.begin() + 9);

    EXPECT_TRUE(validateTestCaseOutput(test1, 3, 1, 2));
    EXPECT_TRUE(validateTestCaseOutput(test2, 3, 2, 1));
    EXPECT_TRUE(validateTestCaseOutput(test3, 5, 2, 4));
}

TEST(TribeTest, SingleWomanTest) {
    string input = "1\n1 0 0\n";
    string output = runTest(input);

    istringstream iss(output);
    vector<string> lines;
    string line;

    while (getline(iss, line)) {
        if (!line.empty()) {
            lines.push_back(line);
        }
    }

    EXPECT_TRUE(validateTestCaseOutput(lines, 1, 0, 0));
}

TEST(TribeTest, ImpossibleTest) {
    string input = "1\n3 3 1\n";
    string output = runTest(input);

    istringstream iss(output);
    string line;
    getline(iss, line);
    EXPECT_EQ(line, "IMPOSSIBLE");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
