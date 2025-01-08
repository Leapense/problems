#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    unordered_map<string, vector<int>> color_map;

    string color;
    int density;

    for (int i = 0; i < N; ++i) {
        cin >> color >> density;
        color_map[color].push_back(density);
    }

    for (auto &entry : color_map) {
        sort(entry.second.begin(), entry.second.end());
    }

    int M;
    cin >> M;
    vector<string> layers(M);

    for (int i = 0; i < M; ++i) {
        cin >> layers[i];
    }

    int prev_density = -1;
    bool possible = true;

    for (int i = 0; i < M; ++i) {
        string current_color = layers[i];
        if (color_map.find(current_color) == color_map.end()) {
            possible = false;
            break;
        }

        vector<int> &densities = color_map[current_color];

        int idx = upper_bound(densities.begin(), densities.end(), prev_density) - densities.begin();
        if (idx == densities.size()) {
            possible = false;
            break;
        }

        prev_density = densities[idx];
    }

    if (possible) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}