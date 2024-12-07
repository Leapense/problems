#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;

    while (T--) {
        string cmd;
        cin >> cmd;

        int x = 0, y = 0;
        int dir = 0;
        int minX = 0, maxX = 0, minY = 0, maxY = 0;

        for (auto c : cmd) {
            if (c == 'F') {
                if (dir == 0) y++;
                else if (dir == 1) x++;
                else if (dir == 2) y--;
                else if (dir == 3) x--;
            } else if (c == 'B') {
                if (dir == 0) y--;
                else if (dir == 1) x--;
                else if (dir == 2) y++;
                else if (dir == 3) x++;
            } else if (c == 'L') {
                dir = (dir + 3) % 4;
            } else if (c == 'R') {
                dir = (dir + 1) % 4;
            }

            if (x < minX) minX = x;
            if (x > maxX) maxX = x;
            if (y < minY) minY = y;
            if (y > maxY) maxY = y;
        }

        int width = maxX - minX;
        int height = maxY - minY;
        cout << (width * height) << "\n";
    }

    return 0;
}