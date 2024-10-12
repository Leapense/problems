#include <bits/stdc++.h>
using namespace std;

bool is_vowel(char c){
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

string process_word(const string &word){
    string step1 = "";
    for(char c : word){
        if(step1.empty() || c != step1.back()){
            step1 += c;
        }
    }
    
    string step2 = "";
    bool prev_vowel = false;
    for(char c : step1){
        if(is_vowel(c)){
            if(!prev_vowel){
                step2 += c;
                prev_vowel = true;
            }
        }
        else{
            step2 += c;
            prev_vowel = false;
        }
    }
    
    string step3 = "";
    int n = step2.size();
    for(int i = 0; i < n; ++i){
        step3 += step2[i];
        if(i < n -1){
            if(!is_vowel(step2[i]) && !is_vowel(step2[i+1])){
                step3 += 'a';
            }
        }
    }

    if(n > 0 && !is_vowel(step2.back())){
        step3 += 'a';
    }

    string final_word = "";
    for(char c : step3){
        if(c == 'r'){
            final_word += 'l';
        }
        else if(c == 's'){
            final_word += 'k';
        }
        else{
            final_word += c;
        }
    }
    
    return final_word;
}

int main(){
    string input_line;
    getline(cin, input_line);

    vector<string> words;
    string word = "";
    for(char c : input_line){
        if(c == ' '){
            if(!word.empty()){
                words.push_back(word);
                word = "";
            }
        }
        else{
            word += c;
        }
    }
    if(!word.empty()){
        words.push_back(word);
    }

    vector<string> processed_words;
    for(auto &w : words){
        processed_words.push_back(process_word(w));
    }

    string output = "";
    for(int i = 0; i < processed_words.size(); ++i){
        output += processed_words[i];
        if(i != processed_words.size()-1){
            output += ' ';
        }
    }
    
    cout << output;
}