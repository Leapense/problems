#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string k, s;
    cin >> n >> k >> s;

    bool adj[26][26] = {false};

    for (int i = 0; i < n; ++i) {
        int c1 = k[i] - 'a';
        int c2 = k[(i + 1) % n] - 'a';
        adj[c1][c2] = true;
    }

    bool possible = true;
    for (size_t i = 1; i < s.length(); ++i) {
        int c1 = s[i - 1] - 'a';
        int c2 = s[i] - 'a';
        if (!adj[c1][c2]) {
            possible = false;
            break;
        }
    }

    cout << (possible ? "YES" : "NO") << endl;
    return 0;
}
