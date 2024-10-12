#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(true){
        int n, m;
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        // 인접 리스트 구축
        vector< vector<int> > adj(n+1, vector<int>());
        // 모든 간선 저장
        vector<pair<int, int>> edges;
        for(int i=0;i<m;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            edges.emplace_back(a, b);
        }
        // 각 도시의 영역 범위 계산
        // bitset<1001>을 사용하여 효율적으로 저장
        vector< bitset<1001> > reach(n+1, bitset<1001>());
        for(int i=1;i<=n;i++){
            reach[i].set(i);
            for(auto &neighbor: adj[i]){
                reach[i].set(neighbor);
            }
        }
        // 조건을 만족하는 쌍의 개수 계산
        int count = 0;
        for(auto &[u, v] : edges){
            if(reach[u] == reach[v]){
                count++;
            }
        }
        cout << count << "\n";
    }
}