#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int dr[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dc[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int dfs(int r, int c, vector<string> &grid, vector<vector<bool>> &visited, int rows, int cols) {
    visited[r][c] = true;
    int count = 1;

    for (int i = 0; i < 8; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == '#' && !visited[nr][nc]) {
            count += dfs(nr, nc, grid, visited, rows, cols);
        }
    }
    return count;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);

    while(1){
        int r, c;
        cin >> r >> c;
        if(r ==0 && c ==0) break;
        vector<string> grid(r);
        for(int i=0;i<r;i++) cin >> grid[i];
        // 방문 여부 체크
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        int cancer_cells =0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] == '#' && !visited[i][j]){
                    int size = dfs(i, j, grid, visited, r, c);
                    if(size ==1) cancer_cells++;
                }
            }
        }
        cout << cancer_cells << "\n";
    }

    return 0;
}