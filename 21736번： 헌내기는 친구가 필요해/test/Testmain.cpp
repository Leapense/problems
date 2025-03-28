#include "gtest/gtest.h"
#include "../cpp/src/main.h"
#include <vector>
#include <string>

TEST(ExampleTest, Sample1)
{
    int N = 3, M = 5;
    std::vector<std::string> campus = {"OOOPO", "OIOOX", "OOOXP"};
    EXPECT_EQ(solveCampus(N, M, campus), "1");
}
TEST(ExampleTest, Sample2)
{
    int N = 3, M = 3;
    std::vector<std::string> campus = {"IOX", "OXP", "XPP"};
    EXPECT_EQ(solveCampus(N, M, campus), "TT");
}
TEST(AdditionalTest, SingleCellI)
{
    int N = 1, M = 1;
    std::vector<std::string> campus = {"I"};
    EXPECT_EQ(solveCampus(N, M, campus), "TT");
}
TEST(AdditionalTest, AllPeople)
{
    int N = 3, M = 3;
    std::vector<std::string> campus = {"IPP", "PPP", "PPP"};
    EXPECT_EQ(solveCampus(N, M, campus), "8");
}
TEST(AdditionalTest, BlockedPath)
{
    int N = 3, M = 3;
    std::vector<std::string> campus = {"IXP", "XXX", "PXP"};
    EXPECT_EQ(solveCampus(N, M, campus), "TT");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}