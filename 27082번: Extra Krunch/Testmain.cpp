#include <gtest/gtest.h>
#include <sstream>
#include <string>

extern std::string krunch(const std::string &);

TEST(KrunchTest, Sample)
{
    std::string in = "NOW IS THE TIME FOR ALL GOOD MEN TO COME TO THE AID OF THEIR COUNTRY.";
    std::string expect = "NW S TH M FR L GD C Y.";
    EXPECT_EQ(krunch(in), expect);
}

TEST(KrunchTest, EdgeCases)
{
    EXPECT_EQ(krunch("AEIOU"), "");
    EXPECT_EQ(krunch("MISSISSIPPI"), "MSP");
    EXPECT_EQ(krunch("  A B C  ?"), "B C?");
    EXPECT_EQ(krunch("AAAA BBBB CCCC"), "B C");
}