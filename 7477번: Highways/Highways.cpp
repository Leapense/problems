#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N;
    cin >> N;

    if (N < 4) {
        cout << 0 << endl; // Impossible to build two highways with N < 4
        return 0;
    }

    vector<int> positions(N);
    vector<pair<int, pair<int, int>>> distances; // Distance, (start city index, end city index)

    // Read the positions of cities from the second city onwards
    positions[0] = 0; // The first city is at position 0
    for (int i = 1; i < N; ++i) {
        cin >> positions[i];
    }

    // Compute the distances between consecutive cities
    for (int i = 1; i < N; ++i) {
        distances.push_back({positions[i] - positions[i - 1], {i, i + 1}});
    }

    // Sort distances by the length of the highways
    sort(distances.begin(), distances.end());

    // Try finding the two non-overlapping pairs with the smallest distances
    int minTotalLength = INT_MAX;
    pair<int, int> highway1, highway2;

    // Loop through combinations to find the first two smallest non-overlapping distances
    for (int i = 0; i < distances.size(); ++i) {
        for (int j = i + 1; j < distances.size(); ++j) {
            int S1 = distances[i].second.first;
            int E1 = distances[i].second.second;
            int S2 = distances[j].second.first;
            int E2 = distances[j].second.second;

            // Ensure the two highways do not share any city
            if (E1 != S2 && E1 != E2 && S1 != S2 && S1 != E2) {
                int totalLength = distances[i].first + distances[j].first;

                // Check if the current total length is the smallest found
                if (totalLength < minTotalLength) {
                    minTotalLength = totalLength;
                    highway1 = {S1, E1};
                    highway2 = {S2, E2};
                }
            }
        }
    }

    // If a valid configuration was found
    if (minTotalLength != INT_MAX) {
        cout << minTotalLength << endl;
        cout << highway1.first << " " << highway1.second << " "
             << highway2.first << " " << highway2.second << endl;
    } else {
        cout << 0 << endl; // No valid way to build two highways
    }

    return 0;
}
