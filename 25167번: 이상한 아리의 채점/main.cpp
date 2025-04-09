#include <bits/stdc++.h>
using namespace std;
int toMinutes(const string &s) {
    int h = stoi(s.substr(0, s.find(':')));
    int m = stoi(s.substr(s.find(':')+1));
    return h*60 + m;
}
struct Record {
    int firstWrong = -1;
    int solveTime = -1;
    bool solvedValid = false;
    bool solvedInvalid = false;
    bool attempted = false;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, P;
    cin >> N >> M >> P;
    vector<string> names(M);
    unordered_map<string,int> idx;
    for(int i=0;i<M;i++){
        cin >> names[i];
        idx[names[i]] = i;
    }
    vector<vector<Record>> rec(N+1, vector<Record>(M));
    for(int i=0;i<P;i++){
        int prob; string time, name, result;
        cin >> prob >> time >> name >> result;
        int t = toMinutes(time);
        int id = idx[name];
        Record &r = rec[prob][id];
        if(r.solvedValid || r.solvedInvalid) continue;
        r.attempted = true;
        if(result=="wrong"){
            if(r.firstWrong==-1) r.firstWrong = t;
        } else {
            if(r.firstWrong==-1){
                r.solvedInvalid = true;
            } else {
                r.solvedValid = true;
                r.solveTime = t;
            }
        }
    }
    vector<int> total(M, 0);
    for(int prob=1; prob<=N; prob++){
        vector<tuple<int,string,int>> valid;
        for(auto &p : names);
        for(int i=0;i<M;i++){
            if(rec[prob][i].solvedValid){
                int dur = rec[prob][i].solveTime - rec[prob][i].firstWrong;
                valid.push_back({dur, names[i], i});
            }
        }
        sort(valid.begin(), valid.end(), [](auto &a, auto &b){
            if(get<0>(a)==get<0>(b)) return get<1>(a) < get<1>(b);
            return get<0>(a) < get<0>(b);
        });
        vector<int> score(M, 0);
        // assign valid scores
        for(int pos=0; pos< (int) valid.size(); pos++){
            int idxP = get<2>(valid[pos]);
            score[idxP] = pos + 1;
        }
        // assign for non valid submissions
        for(int i=0;i<M;i++){
            if(rec[prob][i].solvedValid) continue;
            if(rec[prob][i].solvedInvalid) score[i] = M+1;
            else if(rec[prob][i].attempted) score[i] = M;
            else score[i] = M+1;
        }
        for(int i=0;i<M;i++){
            total[i] += score[i];
        }
    }
    vector<pair<int,string>> result;
    for(int i=0;i<M;i++){
        result.push_back({total[i], names[i]});
    }
    sort(result.begin(), result.end(), [](auto &a, auto &b){
        if(a.first==b.first) return a.second < b.second;
        return a.first < b.first;
    });
    for(auto &p : result) cout << p.second << "\n";
    return 0;
}

