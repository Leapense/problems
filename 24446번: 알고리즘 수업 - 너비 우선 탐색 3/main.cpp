#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, R;
    cin >> N >> M >> R;
    
    // 그래프 인접 리스트 생성 (정점 번호 1부터 시작)
    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    // 각 정점의 인접 리스트를 내림차순 정렬
    for (int i = 1; i <= N; i++){
        sort(graph[i].rbegin(), graph[i].rend());
    }
    
    // 깊이를 저장할 배열, 방문하지 않은 정점은 -1로 초기화
    vector<int> depth(N + 1, -1);
    
    // BFS 구현
    queue<int> q;
    depth[R] = 0;
    q.push(R);
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for (int nxt : graph[cur]){
            if (depth[nxt] == -1){
                depth[nxt] = depth[cur] + 1;
                q.push(nxt);
            }
        }
    }
    
    // 각 정점의 깊이 출력
    for (int i = 1; i <= N; i++){
        cout << depth[i] << "\n";
    }
    
    return 0;
}
