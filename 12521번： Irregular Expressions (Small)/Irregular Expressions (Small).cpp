#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 음절로 구분하는 함수
vector<string> splitIntoSyllables(const string& s) {
    vector<string> syllables;
    int n = s.length();
    int start = 0;
    while (start < n) {
        int end = start + 1;
        while (end <= n) {
            string syllable = s.substr(start, end - start);
            int vowelCount = 0;
            for (char ch : syllable) {
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                    vowelCount++;
                }
            }
            if (vowelCount == 1) {
                syllables.push_back(syllable);
                start = end;
                break;
            }
            end++;
        }
    }
    return syllables;
}

// 주문인지 확인하는 함수
bool isSpell(const string& s) {
    vector<string> syllables = splitIntoSyllables(s);
    int n = syllables.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                string startWord;
                for (int l = i; l < j; ++l) {
                    startWord += syllables[l];
                }
                string middleWord;
                for (int l = j; l < k; ++l) {
                    middleWord += syllables[l];
                }
                string endWord;
                for (int l = k; l < n; ++l) {
                    endWord += syllables[l];
                }
                if (startWord == endWord && (j - i) >= 2 && (k - j) >= 1 && (n - k) >= 2) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        string expression;
        cin >> expression;
        if (isSpell(expression)) {
            cout << "Case #" << t << ": Spell!" << endl;
        } else {
            cout << "Case #" << t << ": Nothing." << endl;
        }
    }
    return 0;
}