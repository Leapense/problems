//=====================================================================
//   23731번:    Physics Experiment                   
//   @date:   2024-10-20              
//   @link:   https://www.acmicpc.net/problem/23731  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
using namespace std;

int main() {
    unsigned long long N;
    cin >> N;
    unsigned long long N_max = N;
    unsigned long long factors[19];
    factors[0] = 1;
    for (int i = 1; i <= 18; i++) {
        factors[i] = factors[i - 1] * 10;
    }
    bool found = true;
    while (found) {
        found = false;
        for (int p = 1; p <= 18; p++) {
            unsigned long long factor = factors[p];
            if (factor / 10 == 0) continue; // Prevent division by zero
            unsigned long long digit = (N_max / (factor / 10)) % 10;
            unsigned long long N_new;
            if (digit >= 5) {
                N_new = ((N_max / factor) + 1) * factor;
            } else {
                N_new = (N_max / factor) * factor;
            }
            if (N_new > N_max) {
                N_max = N_new;
                found = true;
                break;
            }
        }
    }
    cout << N_max << endl;
    return 0;
}
