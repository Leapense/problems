#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

string normalize(string s) {
    string result = "";
    for (char c : s) {
        if (isalpha(c)) {
            result += tolower(c);
        } else if (isdigit(c) || c == ' ') {
            result += c;
        } else {
            if (!result.empty() && isalpha(result.back()))
            {
            }
            else if(!result.empty() && result.back() != ' ')
            {
                result += ' ';
            }
        }
    }
    
    if (!result.empty() && result.back() == ' ') result.pop_back();
    return result;
}

bool is_number(const string& s) {
    for (char c : s) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return !s.empty();
}

int main() {
    string line;
    while (getline(cin, line) && line != "#") {
        string normalized_line = normalize(line);
        
        set<string> words;
        string current_word = "";
        for (char c : normalized_line) {
            if (c == ' ') {
                if (!current_word.empty() && !is_number(current_word)) {
                    words.insert(current_word);
                }
                current_word = "";
            } else {
                current_word += c;
            }
        }
        if (!current_word.empty() && !is_number(current_word)) {
            words.insert(current_word);
        }
        
        for (const string& word : words) {
            cout << word << endl;
        }
        cout << endl;
    }
    return 0;
}