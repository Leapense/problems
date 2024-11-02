#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <cctype>

using namespace std;

int main(){
    string word;
    // 기호 리스트
    vector<char> symbols = {'*', '?', '/', '+', '!'};
    
    while(getline(cin, word)){
        if(word == "#") break;
        
        // 소문자로 변환하여 카운트
        int counts[26] = {0};
        // 반복된 순서대로 문자를 저장
        vector<char> repeated_letters;
        // 문자 -> 기호 매핑
        unordered_map<char, char> symbol_map;
        int symbol_index = 0;
        string output = "";
        
        for(char ch : word){
            char lower_ch = tolower(ch);
            if(counts[lower_ch - 'a'] == 0){
                counts[lower_ch - 'a'] = 1;
                output += ch;
            }
            else{
                if(counts[lower_ch - 'a'] == 1){
                    // 처음 반복되는 문자라면 기호 할당
                    if(symbol_index < symbols.size()){
                        symbol_map[lower_ch] = symbols[symbol_index];
                        symbol_index++;
                    }
                }
                counts[lower_ch - 'a']++;
                // 기호가 할당된 경우 대체
                if(symbol_map.find(lower_ch) != symbol_map.end()){
                    output += symbol_map[lower_ch];
                }
                else{
                    // 기호가 할당되지 않은 경우 (문제 조건상 발생하지 않음)
                    output += ch;
                }
            }
        }
        cout << output << endl;
    }
    return 0;
}