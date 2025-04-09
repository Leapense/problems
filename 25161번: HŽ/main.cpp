#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;cin >> N;
    int K;cin >> K;
    vector<pair<int,int>> closed(K);
    for(int i=0;i<K;i++){
        int a,b;cin >> a >> b;
        if(a>b) swap(a,b);
        closed[i]={a,b};
    }
    int M;cin >> M;
    vector<pair<int,int>> journeys(M);
    for(int i=0;i<M;i++){
        int x,y;cin >> x >> y;
        if(x>y) swap(x,y);
        journeys[i]={x,y};
    }
    int cnt=0;
    for(auto &j: journeys){
        bool flag=false;
        for(auto &c: closed){
            if(j.first < c.second && c.first < j.second){flag=true; break;}
        }
        if(flag) cnt++;
    }
    int cnt2=0;
    for(auto &c: closed){
        bool used=false;
        for(auto &j: journeys){
            if(j.first < c.second && c.first < j.second){used=true; break;}
        }
        if(used) cnt2++;
    }
    vector<bool> edgeClosed(N+1,false);
    for(auto &c: closed){
        for(int i=c.first; i < c.second; i++){
            edgeClosed[i]=true;
        }
    }
    int longest=0, cur=0;
    for(int i=1;i<=N-1;i++){
        if(!edgeClosed[i]){cur++;} else {longest = max(longest, cur+1); cur = 0;}
    }
    longest = max(longest, cur+1);
    cout << cnt << "\n" << cnt2 << "\n" << longest;
    return 0;
}

