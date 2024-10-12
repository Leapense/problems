#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <cctype>

using namespace std;

int main() {
    unordered_map<char, string> letter_to_signal;
    unordered_map<string, char> signal_to_letter;

    // Read 26 lines of letter/signal combinations
    for (int i = 0; i < 26; ++i) {
        string line;
        getline(cin, line);
        char letter = line[0];
        string signal = line.substr(1);
        letter_to_signal[letter] = signal;
        signal_to_letter[signal] = letter;
    }

    int N;
    cin >> N;
    cin.ignore();

    vector<string> coded_expressions(N);
    for (int i = 0; i < N; ++i) {
        getline(cin, coded_expressions[i]);
    }

    cin >> N;
    cin.ignore();

    vector<string> words_or_phrases(N);
    for (int i = 0; i < N; ++i) {
        getline(cin, words_or_phrases[i]);
    }

    // Decoding
    for (string& coded_expression : coded_expressions) {
        string result = "";
        int pos = 0;
        while (pos < coded_expression.size()) {
            if (coded_expression[pos] == '#') {
                result += ' ';
                ++pos;
                continue;
            }
            bool found = false;
            for (int len = 3; len >= 2; --len) {
                if (pos + len <= coded_expression.size()) {
                    string sub = coded_expression.substr(pos, len);
                    if (signal_to_letter.find(sub) != signal_to_letter.end()) {
                        result += signal_to_letter[sub];
                        pos += len;
                        found = true;
                        break;
                    }
                }
            }
            if (!found) {
                // Invalid signal, skip
                ++pos;
            }
        }
        cout << result << endl;
    }

    // Encoding
    for (string& phrase : words_or_phrases) {
        string result = "";
        for (char ch : phrase) {
            if (ch == ' ') {
                result += '#';
            } else if (isalpha(ch)) {
                ch = toupper(ch);
                result += letter_to_signal[ch];
            }
        }
        cout << result << endl;
    }

    return 0;
}
