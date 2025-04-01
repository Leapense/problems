#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 데이터셋을 저장할 벡터와 최대 N 값을 추출
    vector<pair<int, int>> datasets;
    int N, P;
    int maxN = 0;
    while(cin >> N >> P) {
        if(N == -1 && P == -1) break;
        datasets.push_back({N, P});
        maxN = max(maxN, N);
    }
    
    // N의 최대값에 대해 충분한 범위까지 소수를 구하기 위한 bound 설정
    int bound = max(maxN + 3000, 3000);
    vector<bool> isPrime(bound + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= bound; i++){
        if(isPrime[i]){
            for (int j = i * i; j <= bound; j += i)
                isPrime[j] = false;
        }
    }
    
    // 에라토스테네스의 체로 구한 소수를 벡터에 저장
    vector<int> primes;
    for (int i = 2; i <= bound; i++){
        if(isPrime[i]) primes.push_back(i);
    }
    
    // 각 데이터셋 처리
    for(auto &data : datasets){
        int currentN = data.first;
        int currentP = data.second;
        
        // N보다 큰 소수를 찾는다.
        auto it = upper_bound(primes.begin(), primes.end(), currentN);
        // 첫 200개의 소수를 추출 (충분한 수만큼)
        vector<int> subPrimes;
        int cnt = 0;
        while(it != primes.end() && cnt < 200){
            subPrimes.push_back(*it);
            ++it; 
            cnt++;
        }
        
        // 소수 두 개의 합을 모두 계산 (i <= j)
        vector<int> sums;
        for(size_t i = 0; i < subPrimes.size(); i++){
            for(size_t j = i; j < subPrimes.size(); j++){
                sums.push_back(subPrimes[i] + subPrimes[j]);
            }
        }
        
        // 오름차순으로 정렬
        sort(sums.begin(), sums.end());
        
        // P번째 원소 출력 (1-indexed)
        cout << sums[currentP - 1] << "\n";
    }
    
    return 0;
}

