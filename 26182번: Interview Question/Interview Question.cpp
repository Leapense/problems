#include <iostream>
#include <vector>
#include <string>
#include <cmath>       // sqrt 함수 사용
#include <algorithm>   // sort 함수 사용
#include <vector>      // vector 사용 명시

using namespace std;

// 후보 'a'가 트랜스크립트의 'a' 관련 조건을 모두 만족하는지 확인하는 함수
bool check_a(long long a, int c, int d, const vector<string>& transcript) {
    // a는 1 이상이어야 함
    if (a <= 0) return false; 
    int n = transcript.size();
    for (int i = 0; i < n; ++i) {
        long long num = (long long)c + i; // 현재 숫자
        const string& entry = transcript[i]; // 해당 숫자의 트랜스크립트 항목

        // entry가 "Fizz" 또는 "FizzBuzz" 인지 여부 (a로 나누어 떨어져야 함)
        bool required_a_multiple = (entry == "Fizz" || entry == "FizzBuzz");
        // 실제로 a로 나누어 떨어지는지 여부
        bool is_a_multiple = (num % a == 0);

        // 요구 조건과 실제 결과가 다르면 이 a는 유효하지 않음
        if (required_a_multiple != is_a_multiple) {
            return false; 
        }
    }
    // 모든 항목에 대해 조건을 만족하면 유효한 a
    return true; 
}

// 후보 'b'가 트랜스크립트의 'b' 관련 조건을 모두 만족하는지 확인하는 함수
bool check_b(long long b, int c, int d, const vector<string>& transcript) {
    // b는 1 이상이어야 함
    if (b <= 0) return false;
    int n = transcript.size();
    for (int i = 0; i < n; ++i) {
        long long num = (long long)c + i; // 현재 숫자
        const string& entry = transcript[i]; // 해당 숫자의 트랜스크립트 항목

        // entry가 "Buzz" 또는 "FizzBuzz" 인지 여부 (b로 나누어 떨어져야 함)
        bool required_b_multiple = (entry == "Buzz" || entry == "FizzBuzz");
        // 실제로 b로 나누어 떨어지는지 여부
        bool is_b_multiple = (num % b == 0);

        // 요구 조건과 실제 결과가 다르면 이 b는 유효하지 않음
        if (required_b_multiple != is_b_multiple) {
            return false;
        }
    }
    // 모든 항목에 대해 조건을 만족하면 유효한 b
    return true;
}


int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c, d;
    cin >> c >> d; // 구간 시작 c, 끝 d 입력

    int n = d - c + 1; // 트랜스크립트 길이
    vector<string> transcript(n); // 트랜스크립트 저장 벡터
    for (int i = 0; i < n; ++i) {
        cin >> transcript[i]; // 트랜스크립트 항목 입력
    }

    long long found_a = -1; // 찾은 a 값
    long long num_a = -1; // 'a'의 배수여야 하는 첫 번째 숫자

    // 'a'의 배수여야 하는 첫 번째 숫자 찾기
    for (int i = 0; i < n; ++i) {
        if (transcript[i] == "Fizz" || transcript[i] == "FizzBuzz") {
            num_a = (long long)c + i;
            break;
        }
    }

    if (num_a == -1) {
        // "Fizz" 또는 "FizzBuzz"가 없으면 d+1이 유효한 a 값임
        found_a = d + 1;
    } else {
        // num_a의 약수 찾기
        vector<long long> divisors_a;
        long long limit_a = sqrt(num_a);
        for (long long i = 1; i <= limit_a; ++i) {
            if (num_a % i == 0) {
                divisors_a.push_back(i);
                if (i * i != num_a) {
                    divisors_a.push_back(num_a / i);
                }
            }
        }
        sort(divisors_a.begin(), divisors_a.end()); // 작은 약수부터 확인하기 위해 정렬

        // 약수들을 후보로 하여 전체 트랜스크립트 검증
        for (long long cand_a : divisors_a) {
            if (check_a(cand_a, c, d, transcript)) {
                found_a = cand_a; // 가장 작은 유효한 약수를 찾으면 종료
                break; 
            }
        }
    }

    // --- 'b'에 대해 동일한 로직 적용 ---

    long long found_b = -1; // 찾은 b 값
    long long num_b = -1; // 'b'의 배수여야 하는 첫 번째 숫자

    // 'b'의 배수여야 하는 첫 번째 숫자 찾기
    for (int i = 0; i < n; ++i) {
        if (transcript[i] == "Buzz" || transcript[i] == "FizzBuzz") {
            num_b = (long long)c + i;
            break;
        }
    }

    if (num_b == -1) {
        // "Buzz" 또는 "FizzBuzz"가 없으면 d+1이 유효한 b 값임
        found_b = d + 1;
    } else {
        // num_b의 약수 찾기
        vector<long long> divisors_b;
        long long limit_b = sqrt(num_b);
        for (long long i = 1; i <= limit_b; ++i) {
            if (num_b % i == 0) {
                divisors_b.push_back(i);
                if (i * i != num_b) {
                    divisors_b.push_back(num_b / i);
                }
            }
        }
        sort(divisors_b.begin(), divisors_b.end()); // 작은 약수부터 확인

        // 약수들을 후보로 하여 전체 트랜스크립트 검증
        for (long long cand_b : divisors_b) {
            if (check_b(cand_b, c, d, transcript)) {
                found_b = cand_b; // 가장 작은 유효한 약수를 찾으면 종료
                break; 
            }
        }
    }

    // 찾은 a와 b 출력
    cout << found_a << " " << found_b << endl;

    return 0;
}