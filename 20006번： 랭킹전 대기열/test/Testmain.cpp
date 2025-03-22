#include "gtest/gtest.h"
#include "../cpp/src/main.h"

using namespace std;

TEST(GameSimulationTest, SampleTest)
{
    string input = R"(10 5
10 a
15 b
20 c
25 d
30 e
17 f
18 g
26 h
24 i
28 j
)";

    string expected = R"(Started!
10 a
15 b
20 c
17 f
18 g
Started!
25 d
30 e
26 h
24 i
28 j
)";

    auto output = solve(input);
    EXPECT_EQ(output, expected);
}