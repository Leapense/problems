#include <bits/stdc++.h>
using namespace std;

// Function to add two cow numbers based on the cow addition table.
string cow_addition(const string &num1, const string &num2) {
    unordered_map<char, unordered_map<char, pair<char, char>>> add_table = {
        {'V', {{'V', {'V', 'V'}}, {'U', {'U', 'V'}}, {'C', {'C', 'V'}}, {'D', {'D', 'V'}}}},
        {'U', {{'V', {'U', 'V'}}, {'U', {'C', 'V'}}, {'C', {'D', 'V'}}, {'D', {'V', 'U'}}}},
        {'C', {{'V', {'C', 'V'}}, {'U', {'D', 'V'}}, {'C', {'V', 'U'}}, {'D', {'U', 'U'}}}},
        {'D', {{'V', {'D', 'V'}}, {'U', {'V', 'U'}}, {'C', {'U', 'U'}}, {'D', {'C', 'U'}}}}
    };

    string result;
    char carry = 'V';
    for (int i = 4; i >= 0; i--) {
        char first_symbol = add_table[num1[i]][num2[i]].first;
        char carry_symbol = add_table[num1[i]][num2[i]].second;
        first_symbol = add_table[first_symbol][carry].first;
        carry = add_table[first_symbol][carry].second;
        result += first_symbol;
    }
    reverse(result.begin(), result.end());
    return result;
}

// Function to shift right.
string shift_right(const string &num) {
    return "V" + num.substr(0, 4);
}

// Function to shift left.
string shift_left(const string &num) {
    return num.substr(1) + "V";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    cout << "COWCULATIONS OUTPUT" << endl;

    while (n--) {
        string num1, num2;
        cin >> num1 >> num2;

        for (int i = 0; i < 3; i++) {
            char operation;
            cin >> operation;
            if (operation == 'A') {
                num2 = cow_addition(num1, num2);
            } else if (operation == 'R') {
                num2 = shift_right(num2);
            } else if (operation == 'L') {
                num2 = shift_left(num2);
            }
        }

        string result;
        cin >> result;

        // Padding with 'V' to make num2 length 8 if needed.
        while (num2.length() < 8) {
            num2 = "V" + num2;
        }

        if (num2 == result) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    cout << "END OF OUTPUT" << endl;
    return 0;
}