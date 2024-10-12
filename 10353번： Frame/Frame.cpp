#include <iostream>
#include <vector>
using namespace std;

int main() {
    int X, Y, N;
    cin >> X >> Y;  // Read dimensions of the frame
    cin >> N;       // Read the number of tile types

    // Calculate the number of cells in the frame (perimeter)
    int total_cells = 2 * (X + Y - 2);

    vector<int> tiles(N);
    for (int i = 0; i < N; ++i) {
        cin >> tiles[i];  // Read each tile length
    }

    for (int i = 0; i < N; ++i) {
        if (total_cells % tiles[i] == 0) {
            cout << "YES" << endl;  // It is possible to tile the frame
        } else {
            cout << "NO" << endl;   // It is not possible to tile the frame
        }
    }

    return 0;
}