#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<string> grid(N);
    int sx, sy;
    for(int i=0;i<N;i++){
        cin >> grid[i];
        for(int j=0;j<M;j++) {
            if(grid[i][j] == 'S'){
                sx = i;
                sy = j;
            }
        }
    }
    string path = "";
    // Traverse rows from S's row downwards
    int current_row = sx;
    int current_col = sy;
    char direction = 'R';
    // Traverse downwards
    for(int r = current_row; r < N; r++){
        // Move in current direction
        if(direction == 'R'){
            while(current_col < M-1){
                // Check if next cell is not '#'
                if(grid[r][current_col+1] == '#') break;
                path += 'R';
                current_col +=1;
            }
        }
        else{
            while(current_col >0){
                if(grid[r][current_col-1] == '#') break;
                path += 'L';
                current_col -=1;
            }
        }
        // Move down if not last row
        if(r < N-1){
            // Check if cell below is not '#'
            if(grid[r+1][current_col] != '#'){
                path += 'D';
                current_row +=1;
            }
            else{
                // Try to move right or left to avoid obstacle
                bool moved = false;
                if(direction == 'R'){
                    if(current_col >0 && grid[r][current_col-1] != '#'){
                        path += 'L';
                        current_col -=1;
                        path += 'D';
                        current_row +=1;
                        direction = 'L';
                        moved = true;
                    }
                }
                else{
                    if(current_col < M-1 && grid[r][current_col+1] != '#'){
                        path += 'R';
                        current_col +=1;
                        path += 'D';
                        current_row +=1;
                        direction = 'R';
                        moved = true;
                    }
                }
                if(!moved){
                    // Cannot move down, end traversal
                    break;
                }
            }
            // Flip direction
            direction = (direction == 'R') ? 'L' : 'R';
        }
    }
    // Now traverse upwards from S's row -1 to 0
    // Reset to original position
    // To avoid immediate opposite step, make a side step first
    // Only if S's row is not the last row
    // Check if there are rows above
    if(sx >0){
        // From current position, move up if possible
        // To avoid 'D' followed by 'U', make a horizontal move first
        bool can_move = false;
        char horiz_move;
        if(direction == 'R' && current_col >0 && grid[current_row][current_col-1] != '#'){
            path += 'L';
            current_col -=1;
            horiz_move = 'L';
            can_move = true;
        }
        else if(direction == 'L' && current_col < M-1 && grid[current_row][current_col+1] != '#'){
            path += 'R';
            current_col +=1;
            horiz_move = 'R';
            can_move = true;
        }
        if(can_move){
            // Now move up
            if(grid[current_row-1][current_col] != '#'){
                path += 'U';
                current_row -=1;
                // Flip direction
                direction = (direction == 'R') ? 'L' : 'R';
            }
        }
        // Traverse upwards
        for(int r = current_row; r >=0; r--){
            // Move in current direction
            if(direction == 'R'){
                while(current_col < M-1){
                    if(grid[r][current_col+1] == '#') break;
                    path += 'R';
                    current_col +=1;
                }
            }
            else{
                while(current_col >0){
                    if(grid[r][current_col-1] == '#') break;
                    path += 'L';
                    current_col -=1;
                }
            }
            // Move up if not first row
            if(r >0){
                if(grid[r-1][current_col] != '#'){
                    path += 'U';
                    current_row -=1;
                }
                else{
                    // Try to move right or left to avoid obstacle
                    bool moved = false;
                    if(direction == 'R'){
                        if(current_col >0 && grid[r][current_col-1] != '#'){
                            path += 'L';
                            current_col -=1;
                            path += 'U';
                            current_row -=1;
                            direction = 'L';
                            moved = true;
                        }
                    }
                    else{
                        if(current_col < M-1 && grid[r][current_col+1] != '#'){
                            path += 'R';
                            current_col +=1;
                            path += 'U';
                            current_row -=1;
                            direction = 'R';
                            moved = true;
                        }
                    }
                    if(!moved){
                        // Cannot move up, end traversal
                        break;
                    }
                }
                // Flip direction
                direction = (direction == 'R') ? 'L' : 'R';
            }
        }
    }
    // Output the path
    cout << path;
}