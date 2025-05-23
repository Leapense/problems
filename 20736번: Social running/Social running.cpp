#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Function to calculate the total solitary distance for a given starting point
int calculateSolitaryDistance(const vector<int>& distances, int start) {
    int N = distances.size();
    int totalSolitaryDistance = 0;
    int currentRunner = start;

    // Simulate the run
    for (int i = 0; i < N; ++i) {
        // The person living at 'currentRunner' runs from their house to the next house alone
        totalSolitaryDistance += distances[(currentRunner + N - 1) % N];
        currentRunner = (currentRunner + N - 1) % N;
    }

    return totalSolitaryDistance;
}

int main() {
    int N;
    cin >> N;

    vector<int> distances(N);
    for (int i = 0; i < N; ++i) {
        cin >> distances[i];
    }

    int minimalSolitaryDistance = INT_MAX;

    // Test each possible starting point
    for (int start = 0; start < N; ++start) {
        minimalSolitaryDistance = min(minimalSolitaryDistance, calculateSolitaryDistance(distances, start));
    }

    cout << minimalSolitaryDistance << endl;

    return 0;
}
