#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
    
    // 이미 오름차순임: a[0]가 최소값
    int minVal = a[0];
    // 총 합 계산
    long long sum = 0;
    for (int i = 0; i < N; i++){
        sum += a[i];
    }
    
    // 최소값과 같은 통의 개수
    int countMin = 0;
    for (int i = 0; i < N; i++){
        if(a[i] == minVal) countMin++;
        else break; // 오름차순이므로 처음에만 연속됨.
    }
    
    // 먹을 수 있는 초콜릿의 최대 개수
    long long maxEaten = sum - 1LL * N * minVal;
    // 최소 날짜는 (N - countMin)
    int days = N - countMin;
    
    cout << maxEaten << " " << days << "\n";
    return 0;
}
