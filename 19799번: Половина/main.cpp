#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>
#include <iomanip>
using namespace std;

// The solve() function simulates the program execution using input from a string.
string solve(const string &input)
{
    stringstream ss(input);
    int n, k;
    ss >> n >> k;

    // Represent apples in terms of half-apples.
    int start = 2 * n;

    // Use a set to store distinct states (measured in half-apples).
    set<int> current;
    current.insert(start);

    // Process each friend encounter.
    for (int i = 0; i < k; i++)
    {
        set<int> next;
        for (int state : current)
        {
            if (state % 2 == 0)
            { // integer number of apples
                if (state - 1 >= 0)
                    next.insert(state - 1); // giving away half an apple
                next.insert(state / 2);     // giving away half of the apples
            }
            else
            { // fractional amount; only option is to give half an apple
                if (state - 1 >= 0)
                    next.insert(state - 1);
            }
        }
        current = move(next);
    }

    // Convert half-apples back to apples and collect results.
    vector<double> answers;
    for (int state : current)
    {
        answers.push_back(state / 2.0);
    }
    sort(answers.begin(), answers.end());

    // Prepare the output string.
    stringstream out;
    out << answers.size() << "\n";
    out << fixed << setprecision(1);
    for (double apple : answers)
    {
        out << apple << " ";
    }
    out << "\n";

    return out.str();
}

// Custom unit tests function.
void run_tests()
{
    struct TestCase
    {
        string input;
        string expected;
        string description;
    };

    vector<TestCase> tests = {
        {"6 1\n",
         "2\n3.0 5.5 \n",
         "Sample test case: 6 apples, 1 friend"},
        {"1 1\n",
         "1\n0.5 \n",
         "Edge case: minimum values, 1 apple and 1 friend"},
        {"2 2\n",
         "2\n0.5 1.0 \n",
         "Test case: n=2, k=2"},
        {"3 2\n",
         "2\n1.0 2.0 \n",
         "Test case: n=3, k=2"},
        {"4 3\n",
         "4\n0.5 1.0 1.5 2.5 \n",
         "Test case: n=4, k=3"},
        {"10 5\n",
         "8\n0.5 1.0 1.5 2.0 3.0 3.5 4.0 7.5 \n",
         "Test case: n=10, k=5"}};

    bool allPassed = true;
    int testNum = 1;
    for (const auto &tc : tests)
    {
        string output = solve(tc.input);
        if (output == tc.expected)
        {
            cout << "Test case " << testNum << " passed: " << tc.description << "\n";
        }
        else
        {
            cout << "Test case " << testNum << " FAILED: " << tc.description << "\n";
            cout << "  Input:\n"
                 << tc.input;
            cout << "  Expected:\n"
                 << tc.expected;
            cout << "  Got:\n"
                 << output;
            allPassed = false;
        }
        testNum++;
    }

    if (allPassed)
    {
        cout << "All tests passed.\n";
    }
    else
    {
        cout << "Some tests failed.\n";
    }
}

int main()
{
    // Uncomment the following line to run the unit tests:
    // run_tests();

    // For online judge submission, comment out the run_tests() call and use standard input.
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int start = 2 * n;
    set<int> current;
    current.insert(start);

    for (int i = 0; i < k; i++)
    {
        set<int> next;
        for (int state : current)
        {
            if (state % 2 == 0)
            {
                if (state - 1 >= 0)
                    next.insert(state - 1);
                next.insert(state / 2);
            }
            else
            {
                if (state - 1 >= 0)
                    next.insert(state - 1);
            }
        }
        current = move(next);
    }

    vector<double> answers;
    for (int state : current)
    {
        answers.push_back(state / 2.0);
    }
    sort(answers.begin(), answers.end());

    cout << answers.size() << "\n";
    cout << fixed << setprecision(1);
    for (double apple : answers)
    {
        cout << apple << " ";
    }
    cout << "\n";

    return 0;
}
