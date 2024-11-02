#include <iostream>
using namespace std;

int main() {
    int dice[3][6];
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 6; ++j)
            cin >> dice[i][j];

    int result = -1;
    for (int i = 0; i < 3; ++i) {
        double minWinProb = 1.0;
        for (int j = 0; j < 3; ++j) {
            if (i == j) continue;
            int countJohnWins = 0, countHansWins = 0, countTies = 0;
            for (int a = 0; a < 6; ++a) {
                for (int b = 0; b < 6; ++b) {
                    if (dice[i][a] > dice[j][b])
                        countJohnWins++;
                    else if (dice[i][a] < dice[j][b])
                        countHansWins++;
                    else
                        countTies++;
                }
            }
            int totalOutcomes = 36 - countTies;
            double winProb;
            if (totalOutcomes == 0) {
                winProb = 0.0; // 승부가 나지 않으므로 승률은 0%
            } else {
                winProb = (double)countJohnWins / totalOutcomes;
            }
            minWinProb = min(minWinProb, winProb);
        }
        if (minWinProb >= 0.5) {
            result = i + 1;
            break;
        }
    }

    if (result != -1)
        cout << result << endl;
    else
        cout << "No dice" << endl;

    return 0;
}
