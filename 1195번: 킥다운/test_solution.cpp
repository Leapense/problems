#include "gtest/gtest.h"
#include <string>
#include <algorithm>

int calculate_min_length(const std::string &s1, const std::string &s2)
{
    int len1 = s1.length();
    int len2 = s2.length();

    if (len1 == 0)
        return len2;
    if (len2 == 0)
        return len1;

    int min_total_length = len1 + len2;

    for (int shift = 1 - len2; shift <= len1 - 1; ++shift)
    {
        bool possible_to_mesh = true;
        for (int i2 = 0; i2 < len2; ++i2)
        {
            int s1_equivalent_idx = shift + i2;
            if (s1_equivalent_idx >= 0 && s1_equivalent_idx < len1)
            {
                if (s1[s1_equivalent_idx] == '2' && s2[i2] == '2')
                {
                    possible_to_mesh = false;
                    break;
                }
            }
        }

        if (possible_to_mesh)
        {
            int combined_assembly_start_coord = std::min(0, shift);
            int combined_assembly_end_coord_plus_1 = std::max(len1, shift + len2);
            int current_length = combined_assembly_end_coord_plus_1 - combined_assembly_start_coord;
            min_total_length = std::min(min_total_length, current_length);
        }
    }

    return min_total_length;
}

TEST(KickdownTest, Sample1)
{
    EXPECT_EQ(calculate_min_length("2112112112", "2212112"), 10);
}

TEST(KickdownTest, Sample2)
{
    EXPECT_EQ(calculate_min_length("222", "222"), 6);
}

TEST(KickdownTest, PerfectFitShorterInsideLonger)
{
    EXPECT_EQ(calculate_min_length("121", "2"), 3);
}

TEST(KickdownTest, AllOnesS1AllowsAnyS2)
{
    // s1="11111", s2="212". s2 fits inside s1. Length of s1 is 5.
    EXPECT_EQ(calculate_min_length("11111", "212"), 5);
}

TEST(KickdownTest, AllOnesS2AllowsAnyS1)
{
    // s1="212", s2="11111". s1 fits inside s2. Length of s2 is 5.
    EXPECT_EQ(calculate_min_length("212", "11111"), 5);
}

TEST(KickdownTest, IdenticalStringsPartialOverlap)
{
    // s1="121", s2="121"
    // Shift 0: clash at s1[1],s2[1] ('2' and '2')
    // Shift 1: s1: 121, s2:  121. Overlap: s1[1]/s2[0] ('2'/'1'), s1[2]/s2[1] ('1'/'2'). OK.
    // Length: max(3, 1+3) - min(0,1) = 4-0 = 4.
    EXPECT_EQ(calculate_min_length("121", "121"), 4);

    // s1="12", s2="12"
    // Shift 1: s1: 12, s2:  12. Overlap: s1[1]/s2[0] ('2'/'1'). OK.
    // Length: max(2, 1+2) - min(0,1) = 3-0 = 3.
    EXPECT_EQ(calculate_min_length("12", "12"), 3);
}

TEST(KickdownTest, SingleCharStrings)
{
    EXPECT_EQ(calculate_min_length("1", "1"), 1);
    EXPECT_EQ(calculate_min_length("1", "2"), 1);
    EXPECT_EQ(calculate_min_length("2", "1"), 1);
    EXPECT_EQ(calculate_min_length("2", "2"), 2); // Clash if overlapped, so side-by-side
}

TEST(KickdownTest, S2LongerThanS1AndFits)
{
    EXPECT_EQ(calculate_min_length("11", "212"), 3); // s1 fits in s2
}

TEST(KickdownTest, S2LongerThanS1NoClash)
{
    // s1="11", s2="22"
    // Shift 0: s1[0]/s2[0] ('1'/'2'), s1[1]/s2[1] ('1'/'2'). OK. Length = 2.
    EXPECT_EQ(calculate_min_length("11", "22"), 2);
}

TEST(KickdownTest, MaxLengthStringsNoOverlapPossible)
{
    std::string s_a(100, '2');
    std::string s_b(100, '2');
    EXPECT_EQ(calculate_min_length(s_a, s_b), 200);
}

TEST(KickdownTest, MaxLengthStringsCanOverlap)
{
    std::string s_a(100, '1');                      // All grooves
    std::string s_b(50, '2');                       // All teeth
    EXPECT_EQ(calculate_min_length(s_a, s_b), 100); // s_b fits entirely within s_a

    std::string s_c(50, '2');                       // All teeth
    std::string s_d(100, '1');                      // All grooves
    EXPECT_EQ(calculate_min_length(s_c, s_d), 100); // s_c fits entirely within s_d
}

TEST(KickdownTest, InterleavePerfectly)
{
    // Example from problem description's visual style
    // s1 = 21212
    // s2 = 12121
    // They interleave perfectly at shift 0. Length 5.
    EXPECT_EQ(calculate_min_length("21212", "12121"), 5);
}

TEST(KickdownTest, ShortS2InsideLongS1NoClash)
{
    // s1 = 2111111112 (len 10)
    // s2 = 121 (len 3)
    // s2 can fit inside s1, e.g., s1[1..3] = "111" can mesh with "121"
    // Shift = 1: s1[1]/s2[0] ('1'/'1'), s1[2]/s2[1] ('1'/'2'), s1[3]/s2[2] ('1'/'1'). OK.
    // Length = max(10, 1+3) - min(0,1) = 10.
    EXPECT_EQ(calculate_min_length("2111111112", "121"), 10);
}

TEST(KickdownTest, EmptyStrings)
{
    EXPECT_EQ(calculate_min_length("", ""), 0);
    EXPECT_EQ(calculate_min_length("123", ""), 3);
    EXPECT_EQ(calculate_min_length("", "123"), 3);
}