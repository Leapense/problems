// test_solution.cpp — C++26 + GoogleTest
// Sample tests for Alloys problem

#include <gtest/gtest.h>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <string>

// Helper that runs the compiled solution binary with given input and returns its stdout
static std::string run_io_test(const std::string &input)
{
    const char *exe = "./solution"; // compiled target name
    char in_name[] = "/tmp/alloys_inXXXXXX";
    char out_name[] = "/tmp/alloys_outXXXXXX";
    int in_fd = mkstemp(in_name);
    int out_fd = mkstemp(out_name);
    {
        std::ofstream ofs(in_name);
        ofs << input;
    }
    std::string cmd = std::string(exe) + " < " + in_name + " > " + out_name;
    std::system(cmd.c_str());
    std::ostringstream ss;
    {
        std::ifstream ifs(out_name);
        ss << ifs.rdbuf();
    }
    unlink(in_name);
    unlink(out_name);
    return ss.str();
}

TEST(AlloysSamples, Sample1)
{
    std::string input = R"(5
A 1.0 5.0
B 2.0 2.0
C 3.0 4.0
D 5.0 2.0
E 4.0 1.0
)";
    EXPECT_EQ(run_io_test(input), "A C D\n");
}

TEST(AlloysSamples, Sample2)
{
    std::string input = R"(5
4 3.0 4.0
13 1.0 1.0
32 3.0 6.0
111 5.0 5.0
23 1.0 4.0
)";
    EXPECT_EQ(run_io_test(input), "111 32\n");
}

// Extra stress‑case: descending dominance chain
TEST(AlloysEdge, LargeDescending)
{
    std::ostringstream in;
    const int n = 1000;
    in << n << '\n';
    for (int i = 0; i < n; ++i)
    {
        in << 'P' << i << ' ' << (n - i) << ".0 " << (n - i) << ".0\n";
    }
    std::ostringstream expect;
    for (int i = 0; i < n; ++i)
    {
        expect << 'P' << i;
        if (i + 1 < n)
            expect << ' ';
    }
    expect << '\n';
    EXPECT_EQ(run_io_test(in.str()), expect.str());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
