#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

constexpr long long MOD = 1000000007;

enum class Operation
{
    ADD,
    MUL
};

struct Frame
{
    Operation op;
    long long value;
};

void solve(istream &in, ostream &out)
{
    int n;
    in >> n;

    stack<Frame> st;
    // Start with top-level addition. Identity for addition is 0.
    Frame current = {Operation::ADD, 0};

    for (int i = 0; i < n; i++)
    {
        string token;
        in >> token;

        if (token == "(")
        {
            st.push(current);
            // Toggle the operator for the new level:
            Operation newOp = (current.op == Operation::ADD ? Operation::MUL : Operation::ADD);
            // Set identity for the new level: 0 for addition, 1 for multiplication.
            long long init = (newOp == Operation::ADD ? 0 : 1);
            current = {newOp, init};
        }
        else if (token == ")")
        {
            long long groupVal = current.value;
            current = st.top();
            st.pop();
            // Combine the group value with the previous level's value.
            if (current.op == Operation::ADD)
            {
                current.value = (current.value + groupVal) % MOD;
            }
            else
            {
                current.value = (current.value * groupVal) % MOD;
            }
        }
        else
        {
            long long num = stoll(token);
            if (current.op == Operation::ADD)
            {
                current.value = (current.value + num) % MOD;
            }
            else
            {
                current.value = (current.value * num) % MOD;
            }
        }
    }

    out << current.value << "\n";
}

#ifdef DEBUG
// Test harness code
struct TestCase
{
    string input;
    string expectedOutput;
};

void runTests()
{
    vector<TestCase> tests = {
        // Test Case 1: Single Number
        {"1\n42\n", "42\n"},
        // Test Case 2: Two Numbers (Addition at Top Level)
        {"2\n2 3\n", "5\n"},
        // Test Case 3: Single Group (Multiplication Inside Parentheses)
        {"4\n( 12 3 )\n", "36\n"},
        // Test Case 4: Two Separate Groups (Addition at Top Level)
        {"6\n( 2 ) ( 3 )\n", "5\n"},
        // Test Case 5: Nested Group (Alternating Operations)
        {"6\n( ( 2 3 ) )\n", "5\n"},
        // Test Case 6: Mixed Nesting with Zeros and Large Numbers
        {"11\n1 ( 0 ( 583920 ( 2839 82 ) ) )\n", "1\n"},
        // Test Case 7: Complex Expression (Combination of Nested Addition and Multiplication)
        {"9\n5 2 ( 3 1 ( 2 2 ) ( 3 3 ) 1 )\n", "79\n"}};

    for (size_t i = 0; i < tests.size(); i++)
    {
        istringstream iss(tests[i].input);
        ostringstream oss;
        solve(iss, oss);
        string result = oss.str();
        cout << "Test Case " << i + 1 << ": ";
        if (result == tests[i].expectedOutput)
        {
            cout << "Passed\n";
        }
        else
        {
            cout << "Failed\n";
            cout << "Expected Output: " << tests[i].expectedOutput;
            cout << "Your Output: " << result;
        }
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
