#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        string word;
        cin >> word;
        
        // 첫 글자가 대문자인지 확인
        bool isCapital = false;
        if(!word.empty() && isupper(word[0])){
            isCapital = true;
        }
        
        // 모든 문자를 소문자로 변환
        for(char &c : word){
            c = tolower(c);
        }
        
        // 's' 대체 규칙 적용
        string temp;
        int len = word.length();
        for(int i=0; i<len; ++i){
            if(word[i] == 's' && i != 0 && (i+1 >= len || word[i+1] != 'h')){
                temp += "th";
            }
            else{
                temp += word[i];
            }
        }
        word = temp;
        
        // 첫 글자가 'e'인 경우 'ae'로 대체
        if(!word.empty() && word[0] == 'e'){
            word = "ae" + word.substr(1);
        }
        
        // 'oo' 대체 규칙 적용
        temp = "";
        int i = 0;
        len = word.length();
        while(i < len){
            if(word[i] == 'o'){
                int count = 1;
                while(i + count < len && word[i + count] == 'o'){
                    count++;
                }
                if(count >= 2){
                    temp += "ou";
                    for(int j=2; j<count; ++j){
                        temp += "o";
                    }
                    i += count;
                }
                else{
                    temp += "o";
                    i += 1;
                }
            }
            else{
                temp += word[i];
                i +=1;
            }
        }
        word = temp;
        
        // 첫 글자가 대문자였으면 다시 대문자로 변환
        if(isCapital && !word.empty()){
            word[0] = toupper(word[0]);
        }
        
        cout << word << "\n";
    }
}