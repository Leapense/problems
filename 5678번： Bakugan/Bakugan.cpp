#include <iostream>
#include <vector>
using namespace std;

char determineWinner(const vector<int>& mark, const vector<int>& leti, int rounds) {
    int markPoints = 0, letiPoints = 0;
    int markConsecutive = 1, letiConsecutive = 1;
    int lastMark = -1, lastLeti = -1;
    bool markExtra = false, letiExtra = false;

    for (int i = 0; i < rounds; i++) {
        markPoints += mark[i];
        letiPoints += leti[i];

        // Check Mark's consecutive counts
        if (mark[i] == lastMark) {
            markConsecutive++;
        } else {
            markConsecutive = 1;
        }
        lastMark = mark[i];

        // Check Leti's consecutive counts
        if (leti[i] == lastLeti) {
            letiConsecutive++;
        } else {
            letiConsecutive = 1;
        }
        lastLeti = leti[i];

        // Check for 30 point bonus
        if (markConsecutive >= 3 && !markExtra) {
            if (letiConsecutive < 3 || leti[i] != mark[i]) {
                markPoints += 30;
                markExtra = true; // Mark has earned his extra points
            }
        }
        if (letiConsecutive >= 3 && !letiExtra) {
            if (markConsecutive < 3 || leti[i] != mark[i]) {
                letiPoints += 30;
                letiExtra = true; // Leti has earned her extra points
            }
        }
    }

    if (markPoints > letiPoints) {
        return 'M';
    } else if (letiPoints > markPoints) {
        return 'L';
    } else {
        return 'T';
    }
}

int main() {
    int R;
    while (cin >> R && R != 0) {
        vector<int> mark(R);
        vector<int> leti(R);

        for (int i = 0; i < R; i++) {
            cin >> mark[i];
        }
        for (int i = 0; i < R; i++) {
            cin >> leti[i];
        }

        cout << determineWinner(mark, leti, R) << endl;
    }
    return 0;
}
