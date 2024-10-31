//=====================================================================
//   28125번:    2023 아주머학교 프로그래딩 정시머힌                   
//   @date:   2024-10-31              
//   @link:   https://www.acmicpc.net/problem/28125  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(){
    int N;
    cin >> N;
    // 단일 문자 치환 맵
    unordered_map<char, char> single_char_map = {
        {'@', 'a'},
        {'[', 'c'},
        {'!', 'i'},
        {';', 'j'},
        {'^', 'n'},
        {'0', 'o'},
        {'7', 't'}
    };
    
    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        string original_word = "";
        int modified_count = 0;
        int len = s.length();
        int j = 0;
        
        while(j < len){
            if(s[j] == '\\'){
                // 'w'는 "\\'"로 표현 (세 개의 문자: \, \, ')
                if(j+2 < len && s[j+1] == '\\' && s[j+2] == '\''){
                    original_word += 'w';
                    modified_count++;
                    j +=3;
                }
                // 'v'는 "\'"로 표현 (두 개의 문자: \, ')
                else if(j+1 < len && s[j+1] == '\''){
                    original_word += 'v';
                    modified_count++;
                    j +=2;
                }
                else{
                    // 치환되지 않은 백슬래시
                    original_word += s[j];
                    j +=1;
                }
            }
            else{
                // 단일 문자 치환 확인
                if(single_char_map.find(s[j]) != single_char_map.end()){
                    original_word += single_char_map[s[j]];
                    modified_count++;
                }
                else{
                    // 치환되지 않은 문자
                    original_word += s[j];
                }
                j +=1;
            }
        }
        
        int total_letters = original_word.length();
        // ceil(total_letters / 2)
        int half = (total_letters +1)/2;
        if(modified_count >= half){
            cout << "I don't understand\n";
        }
        else{
            cout << original_word << "\n";
        }
    }
    return 0;
}