#include <bits/stdc++.h>
using namespace std;

string escape(const string& s) {
    string res;
    for (char c : s) {
        if (c == '1') res += "11";
        else res += c;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string line;

    while(getline(cin, line)) {
        string encoded = "";
        string buffer = "";
        int pos = 0;
        int n = line.length();

        while (pos < n) {
            char current_char = line[pos];
            int run_length = 1;

            while (pos + run_length < n && line[pos + run_length] == current_char && run_length < 9) {
                run_length++;
            }

            if (run_length >= 2) {
                if (!buffer.empty()) {
                    encoded += '1' + escape(buffer) + '1';
                    buffer.clear();
                }

                encoded += to_string(run_length) + string(1, current_char);
                pos += run_length;
            } else {
                buffer += string(1, current_char);
                pos += 1;
            }
        }

        if (!buffer.empty()) {
            encoded += '1' + escape(buffer) + '1';
        }

        cout << encoded << "\n";
    }

    return 0;
}