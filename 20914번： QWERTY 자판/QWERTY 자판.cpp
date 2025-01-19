#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<string> layout={"QWERTYUIOP","ASDFGHJKL","ZXCVBNM"};
    unordered_map<char,pair<int,int>> pos;
    for(int r=0;r<(int)layout.size();r++){
        for(int c=0;c<(int)layout[r].size();c++){
            pos[layout[r][c]]={r,c};
        }
    }
    vector<vector<int>> dist(26,vector<int>(26,0));
    for(int i=0;i<26;i++){
        char start=(char)('A'+i);
        vector<int> d(26,1e9);
        d[i]=0;
        queue<char>q;
        q.push(start);
        while(!q.empty()){
            char cur=q.front();q.pop();
            int idxCur=cur-'A';
            for(int dr=-1;dr<=1;dr++){
                for(int dc=-1;dc<=1;dc++){
                    if(dr==0 && dc==0) continue;
                    int rr=pos[cur].first+dr;
                    int cc=pos[cur].second+dc;
                    if(rr<0 || rr>2) continue;
                    if(rr==0 && (cc<0 || cc>9)) continue;
                    if(rr==1 && (cc<0 || cc>8)) continue;
                    if(rr==2 && (cc<0 || cc>6)) continue;
                    char nxt=layout[rr][cc];
                    int idxNxt=nxt-'A';
                    if(d[idxCur]+1<d[idxNxt]){
                        d[idxNxt]=d[idxCur]+1;
                        q.push(nxt);
                    }
                }
            }
        }
        for(int j=0;j<26;j++) dist[i][j]=d[j];
    }
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T;cin>>T;
    while(T--){
        string s;cin>>s;
        int ans=s.size();
        for(int i=1;i<(int)s.size();i++){
            ans+=dist[s[i-1]-'A'][s[i]-'A']*2;
        }
        cout<<ans<<"\n";
    }
    return 0;
}