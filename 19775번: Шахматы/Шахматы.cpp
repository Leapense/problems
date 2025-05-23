#include <bits/stdc++.h>
using namespace std;

static const int INF = 1000000000;
vector<int> adjL[1001];
int matchR[1001], matchL[1001], distL[1001];
bool used[1001][1001];
int n, R;
int a[1001];

bool bfs() {
    queue<int> q;
    for(int c = 0; c < n; c++) {
        if(matchL[c] < 0) {
            distL[c] = 0;
            q.push(c);
        } else {
            distL[c] = INF;
        }
    }
    int distNull = INF;
    while(!q.empty()) {
        int c = q.front(); 
        q.pop();
        if(distL[c] < distNull) {
            for(int r : adjL[c]) {
                int nc = matchR[r];
                if(nc < 0) distNull = distL[c] + 1;
                else if(distL[nc] == INF) {
                    distL[nc] = distL[c] + 1;
                    q.push(nc);
                }
            }
        }
    }
    return distNull < INF;
}

bool dfs(int c) {
    if(c < 0) return true;
    for(int r : adjL[c]) {
        int nc = matchR[r];
        if(nc < 0 || (nc >= 0 && distL[nc] == distL[c] + 1 && dfs(nc))) {
            matchL[c] = r;
            matchR[r] = c;
            return true;
        }
    }
    distL[c] = INF;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    R = a[0];
    for(int c=0; c<n; c++){
        for(int r=0; r<a[c]; r++){
            adjL[c].push_back(r);
        }
    }
    for(int i=0; i<R; i++) matchR[i] = -1;
    for(int i=0; i<n; i++) matchL[i] = -1;
    int matching = 0;
    while(bfs()){
        for(int c=0; c<n; c++){
            if(matchL[c]<0 && dfs(c)) matching++;
        }
    }
    vector<bool> usedL(n,false), usedR(R,false);
    queue<int>q;
    for(int c=0;c<n;c++){
        if(matchL[c]<0){
            q.push(c);
            usedL[c]=true;
        }
    }
    while(!q.empty()){
        int c=q.front(); q.pop();
        for(auto r: adjL[c]){
            if(!usedR[r] && matchR[r]!=-1){
                usedR[r]=true;
                int nc=matchR[r];
                if(!usedL[nc]){
                    usedL[nc]=true;
                    q.push(nc);
                }
            }
        }
    }
    vector<int> coverCols, coverRows;
    for(int c=0;c<n;c++){
        if(!usedL[c]) coverCols.push_back(c);
    }
    for(int r=0;r<R;r++){
        if(usedR[r]) coverRows.push_back(r);
    }
    cout<<coverCols.size()+coverRows.size()<<"\n";
    memset(used,false,sizeof(used));
    for(auto c: coverCols){
        int rr = 0;
        if(a[c]>0){
            rr = 0;
            while(rr<a[c] && used[c][rr]) rr++;
            if(rr>=a[c]) rr=a[c]-1;
            used[c][rr]=true;
            cout<<c+1<<" "<<rr+1<<"\n";
        }
    }
    for(auto r: coverRows){
        for(int c=0;c<n;c++){
            if(a[c]>r && !used[c][r]){
                used[c][r]=true;
                cout<<c+1<<" "<<r+1<<"\n";
                break;
            }
        }
    }
    return 0;
}