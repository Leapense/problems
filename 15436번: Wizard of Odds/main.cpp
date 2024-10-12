//=====================================================================
//   15436번:    Wizard of Odds                   
//   @date:   2024-10-12              
//   @link:   https://www.acmicpc.net/problem/15436  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include<bits/stdc++.h>
using namespace std;

string divide_by_two(const string& num, int& remainder){
    string res;
    int carry = 0;
    for(char c : num){
        int digit = c - '0';
        int current = carry * 10 + digit;
        int q_digit = current / 2;
        carry = current % 2;
        if(!res.empty() || q_digit != 0){
            res += to_string(q_digit);
        }
    }
    if(res.empty()) res = "0";
    remainder = carry;
    return res;
}

string multiply_by_two(const string& num){
    string res;
    int carry = 0;
    for(int i = num.size()-1; i >=0; i--){
        int digit = num[i]-'0';
        int temp = digit * 2 + carry;
        carry = temp / 10;
        res += to_string(temp % 10);
    }
    if(carry > 0) res += to_string(carry);
    reverse(res.begin(), res.end());
    int start = 0;
    while(start < res.size()-1 && res[start]=='0') start++;
    return res.substr(start);
}

pair<int, bool> get_bit_length_and_is_power_of_two(string N){
    int cnt = 0;
    string current = N;
    while(current != "0"){
        int rem;
        current = divide_by_two(current, rem);
        cnt++;
    }
    string power = "1";
    for(int i=1;i<cnt;i++) power = multiply_by_two(power);
    bool is_power = (power == N);
    if(is_power) return {cnt-1, true};
    else return {cnt, false};
}

bool K_ge(const string& K, int ceil_log2_N){
    string target = to_string(ceil_log2_N);
    if(K.length() > target.length()) return true;
    if(K.length() < target.length()) return false;
    return K >= target;
}

int main(){
    string N, K;
    cin >> N >> K;
    pair<int, bool> result = get_bit_length_and_is_power_of_two(N);
    int ceil_log2_N = result.second ? result.first : result.first;
    if(result.second){
        ceil_log2_N = result.first;
    }
    else{
        ceil_log2_N = result.first;
    }
    bool possible = K_ge(K, ceil_log2_N);
    cout << (possible ? "Your wish is granted!" : "You will become a flying monkey!");
}
