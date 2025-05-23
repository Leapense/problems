#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    string S;
    cin >> S;
    // Mapping from grade string to index
    unordered_map<string, int> grade_to_idx = {
        {"A+", 0}, {"A0",1}, {"A-",2},
        {"B+",3}, {"B0",4}, {"B-",5},
        {"C+",6}, {"C0",7}, {"C-",8}
    };
    // Parse the input string into grades
    vector<int> grades;
    int i=0;
    while(i < S.size() && grades.size() < N){
        char c = S[i];
        if(c == 'A' || c == 'B' || c == 'C'){
            if(i+1 < S.size() && (S[i+1] == '+' || S[i+1] == '-')){
                string grade = "";
                grade += c;
                grade += S[i+1];
                if(grade_to_idx.find(grade) != grade_to_idx.end()){
                    grades.push_back(grade_to_idx[grade]);
                    i +=2;
                }
                else{
                    // Invalid, treat as 'A0','B0','C0'
                    string grade0 = "";
                    grade0 += c;
                    grade0 += '0';
                    grades.push_back(grade_to_idx[grade0]);
                    i +=1;
                }
            }
            else{
                string grade0 = "";
                grade0 += c;
                grade0 += '0';
                grades.push_back(grade_to_idx[grade0]);
                i +=1;
            }
        }
        else{
            // Invalid character, skip or handle error
            // According to problem statement, input is valid
            // So, we can assume this won't happen
            i +=1;
        }
    }
    // Now, build the new_grade_map
    // new_grade_map[current_grade][previous_grade] = 'B','D','P','E'
    // previous_grade: 0-8 for 'A+',..., 'C-', 9 for no previous
    vector<vector<char>> new_grade_map(9, vector<char>(10, 'B'));
    // current_grade =0: 'A+'
    for(int prev=0; prev<10; prev++) new_grade_map[0][prev] = 'E';
    // current_grade=1: 'A0'
    for(int prev=0; prev<10; prev++){
        if(prev ==0 || prev ==1){
            new_grade_map[1][prev] = 'P';
        }
        else{
            new_grade_map[1][prev] = 'E';
        }
    }
    // current_grade=2: 'A-'
    for(int prev=0; prev<10; prev++){
        if(prev ==9 || prev ==4 || prev ==5 || prev ==6 || prev ==7 || prev ==8){
            new_grade_map[2][prev] = 'P';
        }
        else if(prev ==0 || prev ==1 || prev ==2 || prev ==3){
            new_grade_map[2][prev] = 'D';
        }
    }
    // current_grade=3: 'B+'
    for(int prev=0; prev<10; prev++){
        if(prev ==9 || prev ==4 || prev ==5 || prev ==6 || prev ==7 || prev ==8){
            new_grade_map[3][prev] = 'P';
        }
        else if(prev ==0 || prev ==1 || prev ==2 || prev ==3){
            new_grade_map[3][prev] = 'D';
        }
    }
    // current_grade=4: 'B0'
    for(int prev=0; prev<10; prev++){
        if(prev >=6 && prev <=8){
            new_grade_map[4][prev] = 'D';
        }
        else if(prev ==9){
            new_grade_map[4][prev] = 'D';
        }
        else{
            new_grade_map[4][prev] = 'B';
        }
    }
    // current_grade=5: 'B-'
    for(int prev=0; prev<10; prev++){
        if(prev >=6 && prev <=8){
            new_grade_map[5][prev] = 'D';
        }
        else if(prev ==9){
            new_grade_map[5][prev] = 'D';
        }
        else{
            new_grade_map[5][prev] = 'B';
        }
    }
    // current_grade=6,7,8: 'C+', 'C0', 'C-'
    for(int current=6; current<=8; current++){
        for(int prev=0; prev<10; prev++) new_grade_map[current][prev] = 'B';
    }
    // Now, process the grades
    string result = "";
    int prev_grade = 9; // 9 represents no previous (first semester)
    for(int j=0; j<grades.size(); j++){
        int current = grades[j];
        char new_grade = new_grade_map[current][prev_grade];
        result += new_grade;
        prev_grade = current;
    }
    cout << result;
}