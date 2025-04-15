#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

// 기본 1글자 방향을 각도로 변환
double basicAngle(char c) {
    switch(c) {
        case 'N': return 0.0;
        case 'E': return 90.0;
        case 'S': return 180.0;
        case 'W': return 270.0;
    }
    return 0.0; // 기본값
}

// 2글자 방향을 각도로 변환
double twoLetterAngle(const string &s) {
    if(s == "NE") return 45.0;
    if(s == "SE") return 135.0;
    if(s == "SW") return 225.0;
    if(s == "NW") return 315.0;
    return 0.0; // 기본값 (문제 조건상 s는 항상 올바른 값임)
}

// 모듈로 360 연산 (음수 처리)
double mod360(double angle) {
    angle = fmod(angle, 360.0);
    if(angle < 0) angle += 360.0;
    return angle;
}

// 주어진 바람 방향 문자열을 각도로 변환 (반복적 방식으로 계산하여 재귀 깊이 문제 방지)
double convertWindDirection(const string &s) {
    int n = s.size();
    // 길이가 1이면 기본 방향
    if(n == 1) return basicAngle(s[0]);
    // 길이가 2이면 미리 정의된 표 사용
    if(n == 2) return twoLetterAngle(s);
    
    // 반복문을 이용하여 뒤에서부터 차례로 계산 (부분 문자열 s[i...n-1])
    // baseAngle는 가장 뒤의 2글자에 해당
    double angle = twoLetterAngle(s.substr(n-2, 2));
    
    // i: 현재 처리할 인덱스, s[i...n-1]의 길이는 L = n - i
    // i는 n-3부터 0까지
    for (int i = n - 3; i >= 0; i--) {
        int L = n - i; // 현재 부분 문자열의 길이 (최소 3)
        // offset = 360 / (2^(L+1))
        double offset = 360.0 / pow(2.0, L + 1);
        
        // s[i]는 첫 글자, 기본 각도
        double target = basicAngle(s[i]);
        
        // 현재 angle는 s[i+1...n-1]의 각도
        double diff = mod360(target - angle);
        // 이동 방향 결정: 0~180이면 시계 방향(+), 그 이상이면 반시계 방향(-)
        int sign = (diff <= 180.0 ? 1 : -1);
        
        // 업데이트: wind direction = (angle + sign * offset) mod 360
        angle = mod360(angle + sign * offset);
    }
    
    return angle;
}

// 두 각도 사이의 최소 각 차이 계산
double minimalTurn(double a, double b) {
    double diff = fabs(a - b);
    if(diff > 180.0) diff = 360.0 - diff;
    return diff;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string X, Y;
    cin >> X >> Y;
    
    double angleX = convertWindDirection(X);
    double angleY = convertWindDirection(Y);
    
    double answer = minimalTurn(angleX, angleY);
    cout << fixed << setprecision(6) << answer << "\n";
    
    return 0;
}
