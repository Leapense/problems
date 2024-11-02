#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int x3, y3, x4, y4;
    cin >> x3 >> y3 >> x4 >> y4;

    int overlap_x1 = max(x1, x3);
    int overlap_y1 = max(y1, y3);
    int overlap_x2 = min(x2, x4);
    int overlap_y2 = min(y2, y4);

    bool has_overlap = (overlap_x1 < overlap_x2) && (overlap_y1 < overlap_y2);

    long long lawn_area = (long long)(x2 - x1) * (y2 - y1);
    if (!has_overlap) {
        cout << lawn_area << "\n";
        return 0;
    }

    if (x3 <= x1 && x4 >= x2 && y3 <= y1 && y4 >= y2) {
        cout << "0\n";
        return 0;
    }

    long long tarp_area = lawn_area;

    if (x3 <= x1 && x4 >= x2) {
        bool bottom_exposed = y3 > y1;
        bool top_exposed = y4 < y2;

        if (bottom_exposed && top_exposed) {
            tarp_area = lawn_area;
        } else {
            if (bottom_exposed) {
                long long area = (long long)(x2 - x1) * (y3 - y1);
                tarp_area = min(tarp_area, area);
            }
            if (top_exposed) {
                long long area = (long long)(x2 - x1) * (y2 - y4);
                tarp_area = min(tarp_area, area);
            }
        }
    }

    if (y3 <= y1 && y4 >= y2) {
        bool left_exposed = x3 > x1;
        bool right_exposed = x4 < x2;

        if (left_exposed && right_exposed) {
            tarp_area = lawn_area;
        } else {
            if (left_exposed) {
                long long area = (long long)(x3 - x1) * (y2 - y1);
                tarp_area = min(tarp_area, area);
            }
            if (right_exposed) {
                long long area = (long long)(x2 - x4) * (y2 - y1);
                tarp_area = min(tarp_area, area);
            }
        }
    }

    cout << tarp_area << "\n";
    return 0;
}