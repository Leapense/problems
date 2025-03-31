#include "gtest/gtest.h"
#include "../cpp/src/main.h"

TEST(TautologyTest, SampleCases) {
    EXPECT_EQ(processLine("-(a+b)=(-a*-b)"), "YES");
    EXPECT_EQ(processLine("(a->b)=(-a+b)"), "YES");
    EXPECT_EQ(processLine("((a*T)+b)=(-c+(a*-b))"), "NO");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
