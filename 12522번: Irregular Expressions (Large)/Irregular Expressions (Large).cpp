#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int countVowels(const string& s) {
    int count = 0;
    for (char c : s) {
        if (isVowel(c)) count++;
    }
    return count;
}

void findSpells(const string& expr, int caseNum) {
    int n = expr.size();
    set<string> candidates;

    // Find all substrings with at least two vowels
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            string substr = expr.substr(i, j - i);
            if (countVowels(substr) >= 2) {
                candidates.insert(substr);
            }
        }
    }

    // For each candidate, find positions where it appears
    for (const string& cand : candidates) {
        vector<int> positions;
        int len = cand.size();
        for (int i = 0; i <= n - len; ++i) {
            if (expr.substr(i, len) == cand) {
                positions.push_back(i);
            }
        }
        // Check for pairs of positions with a valid middle part
        for (size_t p = 0; p < positions.size(); ++p) {
            for (size_t q = p + 1; q < positions.size(); ++q) {
                int start1 = positions[p];
                int start2 = positions[q];
                int middleStart = start1 + len;
                int middleEnd = start2;
                if (middleEnd <= middleStart) continue; // Middle part must be non-empty
                string middle = expr.substr(middleStart, middleEnd - middleStart);
                if (countVowels(middle) >= 1) {
                    cout << "Case #" << caseNum << ": Spell!" << endl;
                    return;
                }
            }
        }
    }
    cout << "Case #" << caseNum << ": Nothing." << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        string expr;
        cin >> expr;
        findSpells(expr, t);
    }
    return 0;
}