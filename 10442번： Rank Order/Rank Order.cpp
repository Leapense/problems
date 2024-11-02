#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int case_num=1;
    while(true){
        int N;
        if(!(cin>>N)) break;
        vector<pair<int, int>> judge1(N);
        for(int i=0;i<N;i++) {cin>>judge1[i].first; judge1[i].second=i;}
        vector<pair<int, int>> judge2(N);
        for(int i=0;i<N;i++) {cin>>judge2[i].first; judge2[i].second=i;}
        sort(judge1.begin(), judge1.end(), [&](pair<int, int> a, pair<int, int> b)->bool{
            if(a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        });
        sort(judge2.begin(), judge2.end(), [&](pair<int, int> a, pair<int, int> b)->bool{
            if(a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        });
        int result=-1;
        for(int i=0;i<N;i++) {
            if(judge1[i].second != judge2[i].second){
                result = i+1;
                break;
            }
        }
        if(result==-1) cout<<"Case "<<case_num++<<": agree\n";
        else cout<<"Case "<<case_num++<<": "<<result<<"\n";
    }
}