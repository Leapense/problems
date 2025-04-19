#include <gtest/gtest.h>
#include <utility>

std::pair<long long, long long> split_sum(long long n);

long long digit_sum(long long v)
{
    long long s = 0;
    while (v)
    {
        s += v % 10;
        v /= 10;
    }
    return s;
}

TEST(SumOfTwoNumbers, Samples)
{
    std::vector<long long> input = {1, 161, 67, 1206, 19};
    std::vector<std::pair<long long, long long>> expect = {
        {1, 0}, {67, 94}, {60, 7}, {1138, 68}, {14, 5}};
    for (size_t i = 0; i < input.size(); ++i)
        EXPECT_EQ(split_sum(input[i]), expect[i]);
}

TEST(SumOfTwoNumbers, Random)
{
    for (long long n = 1; n <= 1'000'000; ++n)
    {
        auto [x, y] = split_sum(n);
        ASSERT_EQ(x + y, n);
        long long dx = digit_sum(x), dy = digit_sum(y);
        ASSERT_LE(std::llabs(dx - dy), 1);
    }
}

TEST(SumOfTwoNumbers, Edge)
{
    auto p1 = split_sum(1000000000LL);
    EXPECT_EQ(p1.first + p1.second, 1000000000LL);
    EXPECT_LE(std::llabs(digit_sum(p1.first) - digit_sum(p1.second)), 1);
}

#ifdef UNIT_TEST
int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif