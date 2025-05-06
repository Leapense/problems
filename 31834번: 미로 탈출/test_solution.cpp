// test_solution.cpp
#include <gtest/gtest.h>
#include <sstream>
#include <string>

// Forward declaration of the solution routine
extern int runSolution(const std::string &input, std::string &output);

int runSolution(const std::string &input, std::string &output)
{
    std::istringstream in(input);
    std::ostringstream out;
    int T;
    in >> T;
    while (T--)
    {
        long long N, S, E;
        in >> N >> S >> E;
        int cost = 0;
        if (S != 1 && E != 1)
            cost++;
        if (S != N && E != N)
            cost++;
        out << cost << "\n";
    }
    output = out.str();
    return 0;
}

TEST(MazeEscapeCost, SampleTests)
{
    {
        std::string in = "3\n5 5 1\n3 1 2\n7 3 5\n";
        std::string out;
        runSolution(in, out);
        EXPECT_EQ(out, "0\n1\n2\n");
    }
}

TEST(MazeEscapeCost, EndpointsAsStartOrEnd)
{
    // If S=1 and E=N or S=N and E=1 => cost=0
    std::string in = "2\n10 1 10\n10 10 1\n";
    std::string out;
    runSolution(in, out);
    EXPECT_EQ(out, "0\n0\n");
}

TEST(MazeEscapeCost, OneEndpointMissing)
{
    // Exactly one of {1,N} is missing from {S,E}
    std::string in = "2\n100 1 50\n100 75 100\n";
    // First case misses N => cost=1; second misses 1 => cost=1
    std::string out;
    runSolution(in, out);
    EXPECT_EQ(out, "1\n1\n");
}

TEST(MazeEscapeCost, NeitherEndpoint)
{
    // Neither endpoint is S or E => cost=2
    std::string in = "2\n50 10 20\n5 2 4\n";
    std::string out;
    runSolution(in, out);
    EXPECT_EQ(out, "2\n2\n");
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}