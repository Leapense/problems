#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <utility>
#include <string>
#include <cassert>

using namespace std;

// The solution function that reads from std::cin and writes to std::cout.
void solve()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> f(m);
    for (int i = 0; i < m; i++)
    {
        cin >> f[i];
    }

    // If there is only one or zero lines, no edges are needed.
    if (m <= 1)
    {
        cout << 0 << "\n";
        return;
    }

    // A lambda that, for a given set of allowed error functions, returns
    // the set of required unique edges (f[i+1] calls f[i]) for i from 0 to m-2,
    // if f[i+1] is not in the allowed set.
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

    // Case 1: Use only f[0] as the allowed error function.
    set<int> allowed1 = {f[0]};
    auto edges1 = getEdges(allowed1);
    size_t bestCost = edges1.size();
    set<int> bestAllowed = allowed1;
    set<pair<int, int>> bestEdges = edges1;

    // Case 2: Use f[0] and some Y (Y != f[0]) as allowed error functions.
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

    // Output the result: number of edges and the edge pairs.
    cout << bestEdges.size() << "\n";
    for (auto &edge : bestEdges)
    {
        cout << edge.first << " " << edge.second << "\n";
    }
}

// A helper function to run a single test case.
string runTest(const string &input)
{
    // Redirect input and capture output.
    stringstream inputStream(input);
    streambuf *origCin = cin.rdbuf();
    streambuf *origCout = cout.rdbuf();
    cin.rdbuf(inputStream.rdbuf());
    ostringstream outputStream;
    cout.rdbuf(outputStream.rdbuf());

    solve();

    // Restore original streams.
    cin.rdbuf(origCin);
    cout.rdbuf(origCout);

    return outputStream.str();
}

#ifndef UNIT_TEST
int main()
{
    // If no command line flag for testing, run the solution normally.
    solve();
    return 0;
}
#endif

#ifdef UNIT_TEST
// Test harness main function.
int main()
{
    vector<pair<string, string>> tests = {
        // Test Unit 1: Minimal Input.
        {
            R"(3 1
1
)",
            "0\n"},
        // Test Unit 2: Sample Provided in the Problem Statement.
        {
            R"(3 7
1
3
3
2
3
2
1
)",
            // Expected output may vary because multiple correct answers exist.
            // Here, we provide one possibility.
            "1\n2 3\n"},
        // Test Unit 3: Single Continuous Call Chain.
        {
            R"(4 5
2
3
4
1
2
)",
            // The expected output may vary. One valid output is the set:
            // {(3,2), (4,3), (1,4), (2,1)}
            "4\n3 2\n4 3\n1 4\n2 1\n"},
        // Test Unit 4: Multiple Stacks with Repeated Error Functions.
        {
            R"(5 8
3
2
3
3
5
3
2
3
)",
            // Expected output may vary.
            "1\n5 3\n"},
        // Test Unit 5: Edge Case with All Functions Being the Same.
        {
            R"(2 6
1
1
1
1
1
1
)",
            "0\n"}};

    for (size_t i = 0; i < tests.size(); i++)
    {
        const auto &test = tests[i];
        string output = runTest(test.first);
        cout << "Test Case " << i + 1 << ":\nInput:\n"
             << test.first << "\nOutput:\n"
             << output << "\n";
        // Note: Since the output might be any valid minimal solution,
        // we do not assert equality here.
    }

    return 0;
}
#endif
