#include<bits/stdc++.h>
using namespace std;

pair<int,int> get_hit_and_blow(const string &secret, const string &guess){
    int hits=0, blows=0;
    vector<bool> s_used(4, false);
    vector<bool> g_used(4, false);
    for(int i=0;i<4;i++) if(secret[i]==guess[i]) {hits++; s_used[i]=true; g_used[i]=true;}
    for(int i=0;i<4;i++) if(!g_used[i]){
        for(int j=0;j<4;j++) if(!s_used[j] && guess[i]==secret[j]){
            blows++; s_used[j]=true; break;
        }
    }
    return {hits, blows};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    while(cin>>N && N){
        vector<pair<string, pair<int,int>>> attempts(N);
        for(auto &p: attempts) cin>>p.first>>p.second.first>>p.second.second;
        vector<string> candidates;
        for(int num=0; num<=9999; num++){
            string s = to_string(num);
            while(s.size()<4) s = "0"+s;
            bool distinct=true;
            for(int i=0;i<4&&distinct;i++) for(int j=i+1;j<4&&distinct;j++) if(s[i]==s[j]) {distinct=false;}
            if(!distinct) continue;
            bool ok=true;
            for(auto &[guess, fb]: attempts){
                auto [h, b] = get_hit_and_blow(s, guess);
                if(h != fb.first || b != fb.second) {ok=false; break;}
            }
            if(ok) candidates.push_back(s);
        }
        if(candidates.size()==1){
            cout<<candidates[0]<<"\n";
            continue;
        }
        string critical = "9999";
        for(int num=0; num<=9999; num++){
            string guess = to_string(num);
            while(guess.size()<4) guess = "0"+guess;
            bool distinct=true;
            for(int i=0;i<4&&distinct;i++) for(int j=i+1;j<4&&distinct;j++) if(guess[i]==guess[j]) {distinct=false;}
            if(!distinct) continue;
            unordered_map<long long, int> feedback_count;
            for(auto &secret: candidates){
                auto [h, b] = get_hit_and_blow(secret, guess);
                long long key = h * 10 + b;
                feedback_count[key]++;
            }
            bool is_critical=true;
            for(auto &[k, cnt]: feedback_count) if(cnt >1){is_critical=false; break;}
            if(is_critical && guess < critical) critical = guess;
        }
        bool found=false;
        for(int num=0; num<=9999 && !found; num++) if(to_string(num).size()==4){
            string g = to_string(num);
            while(g.size()<4) g = "0"+g;
            if(g == critical){found=true; break;}
        }
        bool has_critical=false;
        for(int num=0; num<=9999; num++){
            string guess = to_string(num);
            while(guess.size()<4) guess = "0"+guess;
            bool distinct=true;
            for(int i=0;i<4&&distinct;i++) for(int j=i+1;j<4&&distinct;j++) if(guess[i]==guess[j]) {distinct=false;}
            if(!distinct) continue;
            unordered_map<long long, int> feedback_count;
            for(auto &secret: candidates){
                auto [h, b] = get_hit_and_blow(secret, guess);
                long long key = h * 10 + b;
                feedback_count[key]++;
            }
            bool is_critical=true;
            for(auto &[k, cnt]: feedback_count) if(cnt >1){is_critical=false; break;}
            if(is_critical){
                has_critical=true;
                if(guess < critical){
                    critical = guess;
                }
            }
        }
        if(has_critical){
            string min_critical = "9999";
            for(int num=0; num<=9999; num++){
                string guess = to_string(num);
                while(guess.size()<4) guess = "0"+guess;
                bool distinct=true;
                for(int i=0;i<4&&distinct;i++) for(int j=i+1;j<4&&distinct;j++) if(guess[i]==guess[j]) {distinct=false;}
                if(!distinct) continue;
                unordered_map<long long, int> feedback_count;
                for(auto &secret: candidates){
                    auto [h, b] = get_hit_and_blow(secret, guess);
                    long long key = h * 10 + b;
                    feedback_count[key]++;
                }
                bool is_critical=true;
                for(auto &[k, cnt]: feedback_count) if(cnt >1){is_critical=false; break;}
                if(is_critical && guess < min_critical){
                    min_critical = guess;
                }
            }
            cout<<min_critical<<"\n";
        }
        else cout<<"????\n";
    }

    return 0;
}