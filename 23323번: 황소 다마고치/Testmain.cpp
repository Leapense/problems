#include <iostream>
#include <bit>
#include <gtest/gtest.h>

unsigned long long calcDays(unsigned long long n, unsigned long long m) {
    unsigned long long days_without_food = std::bit_width(n);
    return days_without_food + m;
}

TEST(HwangsoTest, SampleTest1) {
    EXPECT_EQ(calcDays(7ULL, 1ULL), 4ULL);
}

TEST(HwangsoTest, SampleTest2) {
    EXPECT_EQ(calcDays(8589934591ULL, 1ULL), 34ULL);
}

TEST(HwangsoTest, EdgeTest) {
    EXPECT_EQ(calcDays(1ULL, 1ULL), 2ULL);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
