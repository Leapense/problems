#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>

using namespace std;

// Adjacency list for each position
vector<int> adj[55]; // positions are from 1 to 54

// Function to initialize the adjacency list
void init_adj() {
    adj[1] = {2, 3};
    adj[2] = {1, 3, 5};
    adj[3] = {1, 2, 4, 5, 6};
    adj[4] = {3, 6, 7};
    adj[5] = {2, 3, 6, 8, 9};
    adj[6] = {3, 4, 5, 7, 9, 10};
    adj[7] = {4, 6, 10, 11};
    adj[8] = {5, 9, 12};
    adj[9] = {5, 6, 8, 10, 12, 13};
    adj[10] = {6, 7, 9, 11, 13, 14};
    adj[11] = {7, 10, 14, 15};
    adj[12] = {8, 9, 13, 16};
    adj[13] = {9, 10, 12, 14, 16, 17};
    adj[14] = {10, 11, 13, 15, 17, 18};
    adj[15] = {11, 14, 18, 19};
    adj[16] = {12, 13, 17, 20};
    adj[17] = {13, 14, 16, 18, 20, 21};
    adj[18] = {14, 15, 17, 19, 21, 22};
    adj[19] = {15, 18, 22, 23};
    adj[20] = {16, 17, 21, 24};
    adj[21] = {17, 18, 20, 22, 24, 25};
    adj[22] = {18, 19, 21, 23, 25, 26};
    adj[23] = {19, 22, 26, 27};
    adj[24] = {20, 21, 25, 28};
    adj[25] = {21, 22, 24, 26, 28, 29};
    adj[26] = {22, 23, 25, 27, 29, 30};
    adj[27] = {23, 26, 30, 31};
    adj[28] = {24, 25, 29, 32};
    adj[29] = {25, 26, 28, 30, 32, 33};
    adj[30] = {26, 27, 29, 31, 33, 34};
    adj[31] = {27, 30, 34, 35};
    adj[32] = {28, 29, 33, 36};
    adj[33] = {29, 30, 32, 34, 36, 37};
    adj[34] = {30, 31, 33, 35, 37, 38};
    adj[35] = {31, 34, 38, 39};
    adj[36] = {32, 33, 37, 40};
    adj[37] = {33, 34, 36, 38, 40, 41};
    adj[38] = {34, 35, 37, 39, 41, 42};
    adj[39] = {35, 38, 42, 43};
    adj[40] = {36, 37, 41, 44};
    adj[41] = {37, 38, 40, 42, 44, 45};
    adj[42] = {38, 39, 41, 43, 45, 46};
    adj[43] = {39, 42, 46, 47};
    adj[44] = {40, 41, 45, 48};
    adj[45] = {41, 42, 44, 46, 48, 49};
    adj[46] = {42, 43, 45, 47, 49, 50};
    adj[47] = {43, 46, 50, 51};
    adj[48] = {44, 45, 49, 52};
    adj[49] = {45, 46, 48, 50, 52, 53};
    adj[50] = {46, 47, 49, 51, 53, 54};
    adj[51] = {47, 50, 54};
    adj[52] = {48, 49, 53};
    adj[53] = {49, 50, 52, 54};
    adj[54] = {50, 51, 53};
}

// Function to check if a pyramid at position 'pos' is trapped
bool is_trapped(int pos, int board[]) {
    for (int neighbor : adj[pos]) {
        if (board[neighbor] == 0) {
            return false; // There is at least one empty adjacent position
        }
    }
    return true; // All adjacent positions are occupied
}

int main() {
    init_adj();
    string line;
    int test_case = 1;
    while (getline(cin, line)) {
        if (line == "0")
            break;
        istringstream iss(line);
        vector<int> positions;
        int num;
        while (iss >> num) {
            positions.push_back(num);
        }
        if (positions.size() != 12) continue; // Skip invalid lines
        int board[55]; // positions from 1 to 54
        memset(board, 0, sizeof(board));

        // Positions of player1 and player2
        vector<int> player1(positions.begin(), positions.begin() + 6);
        vector<int> player2(positions.begin() + 6, positions.begin() + 12);

        // Set up the board
        for (int pos : player1) {
            board[pos] = 1;
        }
        for (int pos : player2) {
            board[pos] = 2;
        }

        bool trapped = false;
        // For each of player1's pyramids
        for (int i = 0; i < 6 && !trapped; ++i) {
            int current_pos = player1[i];
            // For each adjacent empty position
            for (int neighbor : adj[current_pos]) {
                if (board[neighbor] == 0) {
                    // Simulate the move
                    board[current_pos] = 0;
                    board[neighbor] = 1;
                    // Check if any of player2's pyramids are trapped
                    for (int opp_pos : player2) {
                        if (is_trapped(opp_pos, board)) {
                            trapped = true;
                            break;
                        }
                    }
                    // Undo the move
                    board[neighbor] = 0;
                    board[current_pos] = 1;
                    if (trapped) break;
                }
            }
        }

        cout << test_case << ". ";
        if (trapped) {
            cout << "TRAPPED" << endl;
        } else {
            cout << "FREE" << endl;
        }
        test_case++;
    }
    return 0;
}
