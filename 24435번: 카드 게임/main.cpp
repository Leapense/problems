#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
string bobStr, aliceStr;
int best;
int threshold;
vector<char> aliceCards;
vector<bool> used;

void backtrack(int current) {
    if (current < threshold) {
        best = max(best, current);
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = true;
            int newNum = current * 10 + (aliceCards[i] - '0');

            if (newNum < threshold) {
                backtrack(newNum);
            } else {
                backtrack(newNum);
            }
            used[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        cin >> n >> bobStr >> aliceStr;

        int bobLR = stoi(bobStr);
        string bobRev = bobStr;
        reverse(bobRev.begin(), bobRev.end());
        int bobRL = stoi(bobRev);
        threshold = min(bobLR, bobRL);

        aliceCards = vector<char>(aliceStr.begin(), aliceStr.end());
        used.assign(n, false);
        best = -1;

        backtrack(0);

        cout << best << "\n";
    }

    return 0;
}
