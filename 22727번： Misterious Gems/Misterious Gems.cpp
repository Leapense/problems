#include<bits/stdc++.h>
using namespace std;

int main(){
    while(1){
        int N;
        cin>>N;
        if(N==0) break;
        set<pair<int,int>> gems;
        for(int i=0;i<N;i++){
            int x,y;
            cin>>x>>y;
            gems.emplace(x,y);
        }
        int M;
        cin>>M;
        vector<pair<char,int>> commands(M);
        for(auto &p:commands) cin>>p.first>>p.second;
        int x=10, y=10;
        for(auto &[d,l]:commands){
            int dx=0, dy=0;
            if(d=='N') dy=1;
            if(d=='S') dy=-1;
            if(d=='E') dx=1;
            if(d=='W') dx=-1;
            for(int i=0;i<l;i++){
                x += dx;
                y += dy;
                gems.erase({x,y});
            }
        }
        if(gems.empty()) cout<<"Yes\n";
        else cout<<"No\n";
    }
}