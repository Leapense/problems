#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int calculate(int a, int b, char op) {
    if (op == '*') return a * b;
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '/') {
        if (b == 0) return 1000001;
        return a / b;
    }

    return 1000001;
}

int main()
{
    int m;
    cin >> m;
    cin.ignore();

    unordered_map<int, string> results;
    vector<char> ops = {'*', '+', '-', '/'};

    for (char op1 : ops) {
        for (char op2 : ops) {
            for (char op3 : ops) {
                int result1 = calculate(calculate(4, 4, op1), calculate(4, 4, op3), op2);
                if (result1 >= -1000000 && result1 <= 1000000) {
                    string equation1 = "4 " + string(1, op1) + " 4 " + string(1, op2) + " 4 " + string(1, op3) + " 4";
                    results[result1] = equation1;
                }

                int result2 = calculate(calculate(calculate(4, 4, op1), 4, op2), 4, op3);
                if (result2 >= -1000000 && result2 <= 1000000) {
                    string equation2 = "4 " + string(1, op1) + " 4 " + string(1, op2) + " 4 " + string(1, op3) + " 4";
                    results[result2] = equation2;
                }
            }
        }
    }

    while (m--) {
        int n;
        cin >> n;

        if (results.count(n)) {
            cout << results[n] << " = " << n << "\n";
        } else {
            cout << "no solution" << endl;
        }
    }

    return 0;
}