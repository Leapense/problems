#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    string s, t;
    getline(cin, s);
    getline(cin, t);

    set<char> stickyKeys; // to store sticky keys
    int i = 0, j = 0;

    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) {
            i++;
            j++;
        } else {
            // If characters don't match, `t[j]` must be a duplicate character from a sticky key
            stickyKeys.insert(t[j]);
            j++;
        }
    }

    // Handle remaining duplicated characters in `t` if any
    while (j < t.size()) {
        stickyKeys.insert(t[j]);
        j++;
    }

    // Output the sticky keys
    for (char c : stickyKeys) {
        cout << c;
    }
    cout << endl;

    return 0;
}
