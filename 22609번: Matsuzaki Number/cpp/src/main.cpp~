#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "main.h"
using namespace std;

// Matsuzaki Number를 계산하는 함수 구현
int computeM(int N, int P) {
    // N보다 큰 소수를 충분히 구하기 위한 bound 설정
    int bound = max(N + 3000, 3000);
    vector<bool> isPrime(bound + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= bound; i++) {
        if(isPrime[i]){
            for (int j = i * i; j <= bound; j += i)
                isPrime[j] = false;
        }
    }
    
    // 에라토스테네스의 체로 소수를 추출
    vector<int> primes;
    for (int i = 2; i <= bound; i++) {
        if(isPrime[i]) primes.push_back(i);
    }
    
    // N보다 큰 소수 중 첫 200개 (또는 가능한 만큼)를 선택
    auto it = upper_bound(primes.begin(), primes.end(), N);
    vector<int> subPrimes;
    int cnt = 0;
    while(it != primes.end() && cnt < 200) {
        subPrimes.push_back(*it);
        ++it;
        cnt++;
    }
    
    // 선택된 소수들로부터 (i ≤ j)인 모든 쌍의 합을 계산
    vector<int> sums;
    for(size_t i = 0; i < subPrimes.size(); i++){
        for(size_t j = i; j < subPrimes.size(); j++){
            sums.push_back(subPrimes[i] + subPrimes[j]);
        }
    }
    
    // 오름차순 정렬 후, P번째 (1-indexed) 값을 반환
    sort(sums.begin(), sums.end());
    return sums[P - 1];
}

#ifndef UNIT_TESTS
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, P;
    while(cin >> N >> P) {
        if(N == -1 && P == -1) break;
        cout << computeM(N, P) << "\n";
    }
    
    return 0;
}
#endif

