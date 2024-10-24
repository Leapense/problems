//=====================================================================
//   24872번:    Числа                   
//   @date:   2024-10-22              
//   @link:   https://www.acmicpc.net/problem/24872  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

// Function to check if string s is greater than or equal to string x
bool isGreaterOrEqual(const string &s, const string &x) {
    if (s.length() > x.length()) return true;
    if (s.length() < x.length()) return false;
    return s >= x;
}

// Function to check if string a is smaller than string b
bool isSmaller(const string &a, const string &b) {
    if (a.length() < b.length()) return true;
    if (a.length() > b.length()) return false;
    return a < b;
}

int main(){
    string x;
    cin >> x;
    int k;
    cin >> k;
    
    int len = x.length();
    vector<string> candidates;
    
    if(k == 0){
        // Generate numbers with all digits the same
        for(int ylen = len; ylen <= len+1; ylen++){
            for(char d = '1'; d <= '9'; d++){
                string s(ylen, d);
                candidates.push_back(s);
            }
        }
    }
    else if(k ==1){
        // Generate numbers with all digits the same
        for(int ylen = len; ylen <= len+1; ylen++){
            for(char d = '1'; d <= '9'; d++){
                string s(ylen, d);
                candidates.push_back(s);
            }
            // Generate numbers with all digits same except one
            for(char d = '0'; d <= '9'; d++){
                for(int p = 0; p < ylen; p++){
                    for(char e = '0'; e <= '9'; e++){
                        if(e == d) continue;
                        if(p == 0 && e == '0') continue;
                        if(d == '0' && p !=0) continue;
                        string s(ylen, d);
                        s[p] = e;
                        candidates.push_back(s);
                    }
                }
            }
        }
    }
    
    string min_y = "";
    
    for(auto &s : candidates){
        if(isGreaterOrEqual(s, x)){
            if(min_y.empty() || isSmaller(s, min_y)){
                min_y = s;
            }
        }
    }
    
    cout << min_y;
}