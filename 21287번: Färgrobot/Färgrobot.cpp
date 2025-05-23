#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    string squares;
    cin >> N >> squares;

    vector<char> commands(N);
    int current_pos = 0;
    int len = squares.length();

    for (int i = 0; i < N; ++i) {
        // Find the farthest move for each command
        int max_pos = current_pos;
        char best_command = 'R';
        for (char color : {'R', 'G', 'B'}) {
            int pos = current_pos;
            // Move to the next position of 'color'
            while (pos < len && squares[pos] != color) {
                pos++;
            }
            if (pos < len && pos > max_pos) {
                max_pos = pos;
                best_command = color;
            }
        }
        // Apply the best command found
        commands[i] = best_command;
        current_pos = max_pos + 1; // Move past the found color
        if (current_pos >= len) break; // Out of bounds check
    }

    // Output the command sequence
    for (char cmd : commands) {
        cout << cmd;
    }
    cout << endl;

    return 0;
}