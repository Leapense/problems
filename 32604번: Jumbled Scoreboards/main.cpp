//=====================================================================
//   32604번:    Jumbled Scoreboards                   
//   @date:   2024-10-31              
//   @link:   https://www.acmicpc.net/problem/32604  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    // 입력 제한 확인 (필요에 따라 생략 가능)
    if(n < 1 || n > 100){
        // 문제의 입력 제한을 벗어나는 경우
        return 0;
    }
    
    int a, b;
    cin >> a >> b;
    int prev_a = a, prev_b = b;
    
    bool isChronological = true;
    
    for(int i = 1; i < n; i++){
        cin >> a >> b;
        // 이전 점수보다 현재 점수가 같거나 증가했는지 확인
        if(a < prev_a || b < prev_b){
            isChronological = false;
            break;
        }
        prev_a = a;
        prev_b = b;
    }
    
    if(isChronological){
        cout << "yes\n";
    }
    else{
        cout << "no\n";
    }
    
    return 0;
}
