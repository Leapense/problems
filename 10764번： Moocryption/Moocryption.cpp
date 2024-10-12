#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<string> grid(N);
    for(auto &s : grid) cin >> s;
    
    // Directions: N, NE, E, SE, S, SW, W, NW
    vector<pair<int, int>> directions = {
        {-1, 0}, {-1, 1}, {0, 1}, {1,1},
        {1,0}, {1,-1}, {0,-1}, {-1,-1}
    };
    
    // Initialize maximum count
    int max_count = 0;
    
    // Iterate over all possible cM
    for(char cM = 'A'; cM <= 'Z'; cM++){
        if(cM == 'M') continue; // cM cannot be 'M'
        // Iterate over all possible cO
        for(char cO = 'A'; cO <= 'Z'; cO++){
            if(cO == 'O') continue; // cO cannot be 'O'
            if(cO == cM) continue; // cO must be different from cM
            // Now, for this pair (cM, cO), count MOOs
            int count = 0;
            for(int i=0;i<N;i++){
                for(int j=0;j<M;j++){
                    // Check if current cell is cM
                    if(grid[i][j] != cM) continue;
                    // Check all 8 directions
                    for(auto &[dx, dy] : directions){
                        int ni = i + dx;
                        int nj = j + dy;
                        // Check first 'O'
                        if(ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
                        if(grid[ni][nj] != cO) continue;
                        // Move to second 'O'
                        ni += dx;
                        nj += dy;
                        if(ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
                        if(grid[ni][nj] != cO) continue;
                        // Found a "MOO"
                        count++;
                    }
                }
            }
            // Update maximum count
            if(count > max_count){
                max_count = count;
            }
        }
    }
    
    cout << max_count;
}