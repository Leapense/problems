#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        long long r, t_paint;
        cin >> r >> t_paint;

        long long count = 0;
        long long paint_needed = 2 * r + 1;

        while (t_paint >= paint_needed) {
            t_paint -= paint_needed;
            count++;

            r += 2;
            paint_needed = 2 * r + 1;
        }

        cout << "Case #" << t << ": " << count << endl;
    }

    return 0;
}