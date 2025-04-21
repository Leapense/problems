#include "어깨동무.cpp"
#include <gtest/gtest.h>

using namespace std;

TEST(ShoulderLinkTest, Sample1)
{
    vector<int> h = {1, 5, 2, 4, 3};
    EXPECT_EQ(computeMinH(5, 3, h), 2);
}

TEST(ShoulderLinkTest, SinglePerson)
{
    vector<int> h = {100};
    EXPECT_EQ(computeMinH(1, 0, h), 0);
}

TEST(ShoulderLinkTest, NoOneTired)
{
    vector<int> h = {1, 2, 3, 4, 5};
    EXPECT_EQ(computeMinH(5, 4, h), 0);
}

#ifdef UNIT_TEST
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif