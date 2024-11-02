#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string input;
    cin >> input;

    string letters = "";
    string digits = "";

    for (char c : input) {
        if (isalpha(c)) {
            letters += c;
        } else if (isdigit(c)) {
            digits += c;
        }
    }

    sort(letters.begin(), letters.end());
    sort(digits.rbegin(), digits.rend());

    string password = "";

    for (int i = 0; i < 3; ++i) {
        password += letters[i];
        password += digits[i];
    }

    cout << password << "\n";

    return 0;
}