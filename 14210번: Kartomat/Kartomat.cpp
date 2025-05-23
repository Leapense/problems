#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    // 키보드 배열 초기화
    vector<string> keyboard = {
        "***ABCDE",
        "FGHIJKLM",
        "NOPQRSTU",
        "VWXYZ***"
    };

    int N;
    cin >> N;
    
    vector<string> destinations(N);
    for (int i = 0; i < N; ++i) {
        cin >> destinations[i];
    }
    
    string prefix;
    cin >> prefix;
    
    int prefix_len = prefix.size();
    unordered_set<char> next_letters; // 선택 가능한 다음 문자들을 저장할 집합
    
    // 접두사로 필터링된 목적지에서 다음 문자를 찾아냄
    for (const string& dest : destinations) {
        if (dest.size() > prefix_len && dest.substr(0, prefix_len) == prefix) {
            next_letters.insert(dest[prefix_len]);
        }
    }
    
    // 키보드 상태 업데이트
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 8; ++j) {
            char key = keyboard[i][j];
            if (next_letters.find(key) == next_letters.end()) {
                keyboard[i][j] = '*'; // 선택할 수 없는 문자는 '*'로 대체
            }
        }
    }

    // 키보드 상태 출력
    for (const string& row : keyboard) {
        cout << row << endl;
    }
    
    return 0;
}
