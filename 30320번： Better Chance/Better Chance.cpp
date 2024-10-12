#include <bits/stdc++.h>
using namespace std;

// 사용자의 빠른 입력을 위한 버퍼 설정
static char buf[1 << 19]; // 버퍼 크기: 524,288 bytes
static int idx = 0;
static int bytes = 0;

// 버퍼에서 다음 문자를 읽어오는 함수
static inline int _read() {
    if (!bytes || idx == bytes) {
        bytes = (int)fread(buf, sizeof(buf[0]), sizeof(buf), stdin);
        if (bytes == 0) return EOF;
        idx = 0;
    }
    return buf[idx++];
}

// 정수를 빠르게 읽어오는 함수
static inline int _readInt() {
    int x = 0, s = 1;
    int c = _read();
    while (c <= 32) c = _read(); // 공백 문자 무시
    if (c == '-') { s = -1; c = _read(); }
    while (c >= '0' && c <= '9') {
        x = x * 10 + (c - '0');
        c = _read();
    }
    return x * s;
}

// 소수점을 포함한 점수를 100배한 정수로 변환하여 읽어오는 함수
static inline long long _readScore() {
    long long integer_part = 0, decimal_part = 0;
    int c = _read();
    while (c <= 32) c = _read(); // 공백 문자 무시

    // 음수 처리 (문제 조건상 필요 없을 수 있으나 안전하게 처리)
    bool negative = false;
    if (c == '-') { negative = true; c = _read(); }

    // 정수 부분 읽기
    while (c >= '0' && c <= '9') {
        integer_part = integer_part * 10 + (c - '0');
        c = _read();
    }

    // 소수점 처리
    if (c == '.') {
        c = _read();
        if (c >= '0' && c <= '9') {
            decimal_part = (c - '0') * 10;
            c = _read();
        } else {
            decimal_part = 0;
        }
        if (c >= '0' && c <= '9') {
            decimal_part += (c - '0');
        }
    }

    long long score = integer_part * 100 + decimal_part;
    if (negative) score = -score;
    return score;
}

int main(){
    // 빠른 입력을 통해 값 읽어오기
    int R_T = _readInt();
    int R_J = _readInt();
    long long S_T = _readScore();
    long long S_J = _readScore();

    // 비교를 위한 계산
    long long A = (long long)(R_T - 1) * S_J;
    long long B = (long long)(R_J - 1) * S_T;

    // 결과 출력 (빠른 출력을 위해 printf 사용)
    if(A < B){
        printf("TAOYUAN\n");
    }
    else if(A > B){
        printf("JAKARTA\n");
    }
    else{
        printf("SAME\n");
    }
}
