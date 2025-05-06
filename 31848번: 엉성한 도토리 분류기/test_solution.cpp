#define UNIT_TEST
#include "solution.cpp"
#include <gtest/gtest.h>

TEST(ClassifyAcorns, OfficialSample)
{
    std::vector<int> holes = {5, 6, 1, 4, 9, 2, 8, 10, 3, 7};
    std::vector<int> acorns = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> expect = {1, 1, 1, 1, 1, 2, 2, 5, 5, 5};
    EXPECT_EQ(ClassifyAcorns(holes, acorns), expect);
}

TEST(ClassifyAcorns, SingleElement)
{
    std::vector<int> holes = {1};
    std::vector<int> acorns = {1};
    std::vector<int> expect = {1};
    EXPECT_EQ(ClassifyAcorns(holes, acorns), expect);
}

TEST(ClassifyAcorns, StrictlyIncreasingHoles)
{
    std::vector<int> holes = {1, 2, 3, 4, 5};
    std::vector<int> acorns = {5, 4, 3, 2, 1};
    std::vector<int> expect = {3, 3, 2, 2, 1};
    EXPECT_EQ(ClassifyAcorns(holes, acorns), expect);
}