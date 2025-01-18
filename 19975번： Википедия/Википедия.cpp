#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cctype>
#include <sstream>

using namespace std;

// 구조체 정의: 각 기사의 정보를 저장
struct Article {
    string title;
    vector<string> wordforms;
    vector<string> text_lines;
};

// 단어 정규화 함수: 첫 글자를 소문자로 변환
string normalize_word(const string& word) {
    if (word.empty()) return word;
    string normalized = word;
    normalized[0] = tolower(normalized[0]);
    return normalized;
}

// 텍스트 라인 처리 함수: 단어를 링크로 변환
string process_line(const string& line, const map<string, pair<string, bool>>& link_map) {
    string result;
    int n = line.size();
    int i = 0;
    
    while (i < n) {
        if (isalpha(line[i])) {
            // 단어의 시작
            int start = i;
            while (i < n && isalpha(line[i])) i++;
            string word = line.substr(start, i - start);
            
            // 단어 정규화
            string normalized = normalize_word(word);
            
            // 링크 매핑에서 단어 검색
            auto it = link_map.find(normalized);
            if (it != link_map.end()) {
                string title = it->second.first;
                bool is_title = it->second.second;
                
                if (is_title) {
                    // 제목과 동일한 경우: [[word]]
                    result += "[[" + word + "]]";
                }
                else {
                    // 단어형/동의어인 경우: [[Title|word]]
                    result += "[[" + title + "|" + word + "]]";
                }
            }
            else {
                // 매핑되지 않은 단어는 그대로 추가
                result += word;
            }
        }
        else {
            // 단어가 아닌 문자 그대로 추가
            result += line[i];
            i++;
        }
    }
    
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    cin.ignore(); // 남아있는 개행 문자 무시
    
    vector<Article> articles(n);
    
    // 모든 기사 정보 입력 받기
    for(int i = 0; i < n; i++) {
        // 기사 제목 입력
        getline(cin, articles[i].title);
        
        // 단어형/동의어 개수 입력
        string k_line;
        getline(cin, k_line);
        int k = stoi(k_line);
        
        // 단어형/동의어 입력
        for(int j = 0; j < k; j++) {
            string word;
            getline(cin, word);
            articles[i].wordforms.push_back(word);
        }
        
        // 텍스트 라인 개수 입력
        string l_line;
        getline(cin, l_line);
        int l = stoi(l_line);
        
        // 텍스트 라인 입력
        for(int j = 0; j < l; j++) {
            string text_line;
            getline(cin, text_line);
            articles[i].text_lines.push_back(text_line);
        }
    }
    
    // 각 기사별로 링크 변환 처리
    for(int i = 0; i < n; i++) {
        // 링크 대상 매핑 생성 (현재 기사 제외)
        map<string, pair<string, bool>> link_map;
        for(int j = 0; j < n; j++) {
            if(j == i) continue; // 자기 자신 제외
            
            // 다른 기사의 제목 추가 (is_title = true)
            string normalized_title = normalize_word(articles[j].title);
            // 여러 단어가 동일한 normalized_title일 경우, 우선 순위를 첫 번째로 나온 것으로 설정
            if(link_map.find(normalized_title) == link_map.end()) {
                link_map[normalized_title] = {articles[j].title, true};
            }
            
            // 다른 기사의 단어형/동의어 추가 (is_title = false)
            for(auto &wf : articles[j].wordforms) {
                string normalized_wf = normalize_word(wf);
                if(link_map.find(normalized_wf) == link_map.end()) {
                    link_map[normalized_wf] = {articles[j].title, false};
                }
            }
        }
        
        // 현재 기사의 제목 출력
        cout << articles[i].title << "\n";
        
        // 현재 기사의 텍스트 라인 처리 및 출력
        for(auto &line : articles[i].text_lines) {
            string processed_line = process_line(line, link_map);
            cout << processed_line << "\n";
        }
    }
    
    return 0;
}
