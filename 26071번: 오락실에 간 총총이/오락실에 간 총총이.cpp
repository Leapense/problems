#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int min_r = n;
    int max_r = -1;
    int min_c = n;
    int max_c = -1;

    for (int r = 0; r < n; ++r) {
        string row;
        cin >> row;
        for (int c = 0; c < n; ++c) {
            if (row[c] == 'G') {
                min_r = min(min_r, r);
                max_r = max(max_r, r);
                min_c = min(min_c, c);
                max_c = max(max_c, c);
            }
        }
    }

    int vertical_moves = 0;
    if (min_r != max_r) {
        vertical_moves = min(max_r, n - 1 - min_r);
    }

    int horizontal_moves = 0;
    if (min_c != max_c) {
        horizontal_moves = min(max_c, n - 1 - min_c);
    }

    cout << vertical_moves + horizontal_moves << "\n";

    return 0;
}