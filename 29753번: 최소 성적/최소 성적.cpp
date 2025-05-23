#include <bits/stdc++.h>
using namespace std;

// Function to map grade string to grade points multiplied by 1000
int get_grade_point(const string &grade) {
    if (grade == "A+") return 4500;
    if (grade == "A0") return 4000;
    if (grade == "B+") return 3500;
    if (grade == "B0") return 3000;
    if (grade == "C+") return 2500;
    if (grade == "C0") return 2000;
    if (grade == "D+") return 1500;
    if (grade == "D0") return 1000;
    if (grade == "F") return 0;
    return 0; // default, should not reach here
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    string X_str;
    cin >> N >> X_str;
    
    // Parse X_str to integer X_int (X * 100)
    int X_int = 0;
    size_t dot_pos = X_str.find('.');
    if(dot_pos == string::npos){
        // No decimal point
        X_int = stoi(X_str) * 100;
    }
    else{
        string integer_part = X_str.substr(0, dot_pos);
        string fractional_part = X_str.substr(dot_pos + 1);
        if(fractional_part.size() == 1){
            fractional_part += "0";
        }
        else if(fractional_part.size() == 0){
            fractional_part = "00";
        }
        else{
            fractional_part = fractional_part.substr(0,2);
        }
        X_int = stoi(integer_part) * 100 + stoi(fractional_part);
    }
    
    // Define grade list from worst to best
    vector<string> grade_list = {"F", "D0", "D+", "C0", "C+", "B0", "B+", "A0", "A+"};
    
    // Read N-1 courses
    long long sum_gp = 0;
    long long sum_ci = 0;
    for(int i=0;i<N-1;i++){
        int ci;
        string gi;
        cin >> ci >> gi;
        sum_gp += (long long)ci * get_grade_point(gi);
        sum_ci += ci;
    }
    
    // Read L
    int L;
    cin >> L;
    
    long long sum_total = sum_ci + L;
    
    // Iterate through grades from worst to best
    string result = "impossible";
    for(auto &grade: grade_list){
        int G = get_grade_point(grade);
        long long sum_gp_new = sum_gp + (long long)L * G;
        long long A = sum_gp_new / sum_total; // floor division
        long long avg_truncated_two = A / 10; // floor(A /10)
        if(avg_truncated_two > X_int){
            result = grade;
            break;
        }
    }
    
    cout << result;
}