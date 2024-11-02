#include <iostream>
#include <string>

int main() {
    std::string s;
    long long x; // x의 범위가 -1e5에서 1e5이므로 long long으로 선언
    std::cin >> s >> x;

    int nL = 0, nR = 0;
    for(char c : s){
        if(c == 'L') nL++;
        if(c == 'R') nR++;
    }

    bool hasL = nL > 0;
    bool hasR = nR > 0;
    bool possible = false;

    if(hasL && hasR){
        // 'L'과 'R'이 모두 있는 경우
        // x >= nR - nL
        if(x >= (long long)(nR) - (long long)(nL)){
            possible = true;
        }
    }
    else if(hasL){
        // 'L'만 있는 경우
        if(x <= -(long long)(nL)){
            possible = true;
        }
    }
    else if(hasR){
        // 'R'만 있는 경우
        if(x >= (long long)(nR)){
            possible = true;
        }
    }
    // else: 'L'과 'R'이 모두 없는 경우, 이동이 없으므로 x ==0만 가능하지만 문제 조건상 |s|>=1이므로 "NO"

    std::cout << (possible ? "YES" : "NO") << std::endl;

    return 0;
}
