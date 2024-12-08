#include <iostream>
#include <string>
#include <cctype>
#include <unordered_set>
#include <algorithm>
using namespace std;

string toLowercase(const string& s) {
    string result;
    for (char c : s) {
        result += tolower(c);
    }
    return result;
}

string filterAlphanumeric(const string& s) {
    string result;
    for (char c : s) {
        if (isalnum(c)) {
            result += tolower(c);
        }
    }
    return result;
}

bool isPalindrome(const string& s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        if (s[left++] != s[right--]) return false;
    }
    return true;
}

bool isValidPassword(const string& password) {
    const unordered_set<string> invalidWords = {"password", "virginia", "cavalier", "code"};
    int length = password.size();

    if (length < 9 || length > 20) return false;

    int lowercase = 0, uppercase = 0, digit = 0, specialChar = 0;

    const string specialChars = "!@#$%^&*.,;/?";
    for (size_t i = 0; i < length; ++i) {
        if (islower(password[i])) lowercase++;
        else if (isupper(password[i])) uppercase++;
        else if (isdigit(password[i])) digit++;
        else if (specialChars.find(password[i]) != string::npos) specialChar++;
    }
    if (lowercase < 2 || uppercase < 2 || digit < 1 || specialChar < 2) return false;

    for (size_t i = 2; i < length; ++i) {
        if (password[i] == password[i - 1] && password[i] == password[i - 2]) {
            return false;
        }
    }

    string filtered = filterAlphanumeric(password);
    if (isPalindrome(filtered)) return false;

    string lowerPassword = toLowercase(password);
    for (const string& word : invalidWords) {
        string lowerWord = toLowercase(word);
        if (filtered.find(lowerWord) != string::npos || filtered.find(string(lowerWord.rbegin(), lowerWord.rend())) != string::npos) {
            return false;
        }
    }

    return true;
}

int main() {
    int N;
    cin >> N;
    cin.ignore();

    while (N--) {
        string password;
        getline(cin, password);

        if (isValidPassword(password)) {
            cout << "Valid Password" << endl;
        } else {
            cout << "Invalid Password" << endl;
        }
    }

    return 0;
}