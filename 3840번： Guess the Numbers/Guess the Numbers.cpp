#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// Structure to hold expression parse results
struct Expr
{
    bool isLeaf;
    char var;
    string expr; // Store the full sub-expression
    char op;     // Store operator for non-leaf nodes
    int leftEnd; // End position of left expression
    Expr() : isLeaf(false), var(0), op(0), leftEnd(-1) {}
};

// Parse the expression into a tree-like structure
Expr parseExpression(const string &expr, int start, int end)
{
    Expr result;

    // Remove outer parentheses if they encompass the entire expression
    if (start < end && expr[start] == '(' && expr[end] == ')')
    {
        int parenCount = 0;
        bool isOuter = true;
        for (int i = start + 1; i < end; i++)
        {
            if (expr[i] == '(')
                parenCount++;
            if (expr[i] == ')')
                parenCount--;
            if (parenCount < 0)
            {
                isOuter = false;
                break;
            }
        }
        if (isOuter && parenCount == 0)
        {
            return parseExpression(expr, start + 1, end - 1);
        }
    }

    // If it's a single character (variable)
    if (start == end)
    {
        result.isLeaf = true;
        result.var = expr[start];
        result.expr = expr.substr(start, 1);
        return result;
    }

    // Find the main operator (not inside nested parentheses)
    int parenCount = 0;
    int opPos = -1;

    for (int i = end; i >= start; i--)
    {
        if (expr[i] == ')')
            parenCount++;
        if (expr[i] == '(')
            parenCount--;
        if (parenCount == 0 && (expr[i] == '+' || expr[i] == '-' || expr[i] == '*'))
        {
            opPos = i;
            break;
        }
    }

    // If no operator found, it's a parenthesized expression
    if (opPos == -1)
    {
        return parseExpression(expr, start + 1, end - 1);
    }

    // Store the full expression and operator details
    result.isLeaf = false;
    result.expr = expr.substr(start, end - start + 1);
    result.op = expr[opPos];
    result.leftEnd = opPos - 1;
    return result;
}

// Evaluate the expression with given variable assignments
long long evaluate(const Expr &expr, const map<char, int> &assignment)
{
    // If it's a leaf node (variable)
    if (expr.isLeaf)
    {
        return assignment.at(expr.var);
    }

    // Parse left and right sub-expressions
    string leftExpr = expr.expr.substr(1, expr.leftEnd - 1);                    // Skip '('
    string rightExpr = expr.expr.substr(expr.leftEnd + 2,                       // Skip operator and '('
                                        expr.expr.length() - expr.leftEnd - 3); // Skip ')'

    Expr left = parseExpression(leftExpr, 0, leftExpr.length() - 1);
    Expr right = parseExpression(rightExpr, 0, rightExpr.length() - 1);

    long long leftVal = evaluate(left, assignment);
    long long rightVal = evaluate(right, assignment);

    // Perform the operation
    if (expr.op == '+')
        return leftVal + rightVal;
    if (expr.op == '-')
        return leftVal - rightVal;
    if (expr.op == '*')
        return leftVal * rightVal;
    return 0; // Should never reach here
}

// Find all variables in the expression
void findVariables(const string &expr, vector<char> &variables)
{
    for (char c : expr)
    {
        if (c >= 'a' && c <= 'z')
        {
            if (find(variables.begin(), variables.end(), c) == variables.end())
            {
                variables.push_back(c);
            }
        }
    }
}

int main()
{
    while (true)
    {
        // Read input
        int n;
        cin >> n;
        if (n == 0)
        {
            int dummy;
            cin >> dummy;
            break;
        }

        // Read values and target result
        vector<int> values(n);
        for (int i = 0; i < n; i++)
        {
            cin >> values[i];
        }
        int target;
        cin >> target;

        // Read expression
        string expr;
        cin >> expr;

        // Find all variables in the expression
        vector<char> variables;
        findVariables(expr, variables);

        // Parse the expression
        Expr root = parseExpression(expr, 0, expr.length() - 1);

        // Try all possible assignments using permutations
        bool possible = false;
        sort(values.begin(), values.end());

        do
        {
            // Create assignment map
            map<char, int> assignment;
            for (int i = 0; i < n; i++)
            {
                assignment[variables[i]] = values[i];
            }

            // Evaluate the expression with current assignment
            long long result = evaluate(root, assignment);
            if (result == target)
            {
                possible = true;
                break;
            }
        } while (next_permutation(values.begin(), values.end()));

        // Output result
        cout << (possible ? "YES" : "NO") << "\n";
    }
    return 0;
}