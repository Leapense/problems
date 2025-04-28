#include "gtest/gtest.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>

using std::string;
using std::vector;

static string runSolver(const string &input)
{
    const string inFile = "tmp_input.txt";
    const string outFile = "tmp_output.txt";

    {
        std::ofstream ofs(inFile, std::ios::binary);
        ofs << input;
    }

    const string cmd = "./solver_bin < " + inFile + " > " + outFile;
    int ret = std::system(cmd.c_str());
    if (ret != 0)
        return "";

    std::ifstream ifs(outFile, std::ios::binary);
    std::ostringstream oss;
    oss << ifs.rdbuf();
    return oss.str();
}

TEST(VelsasSample, Sample1)
{
    string in = "7 10\n8\n1\n1\n3\n5\n7\n1\n";
    EXPECT_EQ(runSolver(in), "2\n");
}

TEST(VelsasSample, Sample2)
{
    string in = "2 20\n1\n1\n";
    EXPECT_EQ(runSolver(in), "NEPAVYKS\n");
}

TEST(VelsasEdge, OneDayEnough)
{
    string in = "1 5\n10\n";
    EXPECT_EQ(runSolver(in), "1\n");
}

TEST(VelsasEdge, ImpossibleAllZero)
{
    string in = "3 1\n0\n0\n0\n";
    EXPECT_EQ(runSolver(in), "NEPAVYKS\n");
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}