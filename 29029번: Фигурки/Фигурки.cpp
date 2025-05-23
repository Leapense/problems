#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    string directions;
    cin >> directions;

    int countN = 0, countS = 0, countE = 0, countW = 0;

    for (char dir : directions) {
        if (dir == 'N') countN++;
        else if (dir == 'S') countS++;
        else if (dir == 'E') countE++;
        else if (dir == 'W') countW++;
    }

    int minChanges = min({n - countN, n - countS, n - countE, n - countW});

    cout << minChanges << endl;

    return 0;
}