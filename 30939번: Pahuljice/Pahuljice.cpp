#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(auto &s : grid) cin >> s;
    
    // Directions: (dx, dy, expected_char)
    // Order: up, down, left, right, up-left, up-right, down-left, down-right
    vector<tuple<int, int, char>> directions = {
        {-1, 0, '|'}, // up
        {1, 0, '|'},  // down
        {0, -1, '-'}, // left
        {0, 1, '-'},  // right
        {-1, -1, '\\'}, // up-left
        {-1, 1, '/'},   // up-right
        {1, -1, '/'},   // down-left
        {1, 1, '\\'}    // down-right
    };
    
    int max_size = 0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == '+'){
                // For each direction, find the number of consecutive expected characters
                int current_min = INT32_MAX;
                for(auto &[dx, dy, ch] : directions){
                    int count = 0;
                    int x = i + dx;
                    int y = j + dy;
                    while(x >=0 && x < n && y >=0 && y < m && grid[x][y] == ch){
                        count++;
                        x += dx;
                        y += dy;
                    }
                    current_min = min(current_min, count);
                }
                if(current_min > 0){
                    max_size = max(max_size, current_min);
                }
            }
        }
    }
    
    cout << max_size;
}