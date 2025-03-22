#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;

// The solution function.  Modified to take istream& and ostream&.
void solve(istream &in, ostream &out)
{
    ios::sync_with_stdio(false);
    // cin.tie(nullptr);  // Not needed when using custom streams

    int n, m;
    in >> n >> m;
    vector<int> f(m);
    for (int i = 0; i < m; i++)
    {
        in >> f[i];
    }

    if (m <= 1)
    {
        out << 0 << "\n";
        return;
    }

    auto getEdges = [&](const set<int> &allowed) -> set<pair<int, int>>
    {
        set<pair<int, int>> edges;
        for (int i = 0; i < m - 1; i++)
        {
            if (allowed.find(f[i + 1]) == allowed.end())
            {
                edges.insert({f[i + 1], f[i]});
            }
        }
        return edges;
    };

    set<int> allowed1 = {f[0]};
    auto edges1 = getEdges(allowed1);
    size_t bestCost = edges1.size();
    set<int> bestAllowed = allowed1;
    set<pair<int, int>> bestEdges = edges1;

    for (int Y = 1; Y <= n; Y++)
    {
        if (Y == f[0])
            continue;
        set<int> allowed = {f[0], Y};
        auto edges = getEdges(allowed);
        if (edges.size() < bestCost)
        {
            bestCost = edges.size();
            bestAllowed = allowed;
            bestEdges = edges;
        }
    }

    out << bestEdges.size() << "\n";
    for (auto &edge : bestEdges)
    {
        out << edge.first << " " << edge.second << "\n";
    }
}

string runTest(const string &input)
{
    stringstream inputStream(input);
    ostringstream outputStream;
    solve(inputStream, outputStream);
    return outputStream.str();
}

// Helper function to validate edges (example)
bool validateEdges(const string &output, int n, const vector<int> &f)
{
    istringstream iss(output);
    int k;
    iss >> k;

    set<pair<int, int>> edges;
    int a, b;
    for (int i = 0; i < k; ++i)
    {
        if (!(iss >> a >> b))
            return false; // Not enough edges
        if (a < 1 || a > n || b < 1 || b > n)
            return false; // Invalid function numbers
        edges.insert({a, b});
    }

    if (iss >> a)
        return false; // Too many edges

    if (edges.size() != k)
        return false; // Check for duplicates

    // Further checks can be added here. For example:
    // - Ensure no disallowed edges are created
    return true;
}

TEST(SolutionTest, SampleProvided)
{
    string input = R"(3 7
1
3
3
2
3
2
1
)";
    string output = runTest(input);
    vector<int> f = {1, 3, 3, 2, 3, 2, 1};
    EXPECT_TRUE(validateEdges(output, 3, f));
}

TEST(SolutionTest, SingleChain_AllDifferent)
{
    string input = R"(4 5
2
3
4
1
2
)";
    string output = runTest(input);
    vector<int> f = {2, 3, 4, 1, 2};
    EXPECT_TRUE(validateEdges(output, 4, f));
}

TEST(SolutionTest, AllSameFunctions)
{
    string input = R"(2 6
1
1
1
1
1
1
)";
    string expected = "0\n";
    EXPECT_EQ(runTest(input), expected);
    // No need to call validateEdges if output is known
}

TEST(SolutionTest, EdgeCase_EmptyInput)
{
    string input = R"(5 0

)"; // Empty f array
    string expected = "0\n";
    EXPECT_EQ(runTest(input), expected);
}

TEST(SolutionTest, EdgeCase_SingleFunction)
{
    string input = R"(5 1
  3
  )";
    string expected = "0\n";
    EXPECT_EQ(runTest(input), expected);
}

#ifdef UNIT_TEST
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#else
int main()
{
    solve(cin, cout);
    return 0;
}
#endif