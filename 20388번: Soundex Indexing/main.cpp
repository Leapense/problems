//=====================================================================
//   20388번:    Soundex Indexing                   
//   @date:   2024-10-15              
//   @link:   https://www.acmicpc.net/problem/20388  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    // Initialize mapping for A-Z
    int mapping[26];
    fill(mapping, mapping+26, 0);
    // Code 1
    for(char c: {'B','P','F','V'}) mapping[c-'A'] = 1;
    // Code 2
    for(char c: {'C','S','K','G','J','Q','X','Z'}) mapping[c-'A'] = 2;
    // Code 3
    for(char c: {'D','T'}) mapping[c-'A'] = 3;
    // Code 4
    mapping['L'-'A'] = 4;
    // Code 5
    for(char c: {'M','N'}) mapping[c-'A'] = 5;
    // Code 6
    mapping['R'-'A'] = 6;
    
    // Read all names
    vector<string> names;
    string s;
    while(getline(cin, s)){
        if(s.empty()) continue;
        names.push_back(s);
    }
    
    // Output header
    string header = "         NAME                     SOUNDEX CODE";
    cout << header << "\n";
    
    // Process each name
    for(auto &name: names){
        if(name.empty()) continue;
        string code = "";
        // First letter
        char first = name[0];
        code += first;
        // Previous code digit
        int prev = mapping[first-'A'];
        // Collect digits
        string digits = "";
        for(int i=1;i<name.size();i++){
            char c = name[i];
            if(c < 'A' || c > 'Z') continue;
            int current = mapping[c-'A'];
            if(current ==0){
                prev = 0;
                continue;
            }
            if(current != prev){
                digits += to_string(current);
                if(digits.size() ==3) break;
                prev = current;
            }
            else{
                prev = current;
            }
        }
        // Pad with zeros
        while(digits.size() <3) digits += '0';
        if(digits.size() >3) digits = digits.substr(0,3);
        code += digits;
        // Format output
        string line = "";
        line += "         " + name;
        // Calculate spaces to reach column 35
        int current_length = 9 + name.size();
        int spaces = 34 - current_length;
        line += string(max(1, spaces), ' ') + code;
        cout << line << "\n";
    }
    // Output end comment
    cout << "                   END OF OUTPUT";
}