#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cassert>
using namespace std;

// Function that solves one test case reading from the provided istream and writing to the provided ostream.
void solve(istream &in, ostream &out)
{
    int N;
    in >> N;

    vector<long long> D(N - 1);
    for (int i = 0; i < N - 1; i++)
    {
        in >> D[i];
    }

    // Compute prefix sum array
    vector<long long> prefix(N);
    prefix[0] = 0;
    for (int i = 1; i < N; i++)
    {
        prefix[i] = prefix[i - 1] + D[i - 1];
    }

    // Find minimum and maximum prefix sums
    long long minPrefix = *min_element(prefix.begin(), prefix.end());
    long long maxPrefix = *max_element(prefix.begin(), prefix.end());

    // Calculate the possible starting value x
    long long L = 1 - minPrefix;
    long long R = N - maxPrefix;

    // If there's no unique value for x, output -1.
    if (L != R)
    {
        out << -1;
        return;
    }

    long long x = L;
    // Build and output the sequence A: A[i] = x + prefix[i]
    for (int i = 0; i < N; i++)
    {
        out << (x + prefix[i]) << (i + 1 == N ? "\n" : " ");
    }
}

#ifdef DEBUG
// Test framework: each test is a pair of input string and expected output string.
void runTests()
{
    struct TestCase
    {
        string input;
        string expected;
    };

    vector<TestCase> tests = {
        // Test Case 1: Minimal Case (Unique Recovery)
        {
            "2\n1\n",
            "1 2\n"},
        // Test Case 2: Minimal Case (Ambiguous Recovery)
        {
            "2\n0\n",
            "-1"},
        // Test Case 3: Provided Example (Unique Recovery)
        {
            "5\n1 3 -2 1\n",
            "1 2 5 3 4\n"},
        // Test Case 4: Provided Example (Unique Recovery)
        {
            "5\n2 2 -3 1\n",
            "1 3 5 2 3\n"},
        // Test Case 5: Larger Case (Ambiguous Recovery)
        {
            "6\n-1 -1 2 0 1\n",
            "-1"},
        // Test Case 6: Monotonic Increasing Sequence (Unique Recovery)
        {
            "5\n1 1 1 1\n",
            "1 2 3 4 5\n"},
        // Test Case 7: Monotonic Decreasing Sequence (Unique Recovery)
        {
            "5\n-1 -1 -1 -1\n",
            "5 4 3 2 1\n"},
        // Test Case 8: Random Case (Ambiguous Recovery)
        {
            "7\n0 2 -3 1 1 0\n",
            "-1"}};

    for (size_t i = 0; i < tests.size(); i++)
    {
        stringstream input(tests[i].input);
        stringstream output;
        solve(input, output);
        string result = output.str();
        // Remove trailing newline characters for comparison
        while (!result.empty() && result.back() == '\n')
            result.pop_back();
        string expected = tests[i].expected;
        while (!expected.empty() && expected.back() == '\n')
            expected.pop_back();
        assert(result == expected && "Test case failed!");
        cout << "Test case " << i + 1 << " passed.\n";
    }
}
#endif

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef DEBUG
    runTests();
#else
    solve(cin, cout);
#endif

    return 0;
}
