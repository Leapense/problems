#include <gtest/gtest.h>
#include <sstream>
#include <string>

extern int solve(std::istream& in, std::ostream& out);

static std::string run_io(const std::string& input) {
    std::istringstream in(input);
    std::ostringstream out;
    solve(in, out);
    return out.str();
}

TEST(Sample, Provided) {
    std::string inp =
        "6\nKALLE\nMAJA\nSARA\nSVEN\nHUGO\nANNA\n"
        "3\nKALLE ANNA\nMAJA ANNA\nSARA HUGO\n";
    EXPECT_EQ(run_io(inp), "3\n");
}

TEST(Edge, AllConnected) {
    std::string inp =
        "4\nA\nB\nC\nD\n"
        "6\nA B\nB C\nC D\nA C\nB D\nA D\n";
    EXPECT_EQ(run_io(inp), "1\n");
}

TEST(Edge, SingleFriendship) {
    std::string inp =
        "5\nA\nB\nC\nD\nE\n"
        "1\nA B\n";
    EXPECT_EQ(run_io(inp), "4\n");
}
