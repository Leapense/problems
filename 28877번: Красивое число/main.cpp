//=====================================================================
//   28877번:    Красивое число                   
//   @date:   2024-11-03              
//   @link:   https://www.acmicpc.net/problem/28877  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

bool less_or_equal(const string &a, const string &b) {
    if(a.length() != b.length()) return a.length() < b.length();
    return a <= b;
}

string subtract_strings(string a, string b) {
    string result = a;
    int carry = 0;
    for(int i = a.length()-1; i >=0; i--){
        int digit_a = a[i] - '0';
        int digit_b = b[i] - '0';
        int sub = digit_a - digit_b - carry;
        if(sub < 0){
            sub += 10;
            carry = 1;
        }
        else{
            carry = 0;
        }
        result[i] = sub + '0';
    }
    int first_non_zero = 0;
    while(first_non_zero < result.length()-1 && result[first_non_zero] == '0') first_non_zero++;
    return result.substr(first_non_zero);
}

string find_largest_beautiful(const string &x, int n) {
    for(char d = '9'; d >= '1'; d--){
        for(int len = n; len >=1; len--){
            if(len > x.length()) continue;
            string y_digits = string(len, d);
            string y_padded = "";
            if(n > len) y_padded = string(n - len, '0') + y_digits;
            else y_padded = y_digits;
            if(less_or_equal(y_padded, x)){
                return y_digits;
            }
        }
    }
    return "0";
}

int main(){
    string x;
    cin >> x;
    int n = x.length();
    vector<string> summands;
    while(true){
        bool all_zero = true;
        for(char c: x) if(c != '0'){all_zero = false; break;}
        if(all_zero) break;
        string y_digits = find_largest_beautiful(x, n);
        string y_padded = "";
        if(n > y_digits.length()) y_padded = string(n - y_digits.length(), '0') + y_digits;
        else y_padded = y_digits;
        x = subtract_strings(x, y_padded);
        while(x.length() < n) x = "0" + x;
        summands.push_back(y_digits);
    }
    cout << summands.size() << "\n";
    for(int i=0;i<summands.size();i++) {
        if(i >0) cout << " ";
        // Remove leading zeros in summands
        int first_non_zero = 0;
        while(first_non_zero < summands[i].length()-1 && summands[i][first_non_zero] == '0') first_non_zero++;
        cout << summands[i].substr(first_non_zero);
    }
}
