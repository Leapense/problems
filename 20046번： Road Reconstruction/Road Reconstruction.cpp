#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;

// Directions: up, down, left, right
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            cin >> grid[i][j];
        }
    }
    
    // Check if start or end is blocked
    if(grid[0][0] == -1 || grid[m-1][n-1] == -1){
        cout << "-1";
        return 0;
    }
    
    // Distance array
    vector<vector<int>> dist(m, vector<int>(n, INF));
    dist[0][0] = (grid[0][0] > 0) ? grid[0][0] : 0;
    
    // Priority queue: (cost, (x, y))
    // Min-heap
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, std::greater<pair<int, pair<int, int>>>> pq;
    pq.push({dist[0][0], {0, 0}});
    
    while(!pq.empty()){
        auto current = pq.top();
        pq.pop();
        int cost = current.first;
        int x = current.second.first;
        int y = current.second.second;
        
        if(x == m-1 && y == n-1){
            break;
        }
        
        if(cost > dist[x][y]) continue; // Already found a better path
        
        for(int dir=0; dir<4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if(nx >=0 && nx < m && ny >=0 && ny < n){
                if(grid[nx][ny] == -1) continue; // Cannot build road here
                
                int new_cost = cost;
                if(grid[nx][ny] > 0){
                    new_cost += grid[nx][ny];
                }
                
                if(new_cost < dist[nx][ny]){
                    dist[nx][ny] = new_cost;
                    pq.push({new_cost, {nx, ny}});
                }
            }
        }
    }
    
    if(dist[m-1][n-1] == INF){
        cout << "-1";
    }
    else{
        cout << dist[m-1][n-1];
    }
}