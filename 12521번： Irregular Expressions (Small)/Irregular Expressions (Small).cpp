#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 음절인지 확인하는 함수
bool isSyllable(const string& s) {
    int vowelCount = 0;
    for (char ch : s) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowelCount++;
        }
    }
    return vowelCount == 1;
}

// 주문인지 확인하는 함수
bool isSpell(const string& s) {
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                string start = s.substr(i, j - i);
                string middle = s.substr(j, k - j);
                string end = s.substr(k);
                
                // 시작 단어와 끝 단어가 같고, 각 단어가 최소 두 음절인지 확인
                if (start == end) {
                    int startSyllables = 0;
                    int middleSyllables = 0;
                    int endSyllables = 0;
                    
                    // 시작 단어의 음절 수 계산
                    for (int l = 0; l < start.length(); ) {
                        for (int m = l + 1; m <= start.length(); ++m) {
                            if (isSyllable(start.substr(l, m - l))) {
                                startSyllables++;
                                l = m;
                                break;
                            }
                        }
                    }
                    
                    // 중간 단어의 음절 수 계산
                    for (int l = 0; l < middle.length(); ) {
                        for (int m = l + 1; m <= middle.length(); ++m) {
                            if (isSyllable(middle.substr(l, m - l))) {
                                middleSyllables++;
                                l = m;
                                break;
                            }
                        }
                    }
                    
                    // 끝 단어의 음절 수 계산
                    for (int l = 0; l < end.length(); ) {
                        for (int m = l + 1; m <= end.length(); ++m) {
                            if (isSyllable(end.substr(l, m - l))) {
                                endSyllables++;
                                l = m;
                                break;
                            }
                        }
                    }
                    
                    if (startSyllables >= 2 && middleSyllables >= 1 && endSyllables >= 2) {
                        return true;
                    }
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