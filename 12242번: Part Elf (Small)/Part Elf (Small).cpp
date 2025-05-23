#include <bits/stdc++.h>
using namespace std;

// x가 2의 거듭제곱인지(양의 정수) 판별하는 함수
bool isPowerOfTwo(long long x) {
    return x > 0 && (x & (x - 1)) == 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    for(int t = 1; t <= T; t++) {
        string fraction;
        cin >> fraction;  // 예: "3/4"
        
        // P/Q 파싱
        int pos = fraction.find('/');
        long long P = stoll(fraction.substr(0, pos));
        long long Q = stoll(fraction.substr(pos + 1));

        // 1) 먼저 P/Q를 기약분수 형태로 만들기
        long long g = std::gcd(P, Q);
        P /= g;
        Q /= g;

        // 2) Q가 2의 거듭제곱인지 확인
        if(!isPowerOfTwo(Q)) {
            cout << "Case #" << t << ": impossible\n";
            continue;
        }

        // 3) 최소 세대 수 계산
        //    2^gen * P >= Q를 만족하는 최소 gen 찾기
        int gen = 0;
        long long cur = P;
        while(cur < Q) {
            cur <<= 1; 
            gen++;
        }

        // 4) 세대 수가 40을 초과하면 불가능
        if(gen > 40) {
            cout << "Case #" << t << ": impossible\n";
        } else {
            cout << "Case #" << t << ": " << gen << "\n";
        }
    }
    return 0;
}