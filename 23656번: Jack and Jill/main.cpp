#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MIN_VAL = 1;
    const int MAX_VAL = 1000000000;
    // 초기에 비밀 숫자로 가정할 candidate를 정함. (여기서는 30을 선택)
    int candidate = 30;
    int queryCount = 0;
    int x;
    
    // 인터랙티브하게 입력을 받음.
    while(cin >> x) {
        queryCount++;
        // 30번째 질문 이전
        if(queryCount < 30) {
            // 만약 Jack이 candidate와 같은 숫자를 물어보면,
            if(x == candidate) {
                // candidate를 가능한 방향으로 조정 (범위 내에서)
                if(candidate < MAX_VAL) {
                    candidate++; 
                    cout << ">" << "\n";
                } else if(candidate > MIN_VAL) {
                    candidate--;
                    cout << "<" << "\n";
                }
            } else if(x < candidate) {
                // x가 candidate보다 작으면, candidate가 더 크다는 의미
                cout << ">" << "\n";
            } else { // x > candidate
                cout << "<" << "\n";
            }
        } else { // 30번째 질문 이후
            if(x == candidate) {
                cout << "=" << "\n";
                // 게임 종료 후 프로그램 종료
                break;
            } else if(x < candidate) {
                cout << ">" << "\n";
            } else {
                cout << "<" << "\n";
            }
        }
        // 인터랙티브 환경에서 반드시 flush 필요
        cout.flush();
    }
    return 0;
}

