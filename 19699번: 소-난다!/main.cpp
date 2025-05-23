#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <cmath>
#include <cassert>
using namespace std;

// Function to check if a number is prime
bool isPrime(int num)
{
    if (num < 2)
        return false;
    for (int i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

// Backtracking function to generate combinations
void dfs(int idx, int count, int currentSum, int N, int M, const vector<int> &weights, set<int> &primeSums)
{
    if (count == M)
    {
        if (isPrime(currentSum))
            primeSums.insert(currentSum);
        return;
    }
    if (idx >= N)
        return;

    // Include the current cow's weight
    dfs(idx + 1, count + 1, currentSum + weights[idx], N, M, weights, primeSums);
    // Exclude the current cow's weight
    dfs(idx + 1, count, currentSum, N, M, weights, primeSums);
}

// Main solution function
void solve(istream &in = cin, ostream &out = cout)
{
    int N, M;
    in >> N >> M;
    vector<int> weights(N);
    for (int i = 0; i < N; ++i)
    {
        in >> weights[i];
    }

    set<int> primeSums;
    dfs(0, 0, 0, N, M, weights, primeSums);

    if (primeSums.empty())
    {
        out << -1 << "\n";
    }
    else
    {
        for (int sum : primeSums)
            out << sum << " ";
        out << "\n";
    }
}

#ifdef UNIT_TEST
// A helper function to run individual test cases
void runTest(const string &testInput, const string &expectedOutput)
{
    stringstream input(testInput);
    stringstream output;
    solve(input, output);
    // Compare the resulting output with expected output
    assert(output.str() == expectedOutput);
}

void runTests()
{
    {
        // Test case 1: Sample Input
        string input = "5 3\n2 4 10 5 8\n";
        // Expected output (note: extra space at end is acceptable or can be trimmed if needed)
        string expected = "11 17 19 23 \n";
        runTest(input, expected);
    }

    {
        // Test case 2: No valid prime sum exists
        // For example, if there is only one cow and its weight is 4 (which is not prime)
        string input = "1 1\n4\n";
        string expected = "-1\n";
        runTest(input, expected);
    }

    {
        // Test case 3: Another scenario with multiple cows
        // Input: 4 cows, choose 2, weights such that there are multiple possible sums.
        string input = "4 2\n3 5 8 12\n";
        // Possible combinations and their sums:
        // 3+5=8 (not prime), 3+8=11 (prime), 3+12=15 (not prime), 5+8=13 (prime), 5+12=17 (prime), 8+12=20 (not prime)
        string expected = "11 13 17 \n";
        runTest(input, expected);
    }

    cout << "All tests passed.\n";
}
#endif

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef UNIT_TEST
    runTests();
#else
    solve();
#endif

    return 0;
}
