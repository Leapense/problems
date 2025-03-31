#include <gtest/gtest.h>
#include "../cpp/src/main.h"
#include <sstream>

TEST(SampleTests, TestCase1) {
    stringstream in, out;

    in << "4\n2 5\n4 7\n2 4\n3 6\n";
    solve(in, out);
    EXPECT_EQ(out.str(), "3\n");
}

TEST(SampleTests, TestCase2) {
    stringstream in, out;
    in << "5\n8 100001\n7 100001\n12 100001\n8 100001\n3 100001\n";
    solve(in, out);
    EXPECT_EQ(out.str(), "0\n");
}

TEST(SampleTests, TestCase3) {
    stringstream in, out;
    in << "6\n2 9\n4 8\n6 7\n6 6\n5 7\n2 100001\n";
    solve(in, out);
    EXPECT_EQ(out.str(), "5\n");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
