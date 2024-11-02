#include <bits/stdc++.h>
using namespace std;

bool matches(const vector<string>& stop, const vector<string>& screen, int h, int w) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (screen[i][j] == 'x' && stop[i][j] != 'x') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    
    vector<vector<string>> stops(n, vector<string>(h));
    
    // Read each stop's display representation
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < h; j++) {
            cin >> stops[i][j];
        }
    }
    
    // Read the glitchy screen
    vector<string> screen(h);
    for (int i = 0; i < h; i++) {
        cin >> screen[i];
    }
    
    // Check matches
    int match_count = 0;
    for (int i = 0; i < n; i++) {
        if (matches(stops[i], screen, h, w)) {
            match_count++;
        }
    }
    
    if (match_count == 1) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    
    return 0;
}