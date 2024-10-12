#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;

    size_t pos = s.find(':');
    int a = stoi(s.substr(0, pos));
    int b = stoi(s.substr(pos + 1));

    int comebacks = 0;

    if (a == b) {
        if (a > 0) {
            comebacks = a - 1;
        } else {
            comebacks = 0;
        }
    } else {
        comebacks = min(a, b);
    }

    cout << comebacks << "\n";

    return 0;
}