#include <bits/stdc++.h>
using namespace std;

// Structure to hold puzzle piece information
struct Piece {
    char color;
    int rows;
    int cols;
    int u;
    int d;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<Piece> pieces(n);
    for(int i=0; i<n; i++){
        cin >> pieces[i].color >> pieces[i].rows >> pieces[i].cols >> pieces[i].u >> pieces[i].d;
    }
    
    // Read the placement sequence
    vector<int> order(n);
    for(int i=0; i<n; i++) cin >> order[i];
    
    // Initialize a large grid with '.' and an offset to handle negative placements
    const int OFFSET = 200;
    const int GRID_SIZE = 400;
    vector<vector<char>> grid(GRID_SIZE, vector<char>(GRID_SIZE, '.'));
    
    // Vector to store the top-left positions of each piece
    // positions[i] corresponds to the piece with index i (0-based)
    vector<pair<int, int>> positions(n, {OFFSET, OFFSET});
    
    // Place the first piece
    int first_idx = order[0] -1;
    Piece first_piece = pieces[first_idx];
    int start_row = OFFSET;
    int start_col = OFFSET;
    positions[first_idx] = {start_row, start_col};
    
    // Place the first piece on the grid
    for(int r=0; r<first_piece.rows; r++){
        for(int c=0; c<first_piece.cols; c++){
            grid[start_row + r][start_col + c] = first_piece.color;
        }
    }
    
    // Initialize min and max boundaries
    int min_row = start_row;
    int max_row = start_row + first_piece.rows -1;
    int min_col = start_col;
    int max_col = start_col + first_piece.cols -1;
    
    // Iterate through the placement sequence
    for(int i=1; i<n; i++){
        int prev_idx = order[i-1] -1;
        int current_idx = order[i] -1;
        Piece prev_piece = pieces[prev_idx];
        Piece current_piece = pieces[current_idx];
        
        // Get previous piece's position
        int prev_start_row = positions[prev_idx].first;
        int prev_start_col = positions[prev_idx].second;
        
        // Get connection details from the previous piece
        int u = prev_piece.u;
        int d = prev_piece.d;
        
        // Calculate the top-left position for the current piece
        int new_start_row, new_start_col;
        if(u == 0){
            // Connect above at column d
            // Ensure d is within 1 to s_prev
            // d is 1-based
            new_start_row = prev_start_row - current_piece.rows;
            new_start_col = prev_start_col + (d -1);
        }
        else{
            // Connect to the right at row d
            // Ensure d is within 1 to r_prev
            // d is 1-based
            new_start_col = prev_start_col + prev_piece.cols;
            new_start_row = prev_start_row + (d -1) - (current_piece.rows -1);
        }
        positions[current_idx] = {new_start_row, new_start_col};
        
        // Place the current piece on the grid
        for(int r=0; r<current_piece.rows; r++){
            for(int c=0; c<current_piece.cols; c++){
                int grid_r = new_start_row + r;
                int grid_c = new_start_col + c;
                // Update min and max boundaries
                min_row = min(min_row, grid_r);
                max_row = max(max_row, grid_r);
                min_col = min(min_col, grid_c);
                max_col = max(max_col, grid_c);
                // Place the color
                grid[grid_r][grid_c] = current_piece.color;
            }
        }
    }
    
    // Calculate the final height and width
    int height = max_row - min_row +1;
    int width = max_col - min_col +1;
    
    // Print the results
    cout << height << " " << width << "\n";
    for(int r = min_row; r <= max_row; r++){
        for(int c = min_col; c <= max_col; c++){
            cout << grid[r][c];
        }
        cout << "\n";
    }
}