#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    string S;
    cin >> S;

    int direction = 0;
    int count = 0;
    int net_rotation = 0;
    set<int> directions_set;

    for (char c : S) {
        if(c == 'R') {
            direction = (direction + 1) % 4;
            net_rotation += 1;
        } else {
            direction = (direction + 3) % 4;
            net_rotation -= 1;
        }

        if (direction == 0) {
            if (net_rotation == 4) {
                if (directions_set.find(1) != directions_set.end() && directions_set.find(2) != directions_set.end() && directions_set.find(3) != directions_set.end()) {
                    count++;
                }
            }

            net_rotation = 0;
            directions_set.clear();
        } else {
            directions_set.insert(direction);
        }
    }

    cout << count << "\n";

    return 0;
}