//=====================================================================
//   19878번:    Летопись                   
//   @date:   2024-10-14              
//   @link:   https://www.acmicpc.net/problem/19878  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
    string input;
    cin>>input;
    vector<string> parts;
    string s="";
    for(char c: input){
        if(c != '/'){
            s += c;
        }
        else{
            parts.push_back(s);
            s="";
        }
    }
    parts.push_back(s);
    vector<int> nums;
    for(auto &p: parts){
        nums.push_back(stoi(p));
    }
    vector<string> dates;
    set<string> seen;
    vector<vector<int>> perms = {
        {nums[0], nums[1], nums[2]},
        {nums[0], nums[2], nums[1]},
        {nums[1], nums[0], nums[2]},
        {nums[1], nums[2], nums[0]},
        {nums[2], nums[0], nums[1]},
        {nums[2], nums[1], nums[0]}
    };
    for(auto &perm: perms){
        int dd = perm[0];
        int mm = perm[1];
        int yy = perm[2];
        if(mm <1 || mm >12) continue;
        int year = 2000 + yy;
        if(yy == 0){
            year = 2100;
        }
        if(year <2001 || year >2100) continue;
        bool leap = false;
        if( (year %4 ==0 && year %100 !=0) || (year %400 ==0)){
            leap = true;
        }
        int days;
        if(mm ==1 || mm ==3 || mm ==5 || mm ==7 || mm ==8 || mm ==10 || mm ==12){
            days =31;
        }
        else if(mm ==2){
            days = leap ? 29 : 28;
        }
        else{
            days =30;
        }
        if(dd <1 || dd >days) continue;
        string date = "";
        if(dd <10) date += "0";
        date += to_string(dd) + "/";
        if(mm <10) date += "0";
        date += to_string(mm) + "/";
        if(yy <10) date += "0";
        date += to_string(yy);
        if(seen.find(date)==seen.end()){
            dates.push_back(date);
            seen.insert(date);
        }
    }
    if(dates.empty()){
        cout<<"No such date";
    }
    else{
        for(auto &d: dates){
            cout<<d<<'\n';
        }
    }
}
