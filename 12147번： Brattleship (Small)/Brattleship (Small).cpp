#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int R, C, W;
        cin >> R >> C >> W;

        int option1 = R * (C - W + 1);
        int option2 = R * W;
        int minimal_guesses = max(option1, option2);
        cout << "Case #" << t << ": " << minimal_guesses << endl;
    }

    return 0;
}