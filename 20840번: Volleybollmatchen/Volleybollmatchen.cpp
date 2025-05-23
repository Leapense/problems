#pragma GCC optimize ("O3,unroll-loops")

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string sequence;
    cin >> N >> sequence;

    int setsA = 0, setsB = 0;
    int pointsA = 0, pointsB = 0;
    int currentSet = 1;

    for (char ball : sequence) {
        if (ball == 'A') {
            pointsA++;
        } else {
            pointsB++;
        }

        int pointsNeeded = (currentSet < 3) ? 25 : 15;

        if ((pointsA >= pointsNeeded && pointsA - pointsB >= 2) || (pointsB >= pointsNeeded && pointsB - pointsA >= 2)) {
            if (pointsA > pointsB) {
                setsA++;
            } else {
                setsB++;
            }
            pointsA = 0;
            pointsB = 0;
            currentSet++;
        }

        if (setsA == 2 || setsB == 2) {
            break;
        }
    }

    cout << setsA << " " << setsB << endl;

    return 0;
}