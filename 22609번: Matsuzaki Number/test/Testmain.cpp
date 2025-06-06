#include <gtest/gtest.h>
#include "../cpp/src/main.h"

// 기본 테스트 케이스: N = 0일 때
TEST(MatsuzakiNumberTest, BasicTest) {
    EXPECT_EQ(computeM(0, 1), 4);
    EXPECT_EQ(computeM(0, 2), 5);
    EXPECT_EQ(computeM(0, 3), 6);
}

// N = 10인 경우 테스트
TEST(MatsuzakiNumberTest, MoreTests) {
    EXPECT_EQ(computeM(10, 1), 22);
    EXPECT_EQ(computeM(10, 2), 24);
    EXPECT_EQ(computeM(10, 3), 26);
    EXPECT_EQ(computeM(10, 4), 28);
    EXPECT_EQ(computeM(10, 5), 30);
    EXPECT_EQ(computeM(10, 6), 30);
}

// 추가 테스트: N = 11 및 예제 테스트
TEST(MatsuzakiNumberTest, AdvancedTest) {
    EXPECT_EQ(computeM(11, 1), 26);
    EXPECT_EQ(computeM(11, 2), 30);
    EXPECT_EQ(computeM(11, 3), 32);
    EXPECT_EQ(computeM(0, 55), 42);
}

// 큰 입력 케이스 테스트: N = 100000
TEST(MatsuzakiNumberTest, LargeTest) {
    EXPECT_EQ(computeM(100000, 100), 200274);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

