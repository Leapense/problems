#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    // 입력 메시지를 받는다.
    string message;
    getline(cin, message);
    
    // 행복한 글자와 우울한 글자를 정의한다.
    string happyLetters = "HAPPY";
    string sadLetters = "SAD";
    
    int P_H = 0; // 행복 점수
    int P_G = 0; // 우울 점수
    
    // 각 글자를 순회하며 행복 점수와 우울 점수를 계산한다.
    for (char c : message) {
        if (happyLetters.find(c) != string::npos) {
            P_H++; // 행복한 글자일 때
        }
        if (sadLetters.find(c) != string::npos) {
            P_G++; // 우울한 글자일 때
        }
    }
    
    // 행복 지수 계산
    double happinessIndex = 0.5; // 기본값으로 0.5
    if (P_H + P_G > 0) {
        happinessIndex = static_cast<double>(P_H) / (P_H + P_G);
    }
    
    // 백분율로 출력, 소수점 둘째 자리까지
    cout << fixed << setprecision(2) << happinessIndex * 100 << endl;

    return 0;
}