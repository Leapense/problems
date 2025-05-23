#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M; // Number of players excluding Martynas, and rooms

    vector<int> eliminationOrder(N);
    for(int &player : eliminationOrder) cin >> player; // 1-based to 0-based index

    vector<vector<int>> roomAssignments(N, vector<int>(N));
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> roomAssignments[i][j]; // Room assignments
            roomAssignments[i][j]--; // Convert to 0-based index
        }
    }

    vector<bool> alive(N + 1, true); // +1 for Martynas, all initially alive
    vector<bool> knowsImpostor(N, false); // Initially, no one knows who the impostor is
    alive[N] = true; // Martynas is alive

    int turn;
    for(turn = 0; turn < N; ++turn) {
        int target = eliminationOrder[turn] - 1; // Who Martynas plans to eliminate this turn
        if(!alive[target]) continue; // If target already eliminated, skip

        // Move players to rooms
        vector<int> playersInRoom(M, 0);
        for(int player = 0; player < N; ++player) {
            if(alive[player]) {
                playersInRoom[roomAssignments[turn][player]]++;
                if(player != target && roomAssignments[turn][player] == roomAssignments[turn][target]) {
                    knowsImpostor[player] = true; // This player now knows Martynas is the impostor
                }
            }
        }

        // Check if Martynas can eliminate
        if(playersInRoom[roomAssignments[turn][target]] > 1) { // There's someone else in the room
            alive[target] = false;
        } else {
            // If Martynas can't eliminate anyone, he might be in danger but we continue
        }

        // Count votes
        int redVotes = count(knowsImpostor.begin(), knowsImpostor.end(), true);
        int yellowVotes = N - redVotes - (alive[N] ? 0 : 1); // Subtract one if Martynas is dead

        if(redVotes > yellowVotes) {
            break; // Martynas is caught
        }
    }

    if(turn == N) {
        cout << N << endl; // Martynas won
    } else {
        cout << turn + 1 << endl; // +1 because turns are 0-indexed
    }

    return 0;
}