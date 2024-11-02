#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

// Function to find the candidate to eliminate
int findCandidateToEliminate(vector<int>& votes, vector<bool>& eliminated, int N) {
    int minVotes = INT_MAX;
    int candidateToEliminate = -1;

    // Find the candidate with the least votes who is not eliminated
    for (int i = 0; i < N; ++i) {
        if (!eliminated[i] && votes[i] < minVotes) {
            minVotes = votes[i];
            candidateToEliminate = i;
        } else if (!eliminated[i] && votes[i] == minVotes) {
            // In case of tie, eliminate the highest-numbered candidate
            candidateToEliminate = max(candidateToEliminate, i);
        }
    }

    return candidateToEliminate;
}

int main() {
    int G, N;

    // Read until G and N are 0
    while (cin >> G >> N, G != 0 || N != 0) {
        vector<vector<int>> groups(G);
        vector<int> groupSizes(G);

        // Read group information
        for (int i = 0; i < G; ++i) {
            int Mi;
            cin >> Mi;
            groupSizes[i] = Mi;

            groups[i].resize(N);
            for (int j = 0; j < N; ++j) {
                cin >> groups[i][j];
                groups[i][j]--; // Zero-indexed for easier access
            }
        }

        vector<bool> eliminated(N, false); // Tracks eliminated candidates

        while (true) {
            vector<int> votes(N, 0); // Current vote counts for each candidate

            // Count first-choice votes for each candidate
            for (int i = 0; i < G; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (!eliminated[groups[i][j]]) {
                        votes[groups[i][j]] += groupSizes[i];
                        break;
                    }
                }
            }

            // Check how many candidates are not eliminated
            int remainingCandidates = 0;
            int lastCandidate = -1;

            for (int i = 0; i < N; ++i) {
                if (!eliminated[i]) {
                    remainingCandidates++;
                    lastCandidate = i;
                }
            }

            // If only one candidate remains, they are the winner
            if (remainingCandidates == 1) {
                cout << lastCandidate + 1 << endl; // Convert to one-indexed output
                break;
            }

            // Find the candidate to eliminate
            int toEliminate = findCandidateToEliminate(votes, eliminated, N);
            eliminated[toEliminate] = true;
        }
    }

    return 0;
}