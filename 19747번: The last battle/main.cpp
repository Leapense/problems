#include <iostream>
#include <sstream>
#include <vector>
#include <cassert>
using namespace std;

// Function that processes one test case.
// It reads input from the provided stream and returns the result as a string.
string solveCase(istream &in)
{
    int n;
    in >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        in >> a[i];
    }

    // Mark "bad" shifts in an array of size n.
    vector<bool> bad(n, false);
    for (int i = 1; i <= n; ++i)
    {
        int k;
        if (a[i] <= i)
        {
            k = i - a[i];
        }
        else
        {
            k = n + i - a[i];
        }
        if (k >= 0 && k < n)
        {
            bad[k] = true;
        }
    }

    // Find the smallest k (number of shifts) which is not "bad"
    int ans = -1;
    for (int k = 0; k < n; ++k)
    {
        if (!bad[k])
        {
            ans = k;
            break;
        }
    }
    return to_string(ans);
}

#ifdef UNIT_TEST
// Unit tests to verify correctness of the solution.
void runTests()
{
    {
        // Sample Test Case 1:
        // Input: 5 / 1 4 2 3 5
        // Expected output: 2
        string input = "5\n1 4 2 3 5\n";
        istringstream iss(input);
        string output = solveCase(iss);
        assert(output == "2");
    }
    {
        // Sample Test Case 2:
        // Input: 5 / 1 3 5 2 4
        // Expected output: -1
        string input = "5\n1 3 5 2 4\n";
        istringstream iss(input);
        string output = solveCase(iss);
        assert(output == "-1");
    }
    {
        // Edge Case: Only one fighter.
        // Input: 1 / 1
        // Expected output: -1 (since the only person would face Martian 1)
        string input = "1\n1\n";
        istringstream iss(input);
        string output = solveCase(iss);
        assert(output == "-1");
    }
    {
        // Additional test:
        // Input: 6 / 2 3 4 5 6 1
        // Analysis: All computed bad k's are 5, so k = 0 is valid.
        // Expected output: 0
        string input = "6\n2 3 4 5 6 1\n";
        istringstream iss(input);
        string output = solveCase(iss);
        assert(output == "0");
    }
    {
        // Additional test:
        // Input: 4 / 2 1 4 3
        // Expected output: 0
        string input = "4\n2 1 4 3\n";
        istringstream iss(input);
        string output = solveCase(iss);
        assert(output == "0");
    }
    // Additional tests can be added here as needed.
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
    cout << solveCase(cin) << "\n";
#endif
    return 0;
}
