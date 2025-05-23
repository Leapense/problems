#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string s;
    cin >> s;
    
    vector<char> stack;

    int current_depth = 0;
    int max_depth = 0;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push_back(c);
            current_depth++;
            if (current_depth > max_depth) max_depth = current_depth;
        }
        else {
            if (stack.empty()) {
                cout << "NIE";
                return 0;
            }

            char top = stack.back();
            if ((c == ')' && top == '(') || (c == ']' && top == '[') || (c == '}' && top == '{')) {
                stack.pop_back();
                current_depth--;
            } else {
                cout << "NIE";
                return 0;
            }
        }
    }

    if (stack.empty()) {
        cout << max_depth;
    } else {
        cout << "NIE";
    }

    return 0;
}