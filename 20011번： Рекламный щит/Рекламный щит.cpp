#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, n, m;
    cin >> k >> n >> m;

    vector<vector<string>> hieroglyphs(k, vector<string>(n));
    for (int h = 0; h < k; h++) {
        for (int r = 0; r < n; r++) {
            cin >> hieroglyphs[h][r];
        }
    }

    vector<string> patterns(n * m, "");
    for (int h = 0; h < k; h++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                patterns[i * m + j] += (hieroglyphs[h][i][j] == '*' ? '1' : '0');
            }
        }
    }
    
    unordered_set<string> unique_patterns(patterns.begin(), patterns.end());
    cout << unique_patterns.size() << endl;

    return 0;
}