//=====================================================================
//   24308번:    ПРОМЕНЍ ЧИСЛОТО                   
//   @date:   2024-10-20              
//   @link:   https://www.acmicpc.net/problem/24308  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    char sign = '+';
    if(s[0] == '-' || s[0] == '+'){
        sign = s[0];
        s = s.substr(1);
    }
    int n = s.size();
    string best = "";
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            for(char di='0'; di<='9'; di++) {
                for(char dj='0'; dj<='9'; dj++) {
                    if(di == s[i] && dj == s[j]) continue;
                    if(di == s[i] || dj == s[j]) continue;
                    if(i ==0 && di == '0') continue;
                    if(j ==0 && dj == '0') continue;
                    string temp = s;
                    temp[i] = di;
                    temp[j] = dj;
                    int sum =0;
                    for(char c: temp) sum += c - '0';
                    if( ( (temp.back()-'0')%2 ==0 ) && (sum %3 ==0 ) ){
                        if(best.empty()){
                            best = temp;
                        }
                        else{
                            if(sign != '-'){
                                if(temp > best){
                                    best = temp;
                                }
                            }
                            else{
                                if(temp < best){
                                    best = temp;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(sign == '-'){
        cout<<'-'<<best;
    }
    else{
        cout<<best;
    }
}
