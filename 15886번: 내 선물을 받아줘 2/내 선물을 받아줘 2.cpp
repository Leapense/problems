#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<int> next_pos(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        if (S[i-1] == 'E') {
            next_pos[i] = i + 1;
        } else {
            next_pos[i] = i - 1;
        }
    }

    vector<int> color(N + 1, 0);

    int cycle_count = 0;

    for (int i = 1; i <= N; ++i) {
        if (color[i] == 0) {
            int current = i;
            vector<int> path;
            while (true) {
                if (color[current] == 1) {
                    cycle_count++;
                    break;
                }
                if (color[current] == 2) {
                    break;
                }

                color[current] = 1;
                path.push_back(current);
                current = next_pos[current];
            }

            for (auto node : path) {
                color[node] = 2;
            }
        }
    }

    cout << cycle_count;

    return 0;
}