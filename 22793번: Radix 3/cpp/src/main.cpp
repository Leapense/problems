#include <iostream>
#include <string>
#include <algorithm>
#include "main.h"

using namespace std;

// 입력된 32비트 정수를 GSC 표현으로 변환하는 함수 구현
std::string toGSC(long long n) {
    if(n == 0) return "0";
    
    string result = "";
    while(n != 0) {
        int rem = n % 3;
        n /= 3;
        
        // 나머지가 2 또는 -2인 경우, 균형 삼진법에 맞게 보정
        if(rem == 2 || rem == -2) {
            if(rem == 2) {
                rem = -1;
                n += 1;
            } else { // rem == -2
                rem = 1;
                n -= 1;
            }
        }
        
        if(rem == 1)
            result.push_back('1');
        else if(rem == 0)
            result.push_back('0');
        else if(rem == -1)
            result.push_back('-');
    }
    
    reverse(result.begin(), result.end());
    return result;
}

#ifndef UNIT_TESTS
int main() {
    long long num;
    // EOF 전까지 입력을 읽어 처리
    while(cin >> num) {
        cout << num << " = " << toGSC(num) << " GSC" << "\n";
    }
    return 0;
}
#endif
