#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> types(n);
    for(auto &x: types) cin >> x;
    string s;
    getline(cin, s);
    while(s.empty()) getline(cin, s);
    long long space_cnt=0, number_cnt=0, word_cnt=0, sentence_cnt=0, palindrome_cnt=0;
    bool in_number=false, in_word=false;
    string current_word;
    int sentence_word_count=0;
    for(char c: s){
        if(c == ' ' || c == '\t') space_cnt++;
        if(isdigit(c)){
            if(!in_number){
                in_number=true;
                number_cnt++;
            }
        }
        else{
            in_number=false;
        }
        if(isalpha(c)){
            if(!in_word){
                in_word=true;
                word_cnt++;
                current_word = "";
                sentence_word_count++;
            }
            current_word += c;
        }
        else{
            if(in_word){
                string tmp = current_word;
                bool is_palindrome=true;
                int len = tmp.size();
                for(int i=0;i<len/2;i++) if(tolower(tmp[i]) != tolower(tmp[len-1-i])) {is_palindrome=false; break;}
                if(is_palindrome) palindrome_cnt++;
                in_word=false;
            }
            if(c == '.'){
                if(sentence_word_count >=1){
                    sentence_cnt++;
                }
                sentence_word_count=0;
            }
        }
    }
    if(in_word){
        string tmp = current_word;
        bool is_palindrome=true;
        int len = tmp.size();
        for(int i=0;i<len/2;i++) if(tolower(tmp[i]) != tolower(tmp[len-1-i])) {is_palindrome=false; break;}
        if(is_palindrome) palindrome_cnt++;
    }
    vector<long long> results;
    for(auto a: types){
        if(a ==1) results.push_back(space_cnt);
        if(a ==2) results.push_back(number_cnt);
        if(a ==3) results.push_back(word_cnt);
        if(a ==4) results.push_back(sentence_cnt);
        if(a ==5) results.push_back(palindrome_cnt);
    }
    for(int i=0;i<results.size();i++) cout << results[i] << (i<results.size()-1?" ":"\n");
}
