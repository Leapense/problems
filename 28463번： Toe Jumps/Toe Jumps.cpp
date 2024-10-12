#include <iostream>
#include <vector>
using namespace std;

// Function to check the rotated grid against patterns
string identifyToeJump(vector<string>& grid) {
    // Define patterns for Toe Loop (T), Flip (F), and Lutz (Lz)
    vector<string> toeLoop = {".O", "P."};  // Toe Loop
    vector<string> flip = {"I.", ".P"};     // Flip
    vector<string> lutz = {"O.", ".P"};     // Lutz

    // Compare the current grid to known patterns
    if (grid == toeLoop) {
        return "T";  // Toe Loop
    } else if (grid == flip) {
        return "F";  // Flip
    } else if (grid == lutz) {
        return "Lz";  // Lutz
    }
    
    return "?";  // Not a Toe Jump
}

// Function to rotate the grid based on the direction
vector<string> rotateGrid(char direction, vector<string>& grid) {
    vector<string> rotated(2, "..");
    
    // No rotation needed for 'S' (South)
    if (direction == 'S') {
        return grid;
    } 
    // Rotate 90 degrees clockwise for 'E' (East)
    else if (direction == 'E') {
        rotated[0][0] = grid[1][0];
        rotated[0][1] = grid[0][0];
        rotated[1][0] = grid[1][1];
        rotated[1][1] = grid[0][1];
    } 
    // Rotate 90 degrees counterclockwise for 'W' (West)
    else if (direction == 'W') {
        rotated[0][0] = grid[0][1];
        rotated[0][1] = grid[1][1];
        rotated[1][0] = grid[0][0];
        rotated[1][1] = grid[1][0];
    } 
    // Rotate 180 degrees for 'N' (North)
    else if (direction == 'N') {
        rotated[0][0] = grid[1][1];
        rotated[0][1] = grid[1][0];
        rotated[1][0] = grid[0][1];
        rotated[1][1] = grid[0][0];
    }
    
    return rotated;
}

int main() {
    char direction;
    vector<string> grid(2);

    // Input direction
    cin >> direction;
    // Input 2x2 grid
    for (int i = 0; i < 2; ++i) {
        cin >> grid[i];
    }

    // Rotate the grid based on the direction
    vector<string> rotatedGrid = rotateGrid(direction, grid);

    // Determine and output the jump type
    cout << identifyToeJump(rotatedGrid) << endl;

    return 0;
}