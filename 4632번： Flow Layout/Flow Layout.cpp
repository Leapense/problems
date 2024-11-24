#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int m;
        cin >> m;

        if (m == 0) break;

        vector<pair<int, int>> rectangles;
        while (true) {
            int w, h;
            cin >> w >> h;
            if (w == -1 && h == -1) break;
            rectangles.emplace_back(w, h);
        }

        int total_width = 0;
        int total_height = 0;
        int current_row_width = 0;
        int current_row_height = 0;

        for (auto &[w, h] : rectangles) {
            if (current_row_width + w <= m) {
                current_row_width += w;
                current_row_height = max(current_row_height, h);
            } else {
                total_width = max(total_width, current_row_width);
                total_height += current_row_height;
                current_row_width = w;
                current_row_height = h;
            }
        }

        total_width = max(total_width, current_row_width);
        total_height += current_row_height;

        cout << total_width << " x " << total_height << "\n";
    }

    return 0;
}