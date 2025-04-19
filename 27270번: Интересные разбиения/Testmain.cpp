#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>

// Function to capture stdout
std::string capture_stdout(std::function<void()> func)
{
    std::stringstream ss;
    std::streambuf *old_stdout = std::cout.rdbuf(ss.rdbuf());
    func();
    std::cout.rdbuf(old_stdout);
    return ss.str();
}

// Helper function to parse output lines into a set of strings
std::set<std::string> parse_output(const std::string &output, int n)
{
    std::set<std::string> partitions;
    std::stringstream ss(output);
    std::string line;
    std::string prefix = std::to_string(n) + "=";

    while (std::getline(ss, line))
    {
        if (line.rfind(prefix, 0) == 0)
        { // Check if line starts with "n="
            partitions.insert(line.substr(prefix.length()));
        }
    }
    return partitions;
}

// The function to test (needs to be accessible)
extern void solve(int remaining_sum, int min_allowed_value, std::vector<int> &current_partition, int original_n);

// Wrapper function to call solve and capture output
void solve_and_capture(int n)
{
    std::vector<int> current_partition;
    solve(n, 1, current_partition, n);
}

TEST(InterestingPartitionsTest, HandlesN1)
{
    int n = 1;
    std::string output = capture_stdout([&]()
                                        { solve_and_capture(n); });
    std::set<std::string> actual_partitions = parse_output(output, n);
    std::set<std::string> expected_partitions = {"1"};
    EXPECT_EQ(actual_partitions, expected_partitions);
}

TEST(InterestingPartitionsTest, HandlesN2)
{
    int n = 2;
    std::string output = capture_stdout([&]()
                                        { solve_and_capture(n); });
    std::set<std::string> actual_partitions = parse_output(output, n);
    std::set<std::string> expected_partitions = {"2"};
    EXPECT_EQ(actual_partitions, expected_partitions);
}

TEST(InterestingPartitionsTest, HandlesN3)
{
    int n = 3;
    std::string output = capture_stdout([&]()
                                        { solve_and_capture(n); });
    std::set<std::string> actual_partitions = parse_output(output, n);
    std::set<std::string> expected_partitions = {"3"};
    EXPECT_EQ(actual_partitions, expected_partitions);
}

TEST(InterestingPartitionsTest, HandlesN4)
{
    int n = 4;
    std::string output = capture_stdout([&]()
                                        { solve_and_capture(n); });
    std::set<std::string> actual_partitions = parse_output(output, n);
    std::set<std::string> expected_partitions = {"4", "1+3"};
    EXPECT_EQ(actual_partitions, expected_partitions);
}

TEST(InterestingPartitionsTest, HandlesN5)
{
    int n = 5;
    std::string output = capture_stdout([&]()
                                        { solve_and_capture(n); });
    std::set<std::string> actual_partitions = parse_output(output, n);
    std::set<std::string> expected_partitions = {"5", "1+4"}; // 2+3 is not interesting
    EXPECT_EQ(actual_partitions, expected_partitions);
}

TEST(InterestingPartitionsTest, HandlesN9Sample)
{
    int n = 9;
    std::string output = capture_stdout([&]()
                                        { solve_and_capture(n); });
    std::set<std::string> actual_partitions = parse_output(output, n);
    std::set<std::string> expected_partitions = {"1+3+5", "1+8", "2+7", "3+6", "9"};
    EXPECT_EQ(actual_partitions, expected_partitions);
}

TEST(InterestingPartitionsTest, HandlesN10)
{
    int n = 10;
    std::string output = capture_stdout([&]()
                                        { solve_and_capture(n); });
    std::set<std::string> actual_partitions = parse_output(output, n);
    std::set<std::string> expected_partitions = {"10", "1+3+6", "1+8", "2+6", "2+7", "3+7", "4+6"};
    EXPECT_EQ(actual_partitions, expected_partitions);
}

// Add more tests for larger N if needed, up to 80
// Note: Manually determining expected partitions for large N is tedious.
// For competitive programming, the sample case is often sufficient,
// or one might generate expected output using a known correct implementation.
// For a robust test suite, one might generate test cases and expected outputs
// programmatically or use a reference implementation.

// Example for N=15 (a bit larger)
TEST(InterestingPartitionsTest, HandlesN15)
{
    int n = 15;
    std::string output = capture_stdout([&]()
                                        { solve_and_capture(n); });
    std::set<std::string> actual_partitions = parse_output(output, n);
    std::set<std::string> expected_partitions = {
        "15", "1+3+11", "1+4+10", "1+5+9", "1+6+8", "1+14",
        "2+4+9", "2+5+8", "2+6+7", "2+13",
        "3+5+7", "3+12",
        "4+11",
        "5+10",
        "6+9",
        "7+8"};
    EXPECT_EQ(actual_partitions, expected_partitions);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}