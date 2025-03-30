#include "gtest/gtest.h"
#include <sstream>
#include "../cpp/src/main.h"

TEST(EprestanovkaTest, SampleInput1) {
    std::string input = "4 2\n1 4 3 2\n4 1\n3 4\n";
    std::string expected_output = "Yes\nNo\n";

    std::istringstream iss(input);
    std::ostringstream oss;

    solve(iss, oss);

    EXPECT_PRED2([](const std::string &a, const std::string &b) {
            return a == b;
    }, oss.str(), expected_output);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
