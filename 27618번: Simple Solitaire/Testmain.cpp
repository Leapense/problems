#include <gtest/gtest.h>
#include <vector>
#include <string>

// forward declaration from main.cpp
std::vector<std::string> simpleSolitaire(const std::vector<std::string> &);

TEST(SimpleSolitaireTest, Sample1)
{
    std::vector<std::string> deck = {
        "TC", "2C", "6C", "TS", "KC", "QS", "QC", "3C", "KD", "8D", "JH", "JS", "KH",
        "5D", "JD", "2S", "8S", "AS", "9S", "3D", "5H", "9C", "AH", "4D", "4C", "KS",
        "JC", "4S", "7S", "6D", "2H", "7C", "8C", "7D", "AD", "7H", "TH", "2D", "QH",
        "8H", "9H", "5C", "TD", "3S", "6H", "3H", "QD", "5S", "9D", "4H", "6S", "AC"};
    auto res = simpleSolitaire(deck);
    std::vector<std::string> expected = {"3S", "9D"};
    EXPECT_EQ(res, expected);
}

#ifdef UNIT_TEST
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif