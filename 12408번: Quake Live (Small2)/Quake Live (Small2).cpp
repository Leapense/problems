#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int calculateMinDifference(const vector<int>& skills, int n) {
    int minDiff = INT_MAX;
    vector<bool> v(n, false);
    fill(v.begin() + n/2, v.end(), true);

    do {
        int sumA = 0, sumB = 0;
        for (int i = 0; i < n; ++i) {
            if (v[i]) {
                sumA += skills[i];
            } else {
                sumB += skills[i];
            }
        }
        int diff = abs(sumA - sumB);
        if (diff < minDiff) {
            minDiff = diff;
        }
    } while (next_permutation(v.begin(), v.end()));

    return minDiff;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        vector<int> skills(N);
        for (int i = 0; i < N; ++i) {
            cin >> skills[i];
        }

        int minDiff;
        if (N == 2) {
            minDiff = abs(skills[0] - skills[1]);
        } else {
            minDiff = calculateMinDifference(skills, N);
        }

        cout << "Case #" << t << ": " << minDiff << endl;
    }
    return 0;
}