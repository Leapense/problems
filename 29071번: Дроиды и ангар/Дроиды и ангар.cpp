#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string schema;
    cin >> schema;
    string commands;
    cin >> commands;
    const int MAX = 100002;
    bitset<100002> stone_blocks;
    stone_blocks.reset();
    stone_blocks.set(0);
    stone_blocks.set(n+1);
    for(int i=0;i<n;i++){
        if(schema[i] == '#'){
            stone_blocks.set(i+1);
        }
    }
    vector<int> delta(m+1, 0);
    for(int t=1;t<=m;t++){
        if(commands[t-1] == 'R') delta[t] = delta[t-1] +1;
        else delta[t] = delta[t-1] -1;
    }
    bitset<100002> destroyed;
    destroyed.reset();
    for(int t=1;t<=m;t++){
        int shift = delta[t];
        if(shift >=0){
            if(shift >= MAX) continue;
            bitset<100002> temp = stone_blocks >> shift;
            destroyed |= temp;
        }
        else{
            int s = -shift;
            if(s >= MAX) continue;
            bitset<100002> temp = stone_blocks << s;
            destroyed |= temp;
        }
    }
    vector<int> survivors;
    for(int i=0;i<n;i++){
        if(schema[i] == 'D'){
            int pos = i+1;
            if(!destroyed[pos]){
                survivors.push_back(pos);
            }
        }
    }
    cout << survivors.size() << "\n";
    for(int i=0;i<survivors.size();i++){
        if(i>0) cout << " ";
        cout << survivors[i];
    }
}
