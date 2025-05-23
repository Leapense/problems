#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to rotate direction vector 90 degrees clockwise
pair<int, int> rotateClockwise(const pair<int, int>& dir) {
    return {dir.second, -dir.first};
}

// Function to rotate direction vector 90 degrees counter-clockwise
pair<int, int> rotateCounterClockwise(const pair<int, int>& dir) {
    return {-dir.second, dir.first};
}

int main() {
    string sequence;
    while (getline(cin, sequence)) {
        // Initial position and direction (starting eastward)
        int x = 300, y = 420;
        pair<int, int> dir = {1, 0};  // East direction

        // Start the PostScript commands for this sequence
        cout << x << " " << y << " moveto\n";
        x += 10 * dir.first;  // Move 10 units in the initial direction
        y += 10 * dir.second;
        cout << x << " " << y << " lineto\n";

        // Process each character in the sequence
        for (char c : sequence) {
            if (c == 'A') {
                dir = rotateClockwise(dir);
            } else if (c == 'V') {
                dir = rotateCounterClockwise(dir);
            }

            x += 10 * dir.first;
            y += 10 * dir.second;
            cout << x << " " << y << " lineto\n";
        }

        // Finish the drawing commands for this sequence
        cout << "stroke\n";
        cout << "showpage\n";
    }

    return 0;
}