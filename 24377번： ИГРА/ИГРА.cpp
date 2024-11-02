#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);

    vector<int> boxes(4);

    for (int i = 0; i < 4; i++) {
        cin >> boxes[i];
    }

    vector<int> missingNumbers;

    for (int i = 1; i <= 4; i++) {
        if (find(boxes.begin(), boxes.end(), i) == boxes.end()) {
            missingNumbers.push_back(i);
        }
    }

    int emptyCount = count(boxes.begin(), boxes.end(), 0);

    if (emptyCount == 1) {
        for (int i = 0; i < 4; i++) {
            if (boxes[i] == 0) {
                cout << i + 1 << " " << missingNumbers[0] << endl;
                break;
            }
        }
    } else if (emptyCount == 2) {
        sort(missingNumbers.begin(), missingNumbers.end());
        cout << missingNumbers[0] << " " << missingNumbers[1] << endl;
    } else {
        cout << boxes[0] << " " << boxes[1] << endl;
    }

    return 0;
}