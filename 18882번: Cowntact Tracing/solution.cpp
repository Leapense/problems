#include <bits/stdc++.h>
using namespace std;
struct Event{int t,x,y;};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,T;cin>>n>>T;
    string finalState;cin>>finalState;
    vector<Event> ev(T);
    for(auto& e:ev)cin>>e.t>>e.x>>e.y;
    ranges::sort(ev,{},&Event::t);
    int INF_K=T+1;
    int patientCnt=0,minK=INF_K,maxK=-1;
    for(int p=1;p<=n;++p){
        vector<bool> validK(INF_K+1,false);
        for(int K=0;K<=INF_K;++K){
            vector<int> infected(n+1),used(n+1);
            infected[p]=1;
            for(auto [tt,a,b]:ev){
                bool aCan=infected[a]&&used[a]<K;
                bool bCan=infected[b]&&used[b]<K;
                if(aCan){infected[b]=1;++used[a];}
                if(bCan){infected[a]=1;++used[b];}
            }
            bool ok=true;
            for(int i=1;i<=n&&ok;++i)
                if(infected[i]!=(finalState[i-1]=='1'))ok=false;
            if(ok)validK[K]=true;
        }
        if(ranges::any_of(validK,[](bool v){return v;})){
            ++patientCnt;
            for(int K=0;K<=INF_K;++K)if(validK[K]){
                minK=min(minK,K);
                maxK=max(maxK,K);
            }
        }
    }
    cout<<patientCnt<<' '<<minK<<' ';
    if(maxK==T+1)cout<<"Infinity\n";
    else cout<<maxK<<'\n';
}