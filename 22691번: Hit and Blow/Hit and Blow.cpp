#include<bits/stdc++.h>
using namespace std;

struct Number {
    string s;
    int mask;
} ;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<Number> numbers;
    for(int num=0; num<=9999; num++){
        string s = to_string(num);
        while(s.size() < 4) s = "0"+s;
        bool distinct=true;
        for(int i=0;i<4 && distinct;i++) for(int j=i+1;j<4 && distinct;j++) if(s[i]==s[j]) {distinct=false;}
        if(!distinct) continue;
        int mask=0;
        for(char c: s) mask |= 1 << (c - '0');
        numbers.push_back(Number{ s, mask });
    }
    int N;
    while(cin>>N && N){
        struct Attempt {
            string guess;
            int hits;
            int blows;
            int mask;
        };
        vector<Attempt> attempts(N);
        for(auto &p: attempts){
            cin>>p.guess>>p.hits>>p.blows;
            while(p.guess.size() <4) p.guess = "0" + p.guess;
            p.mask = 0;
            for(char c: p.guess) p.mask |= 1 << (c - '0');
        }
        vector<int> candidates;
        for(int i=0;i<numbers.size(); i++){
            bool ok=true;
            for(auto &p: attempts){
                int hits=0;
                for(int k=0; k<4; k++) if(numbers[i].s[k]==p.guess[k]) hits++;
                int common = __builtin_popcount(numbers[i].mask & p.mask);
                int blows = common - hits;
                if(hits != p.hits || blows != p.blows){ok=false; break;}
            }
            if(ok) candidates.push_back(i);
        }
        if(candidates.size() ==1){
            cout<<numbers[candidates[0]].s<<"\n";
            continue;
        }
        string min_critical = "9999";
        bool found=false;
        for(int i=0;i<numbers.size() && !found; i++){
            string guess = numbers[i].s;
            int guess_mask = numbers[i].mask;
            bool is_critical=true;
            bool feedback_seen[20] = {false};
            for(auto &c_idx: candidates){
                int hits=0;
                for(int k=0; k<4; k++) if(guess[k] == numbers[c_idx].s[k]) hits++;
                int common = __builtin_popcount(guess_mask & numbers[c_idx].mask);
                int blows = common - hits;
                int key = hits * 5 + blows;
                if(feedback_seen[key]) {is_critical=false; break;}
                feedback_seen[key] = true;
            }
            if(is_critical){
                min_critical = guess;
                found=true;
            }
        }
        if(found){
            cout<<min_critical<<"\n";
        }
        else{
            cout<<"????\n";
        }
    }
}