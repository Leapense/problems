#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

string ROT13(const string& s) {
    string res = s;
    for (char& c : res) {
        if ('a' <= c && c <= 'z') {
            c = (c - 'a' + 13) % 26 + 'a';
        }
    }

    return res;
}

int main() {
    int n;
    cin >> n;

    unordered_set<string> words;
    for (int i = 0; i < n; ++i) {
        string w;
        cin >> w;
        words.insert(w);
    }

    int count = 0;
    for (const auto& w : words) {
        string w_rot13 = ROT13(w);
        if (words.find(w_rot13) != words.end()) {
            ++count;
        }
    }

    cout << count << "\n";

    return 0;
}