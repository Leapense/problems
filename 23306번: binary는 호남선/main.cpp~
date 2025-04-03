#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    int firstBit, lastBit;
    
    // 첫 번째 철로 확인
    cout << "? " << 1 << "\n";
    cout.flush();
    cin >> firstBit;
    
    // 마지막 철로 확인
    cout << "? " << N << "\n";
    cout.flush();
    cin >> lastBit;
    
    int result = lastBit - firstBit; // 오르막 구간 개수 - 내리막 구간 개수
    
    // 결과 출력: 1 (오르막 많음), 0 (같음), -1 (내리막 많음)
    cout << "! " << (result > 0 ? 1 : (result < 0 ? -1 : 0)) << "\n";
    cout.flush();
    
    return 0;
}

