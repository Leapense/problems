#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

bool isValidISBN10(const string &s, vector<int> &digits, vector<int> &hyphen_positions) {
    int n = s.size();
    int hyphen_count = 0;
    bool last_char_hyphen = false;
    bool first_char_hyphen = false;
    vector<int> hyphen_positions_temp;

    if (s[0] == '-' || s[n - 1] == '-')
        return false;

    int digit_count = 0;
    vector<int> digit_values;

    for (int i = 0; i < n; ++i) {
        char c = s[i];
        if (c == '-') {
            hyphen_count++;
            if (last_char_hyphen)
                return false;
            hyphen_positions_temp.push_back(digit_count);
            last_char_hyphen = true;
        } else {
            last_char_hyphen = false;
            if (digit_count >= 10)
                return false; // Too many digits
            if (c >= '0' && c <= '9') {
                digit_values.push_back(c - '0');
            } else if (c == 'X') {
                if (digit_count != 9)
                    return false; // 'X' only allowed in checksum position
                digit_values.push_back(10);
            } else {
                return false; // Invalid character
            }
            digit_count++;
        }
    }

    if (digit_count != 10)
        return false;

    if (hyphen_count > 3)
        return false;

    if (hyphen_count == 3) {
        // Check that one hyphen separates the checksum digit from the previous digit
        int checksum_hyphen_pos = digit_count - 1; // After the 9th digit (before checksum digit)
        bool found = false;
        for (int pos : hyphen_positions_temp) {
            if (pos == checksum_hyphen_pos) {
                found = true;
                break;
            }
        }
        if (!found)
            return false;
    }

    // Compute ISBN-10 checksum
    int S = 0;
    for (int i = 0; i < 10; ++i) {
        S += (10 - i) * digit_values[i];
    }
    if (S % 11 != 0)
        return false;

    // If all checks pass, copy digits and hyphen positions
    digits = digit_values;
    hyphen_positions = hyphen_positions_temp;
    return true;
}

string convertISBN10toISBN13(const vector<int> &digits, const vector<int> &hyphen_positions) {
    vector<int> isbn13_digits = {9, 7, 8};
    for (int i = 0; i < 9; ++i) {
        isbn13_digits.push_back(digits[i]);
    }
    // Compute ISBN-13 checksum
    int S = 0;
    for (int i = 0; i < 12; ++i) {
        int multiplier = (i % 2 == 0) ? 1 : 3;
        S += isbn13_digits[i] * multiplier;
    }
    int checksum_digit = (10 - (S % 10)) % 10;
    isbn13_digits.push_back(checksum_digit);

    // Adjust hyphen positions
    vector<int> new_hyphen_positions;
    new_hyphen_positions.push_back(3); // Hyphen after '978'
    for (int pos : hyphen_positions) {
        new_hyphen_positions.push_back(pos + 3); // Shift by 3 positions
    }

    // Build ISBN-13 string
    string isbn13;
    int digit_index = 0;
    for (int i = 0; i < 13; ++i) {
        isbn13 += '0' + isbn13_digits[i];
        digit_index++;
        for (int h_pos : new_hyphen_positions) {
            if (digit_index == h_pos) {
                isbn13 += '-';
                break;
            }
        }
    }
    return isbn13;
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Ignore newline after T
    while (T--) {
        string s;
        getline(cin, s);

        vector<int> digits;
        vector<int> hyphen_positions;
        if (isValidISBN10(s, digits, hyphen_positions)) {
            string isbn13 = convertISBN10toISBN13(digits, hyphen_positions);
            cout << isbn13 << endl;
        } else {
            cout << "invalid" << endl;
        }
    }
    return 0;
}