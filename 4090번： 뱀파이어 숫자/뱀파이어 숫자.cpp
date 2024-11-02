#include <bits/stdc++.h>
using namespace std;

// 뱀파이어 숫자인지 확인하는 함수
bool isVampire(int v) {
    // 각 숫자의 개수를 4비트씩 저장하기 위해 64비트 정수 사용
    unsigned long long counts_v = 0;
    int temp_v = v;
    while(temp_v > 0){
        int d = temp_v % 10;
        // 현재 d의 개수 추출
        int current = (counts_v >> (d * 4)) & 0xF;
        current += 1;
        // 이전 개수 지우기
        counts_v &= ~(0xFULL << (d * 4));
        // 새로운 개수 설정
        counts_v |= ((unsigned long long)current << (d * 4));
        temp_v /= 10;
    }
    
    // a를 1부터 sqrt(v)까지 반복
    for(int a = 1; a * a <= v; a++){
        if(v % a != 0) continue; // a가 v의 약수가 아니면 건너뜀
        int b = v / a;
        
        // a의 숫자 개수 계산
        unsigned long long counts_a = 0;
        int temp_a = a;
        while(temp_a > 0){
            int d = temp_a % 10;
            int current = (counts_a >> (d * 4)) & 0xF;
            current += 1;
            counts_a &= ~(0xFULL << (d * 4));
            counts_a |= ((unsigned long long)current << (d * 4));
            temp_a /= 10;
        }
        
        // b의 숫자 개수 계산
        unsigned long long counts_b = 0;
        int temp_b = b;
        while(temp_b > 0){
            int d = temp_b % 10;
            int current = (counts_b >> (d * 4)) & 0xF;
            current += 1;
            counts_b &= ~(0xFULL << (d * 4));
            counts_b |= ((unsigned long long)current << (d * 4));
            temp_b /= 10;
        }
        
        // a와 b의 숫자 개수가 v의 숫자 개수와 일치하는지 확인
        bool match = true;
        for(int d = 0; d < 10; d++){
            int count_a = (counts_a >> (d * 4)) & 0xF;
            int count_b = (counts_b >> (d * 4)) & 0xF;
            int count_v = (counts_v >> (d * 4)) & 0xF;
            if(count_a + count_b != count_v){
                match = false;
                break;
            }
        }
        
        if(match){
            return true; // 뱀파이어 숫자임
        }
    }
    
    return false; // 뱀파이어 숫자가 아님
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(true){
        int X;
        cin >> X;
        if(X == 0) break; // 입력 종료 조건
        
        int v = X;
        while(true){
            if(isVampire(v)){
                cout << v << "\n";
                break;
            }
            v++;
        }
    }
}
