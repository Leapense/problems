#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int Y, X;
vector<string> grid;
vector<vector<bool>> visited;
int dx[4] = {0, 1, 0, -1}; // directions for adjacent cells
int dy[4] = {-1, 0, 1, 0};

// Function to check connectivity of a specific character and count connected components
int countConnectedComponents(char c) {
    visited.assign(Y, vector<bool>(X, false));
    int count = 0;
    for (int y = 0; y < Y; y++) {
        for (int x = 0; x < X; x++) {
            if (grid[y][x] == c && !visited[y][x]) {
                count++;
                queue<pair<int, int>> q;
                q.push({y, x});
                visited[y][x] = true;
                while (!q.empty()) {
                    auto [cy, cx] = q.front(); q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int ny = cy + dy[dir], nx = cx + dx[dir];
                        if (ny >= 0 && ny < Y && nx >= 0 && nx < X) {
                            if (!visited[ny][nx] && grid[ny][nx] == c) {
                                visited[ny][nx] = true;
                                q.push({ny, nx});
                            }
                        }
                    }
                }
            }
        }
    }
    return count;
}

// Function to check symmetry
bool isSymmetric() {
    for (int y = 0; y < Y; y++) {
        for (int x = 0; x < X / 2; x++) {
            int x_mirror = X - x - 1;
            if (grid[y][x] != grid[y][x_mirror]) {
                return false;
            }
        }
    }
    return true;
}

// Function to check adjacency between 'W's and 'Y's
bool checkAdjacency() {
    visited.assign(Y, vector<bool>(X, false));
    queue<pair<int, int>> q;
    // Start from 'W's
    for (int y = 0; y < Y; y++) {
        for (int x = 0; x < X; x++) {
            if (grid[y][x] == 'W') {
                q.push({y, x});
                visited[y][x] = true;
            }
        }
    }
    // Check if 'W's are adjacent to 'Y's
    while (!q.empty()) {
        auto [y, x] = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int ny = y + dy[dir], nx = x + dx[dir];
            if (ny >= 0 && ny < Y && nx >= 0 && nx < X) {
                if (grid[ny][nx] == 'Y') {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    cin >> Y >> X;
    grid.resize(Y);
    for (int y = 0; y < Y; y++) {
        cin >> grid[y];
    }

    // Check that the 'B's (blue cells) form one connected component
    int blue_components = countConnectedComponents('B');
    if (blue_components != 1) {
        cout << "NO" << endl;
        return 0;
    }

    // Initialize grid: replace 'X' with 'Y' (yellow cells)
    for (int y = 0; y < Y; y++) {
        for (int x = 0; x < X; x++) {
            if (grid[y][x] == 'X') {
                grid[y][x] = 'Y';
            }
        }
    }

    int mid = X / 2;
    for (int y = 1; y < Y - 1; y++) {
        for (int x = 1; x < X / 2; x++) {
            int x_mirror = X - x - 1;
            if (grid[y][x] == 'Y' && grid[y][x_mirror] == 'Y') {
                grid[y][x] = 'W';
                grid[y][x_mirror] = 'W';
            }
        }
    }

    // Ensure there is at least one 'Y' cell remaining
    bool hasYellow = false;
    for (int y = 0; y < Y; y++) {
        for (int x = 0; x < X; x++) {
            if (grid[y][x] == 'Y') {
                hasYellow = true;
                break;
            }
        }
        if (hasYellow) break;
    }
    if (!hasYellow) {
        cout << "NO" << endl;
        return 0;
    }

    // Check conditions
    if (!isSymmetric()) {
        cout << "NO" << endl;
        return 0;
    }

    int white_components = countConnectedComponents('W');
    if (white_components != 2) {
        cout << "NO" << endl;
        return 0;
    }

    int yellow_components = countConnectedComponents('Y');
    if (yellow_components != 1) {
        cout << "NO" << endl;
        return 0;
    }

    if (!checkAdjacency()) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    for (int y = 0; y < Y; y++) {
        cout << grid[y] << endl;
    }

    return 0;
}
