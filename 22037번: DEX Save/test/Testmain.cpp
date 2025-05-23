#include "../cpp/src/main.h"
#include <gtest/gtest.h>
#include <sstream>

TEST(DexSaveTest, SampleTest1) {
    std::string input = "12 4\nstraight\n0\n";
    std::string expected = "0.650000000\n";

    std::stringstream in(input);
    std::stringstream out;
    solve(in, out);

    EXPECT_EQ(out.str(), expected);
}

TEST(DexSaveTest, SampleTest2) {
    std::string input = "10 3\nadvantage\n0\n";
    std::string expected = "0.910000000\n";

    std::stringstream in(input);
    std::stringstream out;
    solve(in, out);

    EXPECT_EQ(out.str(), expected);
}

TEST(DexSaveTest, SampleTest3) {
    std::string input = "20 7\ndisadvantage\n2 +d6 -d4\n";
    std::string expected = "0.212916667\n";

    std::stringstream in(input);
    std::stringstream out;
    solve(in, out);

    EXPECT_EQ(out.str(), expected);
}

TEST(DexSaveTest, NegativeModifier) {
    std::string input = "15 -2\nstraight\n0\n";
    std::string expected = "0.200000000\n";

    std::stringstream in(input);
    std::stringstream out;
    solve(in, out);

    EXPECT_EQ(out.str(), expected);
}

TEST(DexSaveTest, MultipleBonusDice) {
    std::string input = "18 3\nstraight\n2 +d4 +d4\n";
    std::stringstream in(input);
    std::stringstream out;
    solve(in, out);

    double prob = stod(out.str());
    EXPECT_GE(prob, 0.0);
    EXPECT_LE(prob, 1.0);
}

TEST(DexSaveTest, DisadvantageNoBonus) {
    std::string input = "14 2\ndisadvantage\n0\n";
    std::stringstream in(input);
    std::stringstream out;
    solve(in, out);

    double prob = stod(out.str());
    EXPECT_GE(prob, 0.0);
    EXPECT_LE(prob, 1.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
