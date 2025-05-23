#include <bits/stdc++.h>
using namespace std;

int main(){
    // 실제 아이템의 색상 정의
    map<string, string> real_color = {
        {"Barabashka", "white"},
        {"book", "blue"},
        {"chair", "red"},
        {"mouse", "gray"},
        {"bottle", "green"}
    };
    
    // 색상과 아이템 이름의 집합 정의
    set<string> colors = {"white", "blue", "red", "gray", "green"};
    set<string> items = {"Barabashka", "book", "chair", "mouse", "bottle"};
    
    // 입력된 다섯 문장 처리
    for(int i=0;i<5;i++){
        string sentence;
        getline(cin, sentence);
        
        // 단어 추출
        vector<string> words;
        string word = "";
        for(char c: sentence){
            if( (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
                word += c;
            }
            else{
                if(!word.empty()){
                    words.push_back(word);
                    word = "";
                }
            }
        }
        if(!word.empty()) words.push_back(word);
        
        // 색상-아이템 쌍 추출
        vector<pair<string, string>> pairs;
        for(int j=0; j < (int)words.size()-1; j++){
            if(colors.find(words[j]) != colors.end() && items.find(words[j+1]) != items.end()){
                pairs.emplace_back(words[j], words[j+1]);
            }
        }
        
        // 일치하는 쌍 찾기
        vector<pair<string, string>> matched;
        for(auto &p: pairs){
            if(p.first == real_color[p.second]){
                matched.emplace_back(p);
            }
        }
        
        if(matched.size() == 1){
            // 일치하는 쌍이 하나인 경우
            cout << real_color[matched[0].second] << " " << matched[0].second << "\n";
        }
        else{
            // 일치하는 쌍이 없는 경우
            // 카드에 있는 아이템과 색상 수집
            set<string> card_items;
            set<string> card_colors;
            for(auto &p: pairs){
                card_items.insert(p.second);
                card_colors.insert(p.first);
            }
            // 카드에 없는 아이템 중 실제 색상이 카드 색상에 없는 아이템 찾기
            string answer_color, answer_item;
            for(auto &item: items){
                if(card_items.find(item) == card_items.end()){
                    string r_color = real_color[item];
                    if(card_colors.find(r_color) == card_colors.end()){
                        answer_color = r_color;
                        answer_item = item;
                        break;
                    }
                }
            }
            cout << answer_color << " " << answer_item << "\n";
        }
    }
}