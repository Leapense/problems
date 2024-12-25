#include <iostream>
#include <string>

using namespace std;

int main() {
    string text;
    string line;

    while (getline(cin, line)) {
        text += line + "\n";
    }

    string result;
    int nesting_level = 0;
    size_t index = 0;
    size_t length = text.length();

    while (index < length) {
        if (text[index] == '/' && index + 1 < length && text[index + 1] == '*') {
            nesting_level++;
            index += 2;
        } else if (text[index] == '*' && index + 1 < length && text[index + 1] == '/' && nesting_level > 0) {
            nesting_level--;
            index += 2;
        } else if (nesting_level == 0) {
            result += text[index];
            index++;
        } else {
            index++;
        }
    }
    cout << "Case #1:\n" << result;

    return 0;
}