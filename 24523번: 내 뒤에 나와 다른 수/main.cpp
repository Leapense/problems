#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
    
    // 결과를 저장할 벡터 (0-indexed 내부 저장, -1은 변하지 않음)
    vector<int> result(N, -1);
    result[N-1] = -1;  // 마지막 원소는 항상 -1
    
    // 뒤에서부터 탐색
    for (int i = N - 2; i >= 0; i--){
        if (A[i] != A[i + 1]){
            result[i] = i + 1;  // 바로 뒤의 인덱스 (0-indexed)
        } else {
            result[i] = result[i + 1];  // 뒤쪽 결과를 그대로 할당
        }
    }
    
    // 출력 (문제에서는 1-indexed를 요구하므로, 결과가 -1이 아니라면 1을 더해 출력)
    for (int i = 0; i < N; i++){
        if(result[i] == -1)
            cout << -1 << " ";
        else
            cout << result[i] + 1 << " "; // 1-indexed로 변환
    }
    
    return 0;
}

