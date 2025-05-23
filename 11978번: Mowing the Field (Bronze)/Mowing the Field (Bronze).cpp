#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main()
{
    int N;
    cin >> N;

    map<pair<int, int>, int> visited;

    int x = 0, y = 0;
    int time = 0;
    int max_x = -1;

    visited[{x, y}] = time;

    for (int i = 0; i < N; ++i) {
        char dir;
        int steps;
        cin >> dir >> steps;

        for (int s = 1; s <= steps; ++s) {
            time++;
            if (dir == 'N') y++;
            else if (dir == 'S') y--;
            else if (dir == 'E') x++;
            else if (dir == 'W') x--;

            pair<int, int> pos = {x, y};

            if (visited.find(pos) != visited.end()) {
                int last_time = visited[pos];
                int diff = time - last_time;
                if (max_x == -1 || diff < max_x) {
                    max_x = diff;
                }
            }

            visited[pos] = time;
        }
    }

    cout << max_x << endl;

    return 0;
}