#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    int T;
    cin >> T;
    
    if (T == 1) {
        // 갑의 역할: A와 B를 받아서 문자열 생성
        long long A, B;
        cin >> A >> B;
        
        long long sum = A + B;
        string result = "aaaaaaaaaaaaa";

        for (int i = 0; i < result.size(); i++) {
            if (sum) {
                result[i] = ((sum % 26) + 'a');
                sum /= 26;
            } else {
                break;
            }
        }
        
        cout << result << endl;
    } else if (T == 2) {
        // 을의 역할: 문자열에서 A + B 구하기
        string input;
        cin >> input;

        long long ans = 0;
        long long r = 1;

        for (int i = 0; i < input.size(); i++) {
            ans += (input[i] - 'a') * r;
            r *= 26;
        }

        cout << ans << "\n";
    }
    
    return 0;
}