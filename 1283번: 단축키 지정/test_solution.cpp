#include "gtest/gtest.h"
#include "solution.cpp"
#include <vector>
#include <string>

TEST(ShortcutAssignmentTest, Sample1)
{
    std::vector<std::string> input = {"New", "Open", "Save", "Save As", "Save All"};
    std::vector<std::string> expected = {"[N]ew", "[O]pen", "[S]ave", "Save [A]s", "Sa[v]e All"};

    ASSERT_EQ(solve_all_options(input), expected);
}

TEST(ShortcutAssignmentTest, Sample2)
{
    std::vector<std::string> input = {"New window", "New file", "Copy", "Undo", "Format", "Font", "Cut", "Paste"};
    std::vector<std::string> expected = {"[N]ew window", "New [f]ile", "[C]opy", "[U]ndo", "F[o]rmat", "Fon[t]", "Cut", "[P]aste"};

    ASSERT_EQ(solve_all_options(input), expected);
}

TEST(ShortcutAssignmentTest, AllFirstLettersTakenThenRule2)
{
    std::vector<std::string> input = {"Apple", "Ant", "Anchor"};
    // A from Apple
    // A from Ant is taken. N from Ant.
    // A from Anchor is taken. N from Anchor is taken. C from Anchor.
    std::vector<std::string> expected = {"[A]pple", "A[n]t", "An[c]hor"};
    ASSERT_EQ(solve_all_options(input), expected);
}

TEST(ShortcutAssignmentTest, NoShortcutPossibleForSome)
{
    std::vector<std::string> input = {"aa", "Aa", "AA"};
    // 'a' from "aa"
    // "Aa": 'A' (a) taken. 'a' (a) taken. -> "Aa"
    // "AA": 'A' (a) taken. 'A' (a) taken. -> "AA"
    std::vector<std::string> expected = {"[a]a", "Aa", "AA"};
    ASSERT_EQ(solve_all_options(input), expected);
}

TEST(ShortcutAssignmentTest, NonAlphabeticFirstChars)
{
    std::vector<std::string> input = {"1st Option", "Option Two"};
    // "1st Option": '1' skip. 's' available. -> "1[s]t Option"
    // "Option Two": 'O' available. -> "[O]ption Two"
    std::vector<std::string> expected = {"1[s]t Option", "[O]ption Two"};
    ASSERT_EQ(solve_all_options(input), expected);
}

TEST(ShortcutAssignmentTest, EmptyInputList)
{
    std::vector<std::string> input = {};
    std::vector<std::string> expected = {};
    ASSERT_EQ(solve_all_options(input), expected);
}

TEST(ShortcutAssignmentTest, CaseSensitivityCheck)
{
    std::vector<std::string> input = {"apple", "Ant"};
    // 'a' from "apple"
    // "Ant": 'A' (a) taken. 'n' available. -> "A[n]t"
    std::vector<std::string> expected = {"[a]pple", "A[n]t"};
    ASSERT_EQ(solve_all_options(input), expected);
}

TEST(ShortcutAssignmentTest, LeadingAndMultipleSpaces)
{
    std::vector<std::string> input = {"  Leading Space", "Next  Option"};
    // "  Leading Space": 'L' available. -> "  [L]eading Space"
    // "Next  Option": 'N' available. ('L' taken) -> "[N]ext  Option"
    std::vector<std::string> expected = {"  [L]eading Space", "[N]ext  Option"};
    ASSERT_EQ(solve_all_options(input), expected);
}

TEST(ShortcutAssignmentTest, AllShortcutsUsed)
{
    // Create 26 options that will use up a-z by first letter
    std::vector<std::string> input;
    std::vector<std::string> expected;
    for (char c = 'a'; c <= 'z'; ++c)
    {
        std::string s(1, c);
        input.push_back(s);
        expected.push_back("[" + s + "]");
    }
    // Add one more option that cannot find a shortcut
    input.push_back("extra");
    expected.push_back("extra");

    ASSERT_EQ(solve_all_options(input), expected);
}

TEST(ShortcutAssignmentTest, Rule2PriorityOverLaterWordFirstLetter)
{
    std::vector<std::string> input = {"first option", "First second"};
    // "first option": 'f' assigned.
    // "First second": 'F' (f) taken. So Rule 1 fails for "First".
    //                 Rule 1 continues to "second", 's' is available. -> "First [s]econd"
    std::vector<std::string> expected = {"[f]irst option", "First [s]econd"};
    ASSERT_EQ(solve_all_options(input), expected);
}

TEST(ShortcutAssignmentTest, Rule1WordByWordNotCharByChar)
{
    std::vector<std::string> input = {"Zip Zap", "Zoom"};
    // "Zip Zap": 'Z' assigned from "Zip".
    // "Zoom": 'Z' (z) taken. Rule 1 fails for "Zoom".
    //         Rule 2 for "Zoom": 'o' available. -> "Z[o]om"
    std::vector<std::string> expected = {"[Z]ip Zap", "Z[o]om"};
    ASSERT_EQ(solve_all_options(input), expected);
}