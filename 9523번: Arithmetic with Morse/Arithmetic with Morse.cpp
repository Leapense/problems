#include <bits/stdc++.h>
using namespace std;

// Function to calculate the value of a Morse number
int valueOfMorseNumber(const string &s) {
    int val = 0;
    for (auto c : s) {
        if (c == '.') val += 1;
        else if (c == '-') val += 5;
        else if (c == ':') val += 2;
        else if (c == '=') val += 10;
    }
    return val;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int N;
    cin >> N;

    vector<string> tokens(2 * N + 1);
    for (int i = 0; i < 2 * N + 1; ++i) {
        cin >> tokens[i];
    }

    vector<int> values;
    vector<char> operators;

    // Parse the tokens
    for (int i = 0; i < tokens.size(); ++i) {
        if (i % 2 == 0) {
            // Morse number
            values.push_back(valueOfMorseNumber(tokens[i]));
        } else {
            // Operator
            operators.push_back(tokens[i][0]);
        }
    }

    // Process multiplication (*) first
    vector<int> tempValues;
    vector<char> tempOperators;

    tempValues.push_back(values[0]);
    for (int i = 0; i < operators.size(); ++i) {
        if (operators[i] == '*') {
            int lastValue = tempValues.back();
            tempValues.pop_back();
            tempValues.push_back(lastValue * values[i + 1]);
        } else {
            tempValues.push_back(values[i + 1]);
            tempOperators.push_back(operators[i]);
        }
    }

    // Process addition (+)
    int result = tempValues[0];
    for (int i = 0; i < tempOperators.size(); ++i) {
        result += tempValues[i + 1];
    }

    cout << result << "\n";

    return 0;
}
